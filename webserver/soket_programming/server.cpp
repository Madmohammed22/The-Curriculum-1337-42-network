#include "server.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define CHUNK_SIZE 1024
#define MAX_EVENTS 10

Server::Server()
{
    // std::cout << "[Server] Constructor is called" << std::endl;
}

Server::Server(const Server &Init)
{
    (void)Init;
}

Server &Server::operator=(const Server &Init)
{
    if (this == &Init)
        // Copy data members from Init to this
        // Example: this->dataMember = Init.dataMember;
        // Add actual data members here
        return *this;
    return *this;
}

Server::~Server()
{
    std::cout << "[Server] Destructor is called" << std::endl;
}

std::string Server::getContentType(const std::string &path)
{
    std::map<std::string, std::string> extensionToType;
    extensionToType.insert(std::make_pair(std::string(".html"), std::string("text/html")));
    extensionToType.insert(std::make_pair(std::string(".css"), std::string("text/css")));
    extensionToType.insert(std::make_pair(std::string(".js"), std::string("application/javascript")));
    extensionToType.insert(std::make_pair(std::string(".json"), std::string("application/json")));
    extensionToType.insert(std::make_pair(std::string(".xml"), std::string("application/xml")));
    extensionToType.insert(std::make_pair(std::string(".mp4"), std::string("video/mp4")));
    extensionToType.insert(std::make_pair(std::string(".mp3"), std::string("audio/mpeg")));
    extensionToType.insert(std::make_pair(std::string(".wav"), std::string("audio/wav")));
    extensionToType.insert(std::make_pair(std::string(".ogg"), std::string("audio/ogg")));
    extensionToType.insert(std::make_pair(std::string(".png"), std::string("image/png")));
    extensionToType.insert(std::make_pair(std::string(".jpg"), std::string("image/jpeg")));
    extensionToType.insert(std::make_pair(std::string(".jpeg"), std::string("image/jpeg")));
    extensionToType.insert(std::make_pair(std::string(".gif"), std::string("image/gif")));
    extensionToType.insert(std::make_pair(std::string(".svg"), std::string("image/svg+xml")));
    extensionToType.insert(std::make_pair(std::string(".ico"), std::string("image/x-icon")));

    size_t dotPos = path.rfind('.');
    if (dotPos != std::string::npos)
    {
        std::string extension = path.substr(dotPos);
        std::map<std::string, std::string>::const_iterator it = extensionToType.find(extension);
        if (it != extensionToType.end())
        {
            return it->second;
        }
    }
    return "application/octet-stream";
}

// std::string readFile(const std::string &path)
// {
//     // std::cout << "[" << path << "]\n";
//     std::stringstream content;
//     if (path.empty())
//         return "";

//     std::ifstream infile(path.c_str(), std::ios::binary);
//     if (!infile.is_open())
//         return "";

//     char buffer[CHUNK_SIZE];
//     while (infile.read(buffer, CHUNK_SIZE))
//     {
//         content.write(buffer, CHUNK_SIZE);
//     }

//     size_t remaining = infile.gcount();
//     if (remaining > 0)
//     {
//         content.write(buffer, remaining);
//     }

//     std::string r = content.str();
//     // std::cout << "---->\n"<< r << "<\n -----" <<  std::endl;
//     return r;
// }

std::string readFile(const std::string &path, size_t &pos, size_t chunkSize)
{
    std::ifstream infile(path.c_str(), std::ios::binary);
    if (!infile.is_open())
        return "";

    infile.seekg(pos);
    char buffer[chunkSize];
    std::memset(buffer, 0, chunkSize);
    infile.read(buffer, chunkSize);
    size_t bytesRead = infile.gcount();
    pos += bytesRead;

    return std::string(buffer, bytesRead);
}

std::string parseRequest(std::string request)
{
    if (request.empty())
        return "";
    std::cout << "Received request: " << request << std::endl;
    std::string filePath = "/index.html";
    size_t startPos = request.find("GET /");
    if (startPos != std::string::npos)
    {
        startPos += 5;
        size_t endPos = request.find(" HTTP/", startPos);
        if (endPos != std::string::npos)
        {
            filePath = request.substr(startPos, endPos - startPos);
        }
    }
    return filePath;
}

std::string parsRequest_will(std::string request, std::string &method)
{
    if (request.empty())
        return "";
    std::cout << "Received request: " << request << std::endl;

    // Extract the HTTP method
    size_t methodEnd = request.find(' ');
    if (methodEnd != std::string::npos)
    {
        method = request.substr(0, methodEnd);
    }
    else
    {
        method = "UNKNOWN";
    }

    std::string filePath = "/index.html";
    size_t startPos = request.find("GET /");
    if (startPos != std::string::npos)
    {
        startPos += 5;
        size_t endPos = request.find(" HTTP/", startPos);
        if (endPos != std::string::npos)
        {
            std::string requestedPath = request.substr(startPos, endPos - startPos);
            if (!requestedPath.empty() && requestedPath != "/")
            {
                filePath = requestedPath;
            }
        }
    }
    return filePath;
}

std::string Server::parsRequest(std::string request)
{
    if (request.empty())
        return "";
    std::cout << "Received request: " << request << std::endl;
    std::string filePath = "/index.html";
    size_t startPos = request.find("GET /");
    if (startPos != std::string::npos)
    {
        startPos += 5;
        size_t endPos = request.find(" HTTP/", startPos);
        if (endPos != std::string::npos)
        {
            std::string requestedPath = request.substr(startPos, endPos - startPos);
            if (!requestedPath.empty() && requestedPath != "/")
            {
                filePath = requestedPath;
            }
        }
    }
    return filePath;
}

std::string Server::creatHttpResponse(std::string contentType, std::string content)
{
    (void)content;
    std::string httpResponse = "HTTP/1.1 200 OK\r\n"
                               "Content-Type: " +
                               contentType + "\r\n"
                                             "Transfer-Encoding: chunked\r\n"
                                             "\r\n";
    return httpResponse;
}

void setnonblocking(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1)
    {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
    {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
}

bool CanBeOpen(std::string &filePath)
{
    std::string new_path;
    new_path = "/var/www/Resources/" + filePath;
    std::ifstream file(new_path.c_str());
    if (!file.is_open())
    {
        std::cerr << "Failed to open file:: " << new_path << std::endl;
        return false;
    }
    filePath = new_path;
    return true;
}

int do_use_fd(int fd, Server *server, std::string request)
{
    std::string filePath = server->parsRequest(request);
    std::string content;
    size_t pos = 0;

    // if (CanBeOpen(filePath) == true)
    // {
    //     pos = 0;
    //     content = readFile(filePath, pos, CHUNK_SIZE);
    //     // content = readFile(filePath);
    //     std::string contentType = server->getContentType(filePath);
    //     std::string httpResponse = server->creatHttpResponse(contentType, content);
    //     send(fd, httpResponse.c_str(), httpResponse.length(), MSG_NOSIGNAL);

    //     while (pos < content.size())
    //     {
    //         size_t chunkSize = (CHUNK_SIZE < (content.size() - pos)) ? CHUNK_SIZE : (content.size() - pos);
    //         std::ostringstream chunkStream;
    //         chunkStream << std::hex << chunkSize << "\r\n";
    //         chunkStream.write(content.data() + pos, chunkSize);
    //         chunkStream << "\r\n";
    //         std::string chunk = chunkStream.str();
    //         send(fd, chunk.c_str(), chunk.size(), MSG_NOSIGNAL);
    //         pos += chunkSize;
    //     }
    //     std::string finalChunk = "0\r\n\r\n";
    //     send(fd, finalChunk.c_str(), finalChunk.size(), MSG_NOSIGNAL);
    // }
    if (CanBeOpen(filePath) == true)
    {
        std::ifstream file(filePath.c_str(), std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "Failed to open file: " << filePath << std::endl;
            return -1;
        }

        std::string contentType = server->getContentType(filePath);
        std::string httpResponse = server->creatHttpResponse(contentType, "");
        send(fd, httpResponse.c_str(), httpResponse.size(), MSG_NOSIGNAL);

        char buffer[CHUNK_SIZE];
        while (file)
        {
            file.read(buffer, CHUNK_SIZE);
            size_t bytesRead = file.gcount();
            if (bytesRead == 0)
                break;

            std::ostringstream chunkStream;
            chunkStream << std::hex << bytesRead << "\r\n";
            chunkStream.write(buffer, bytesRead);
            chunkStream << "\r\n";
            std::string chunk = chunkStream.str();

            ssize_t sent = send(fd, chunk.c_str(), chunk.size(), MSG_NOSIGNAL);
            if (sent == -1 && (errno == EAGAIN || errno == EWOULDBLOCK))
            {
                // Handle non-blocking send (needs further logic for partial sends)
                ssize_t totalSent = 0;
                while ((size_t)totalSent < chunk.size())
                {
                    ssize_t sent = send(fd, chunk.c_str() + totalSent, chunk.size() - totalSent, MSG_NOSIGNAL);
                    if (sent == -1)
                    {
                        if (errno == EAGAIN || errno == EWOULDBLOCK)
                        {
                            // If the socket is not ready for sending, break and try again later
                            break;
                        }
                        else
                        {
                            std::cerr << "Failed to send data" << std::endl;
                            return -1;
                        }
                    }
                    totalSent += sent;
                }
                break;
            }
            // Note: In a real scenario, handle partial sends and buffer remaining data
            if (sent == -1)
            {
                std::cerr << "Failed to send data" << std::endl;
                break;
            }
        }

        std::string finalChunk = "0\r\n\r\n";
        send(fd, finalChunk.c_str(), finalChunk.size(), MSG_NOSIGNAL);
    }
    else
    {
        std::string path1 = "/var/www/Errors/404/";
        std::string path2 = "errorPage.html";
        std::string new_path = path1 + path2;
        pos = 0;
        std::string content = readFile(new_path, pos, CHUNK_SIZE);
        // std::string content = readFile(new_path);
        std::string contentType = server->getContentType(new_path);
        std::string notFound = "HTTP/1.1 404 Not Found\r\n"
                               "Content-Type: " +
                               contentType + "\r\n"
                                             "Transfer-Encoding: chunked\r\n"
                                             "\r\n";
        send(fd, notFound.c_str(), notFound.length(), MSG_NOSIGNAL);

        size_t pos = 0;
        while (pos < content.size())
        {
            size_t chunkSize = (CHUNK_SIZE < (content.size() - pos)) ? CHUNK_SIZE : (content.size() - pos);
            std::ostringstream chunkStream;
            chunkStream << std::hex << chunkSize << "\r\n";
            chunkStream.write(content.data() + pos, chunkSize);
            chunkStream << "\r\n";
            std::string chunk = chunkStream.str();
            send(fd, chunk.c_str(), chunk.size(), MSG_NOSIGNAL);
            pos += chunkSize;
        }

        std::string finalChunk = "0\r\n\r\n";
        send(fd, finalChunk.c_str(), finalChunk.size(), MSG_NOSIGNAL);
    }
    return 0;
}

int establishingServer(Server *server)
{
    int serverSocket = 0;
    serverSocket = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, getprotobyname("tcp")->p_proto);
    if (serverSocket < 0)
        return delete server, std::cerr << "opening stream socket." << std::endl, EXIT_FAILURE;

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    int len = sizeof(serverAddress);
    int a = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEPORT, &a, sizeof(int)) < 0)
        return perror(NULL), delete server, EXIT_FAILURE;
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
        return perror("binding stream socket"), delete server, EXIT_FAILURE;

    if (getsockname(serverSocket, (struct sockaddr *)&serverAddress, (socklen_t *)&len) == -1)
        return perror("getting socket name."), delete server, EXIT_FAILURE;
    std::cout << "Socket port " << ntohs(serverAddress.sin_port) << std::endl;

    if (listen(serverSocket, 5) < 0)
        return perror("listen stream socket"), delete server, EXIT_FAILURE;
    return serverSocket;
}

int multiplexInputOutput_Post_method(Server *server, int listen_sock, struct epoll_event &ev, sockaddr_in &clientAddress, int epollfd, socklen_t &clientLen, std::map<int, std::string> &send_buffers)
{
    int conn_sock;
    // static char buffer[CHUNK_SIZE];

    struct epoll_event events[MAX_EVENTS];
    int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
    if (nfds == -1)
        return perror("epoll_wait"), EXIT_FAILURE;
    for (int i = 0; i < nfds; i++)
    {
        if (events[i].data.fd == listen_sock)
        {
            conn_sock = accept(listen_sock, (struct sockaddr *)&clientAddress, &clientLen);
            if (conn_sock == -1)
                return std::cerr << "accept" << std::endl, EXIT_FAILURE;
            setnonblocking(conn_sock);
            ev.events = EPOLLIN | EPOLLOUT;
            ev.data.fd = conn_sock;
            if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1)
            {
                return std::cerr << "epoll_ctl: conn_sock" << std::endl, EXIT_FAILURE;
            }
        }
        else if (events[i].events & EPOLLIN)
        {
            std::string &buffer = send_buffers[events[i].data.fd];
            char temp[CHUNK_SIZE];
            ssize_t result;
            while ((result = recv(events[i].data.fd, temp, sizeof(temp), 0)) > 0)
            {
                buffer.append(temp, result);
                if (buffer.find("\r\n\r\n") != std::string::npos)
                    break; // End of headers
            }
            if (result <= 0 && errno != EAGAIN)
            {
                close(events[i].data.fd);
                send_buffers.erase(events[i].data.fd);
            }
            else
            {
                // // Process the complete request here
                // // Modify epoll to monitor EPOLLOUT after response is generated
                // ev.events = EPOLLOUT | EPOLLET;
                // ev.data.fd = events[i].data.fd;
                // if (epoll_ctl(epollfd, EPOLL_CTL_MOD, events[i].data.fd, &ev) == -1)
                // {
                //     std::cerr << "epoll_ctl: mod" << std::endl;
                //     close(events[i].data.fd);
                //     send_buffers.erase(events[i].data.fd);
                // }
            }
        }
        else if (events[i].events & EPOLLOUT)
        {
            if (!send_buffers[events[i].data.fd].empty())
            {
                do_use_fd(events[i].data.fd, server, send_buffers[events[i].data.fd]);
                send_buffers[events[i].data.fd].clear();
            }
        }
    }

    return EXIT_SUCCESS;
}

int main()
{
    Server *server = new Server();

    sockaddr_in clientAddress;
    socklen_t clientLen = sizeof(clientAddress);
    int listen_sock, epollfd;
    listen_sock = establishingServer(server);
    std::cout << "Server is listening" << std::endl;

    epollfd = epoll_create1(0);
    if (epollfd < 0)
        return std::cerr << "Failed to create epoll file descriptor" << std::endl, EXIT_FAILURE;

    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = listen_sock;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1)
        return perror("epoll_ctl"), EXIT_FAILURE;
    std::map<int, std::string> send_buffers;
    while (true)
    {
        if (multiplexInputOutput_Post_method(server, listen_sock, ev, clientAddress, epollfd, clientLen, send_buffers) == 1)
            return EXIT_FAILURE;
    }

    close(listen_sock);
    delete server;
    return EXIT_SUCCESS;
}