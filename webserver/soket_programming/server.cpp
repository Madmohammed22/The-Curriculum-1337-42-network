#include "server.hpp"

Server::Server()
{
}

Server::Server(const Server &Init)
{
    (void)Init;
}

Server &Server::operator=(const Server &Init)
{
    if (this == &Init)
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

std::string readFile(const std::string &path)
{
    std::stringstream content;
    if (path.empty())
        return "";

    std::ifstream infile(path.c_str(), std::ios::binary);
    if (!infile.is_open())
        return "";

    char buffer[CHUNK_SIZE];
    while (infile.read(buffer, CHUNK_SIZE))
    {
        content.write(buffer, CHUNK_SIZE);
    }

    size_t remaining = infile.gcount();
    if (remaining > 0)
    {
        content.write(buffer, remaining);
    }

    std::string r = content.str();
    return r;
}

std::string Server::parsRequest(std::string request)
{
    if (request.empty())
        return "";
    std::cout << "Received request: " << request << std::endl;
    std::string filePath = "/index.html";
    // std::string filePath = "/upload.html";
    if (request.find("GET / ") == std::string::npos)
    {
        size_t startPos = request.find("GET /") + 5;
        size_t endPos = request.find(" HTTP/");
        filePath = request.substr(startPos, endPos - startPos);
    }
    return filePath;
}

std::string Server::parsRequest404(std::string request)
{
    if (request.empty())
        return "";
    std::cout << "Received request 404: " << request << std::endl;
    std::string filePath = "errorPage.html";
    return filePath;
}

std::string Server::creatHttpResponse(std::string contentType, std::string content)
{
    std::ostringstream oss;
    oss << content.length();
    std::string str = oss.str();

    std::string httpResponse = "HTTP/1.1 200 OK\r\n"
                               "Content-Type: " +
                               contentType + "\r\n"
                                             "Transfer-Encoding: chunked\r\n"
                                             "\r\n";
    return httpResponse;
}

std::string Server::creatHttpResponseForPage404(std::string contentType, std::ifstream &file, std::string &s_content)
{
    std::stringstream content_v1;
    content_v1 << file.rdbuf();
    file.close();
    std::string content = content_v1.str();
    std::ostringstream oss;
    oss << content.length();
    std::string str = oss.str();

    std::string httpResponse = "HTTP/1.1 404 Not Found\r\n"
                               "Content-Type: " +
                               contentType + "\r\n"
                                             "Transfer-Encoding: chunked\r\n"
                                             "\r\n";
    s_content = content;
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

int uploadFiles(std::string filePath)
{
    std::string new_path = filePath.substr(filePath.find("=") + 1, filePath.length());
    if (CanBeOpen(new_path))
    {
        std::ifstream file1(new_path.c_str(), std::ios::binary);
        if (!file1.is_open())
            return std::cerr << "Failed to open input file." << std::endl, -1;

        std::ofstream output("output.txt", std::ios::binary);
        if (!output.is_open())
        {
            std::cerr << "Failed to open output file." << std::endl;
            file1.close();
            return -1;
        }

        char buffer[CHUNK_SIZE];
        while (file1.read(buffer, CHUNK_SIZE))
        {
            std::cout << "buffer" << std::endl;
            output.write(buffer, CHUNK_SIZE);
        }

        size_t remaining = file1.gcount();
        if (remaining > 0)
        {
            output.write(buffer, remaining);
        }
        file1.close();
        output.close();
    }
    else
        return std::cerr << "Failed to open input file." << std::endl, -1;
    return 0;
}

int do_use_fd(int fd, Server *server)
{
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(fd, buffer, sizeof(buffer), 0);

    std::string request(buffer);
    std::string filePath = server->parsRequest(request);
    std::string content = "";
    if (filePath.find("=") != std::string::npos)
        return uploadFiles(filePath);

    if (CanBeOpen(filePath) == true)
    {
        content = readFile(filePath);
        std::string contentType = server->getContentType(filePath);
        std::string httpResponse = server->creatHttpResponse(contentType, content);
        send(fd, httpResponse.c_str(), httpResponse.length(), 0);

        // Send the content in chunks..
        size_t pos = 0;
        while (pos < content.size())
        {
            size_t chunkSize = (CHUNK_SIZE < (content.size() - pos)) ? CHUNK_SIZE : (content.size() - pos);
            std::ostringstream chunkStream;
            chunkStream << std::hex << chunkSize << "\r\n";
            chunkStream.write(content.data() + pos, chunkSize);
            chunkStream << "\r\n";
            std::string chunk = chunkStream.str();
            send(fd, chunk.c_str(), chunk.size(), 0);
            return 0;
            pos += chunkSize;
        }

        // Send the final chunk ....
        std::string finalChunk = "0\r\n\r\n";
        send(fd, finalChunk.c_str(), finalChunk.size(), 0);
    }
    else
    {
        std::string path1 = "/var/www/Errors/404/";
        std::string path2 = "errorPage.html";
        std::string new_path = path1 + path2;
        std::ifstream file(new_path.c_str());
        std::string content;
        if (!file.is_open())
            return perror(NULL), delete server, EXIT_FAILURE;
        std::string contentType = server->getContentType(new_path);
        std::string notFound = server->creatHttpResponseForPage404(contentType, file, content);
        send(fd, notFound.c_str(), notFound.length(), 0);

        size_t pos = 0;
        while (pos < content.size())
        {
            size_t chunkSize = (CHUNK_SIZE < (content.size() - pos)) ? CHUNK_SIZE : (content.size() - pos);
            std::ostringstream chunkStream;
            chunkStream << std::hex << chunkSize << "\r\n";
            chunkStream.write(content.data() + pos, chunkSize);
            chunkStream << "\r\n";
            std::string chunk = chunkStream.str();
            send(fd, chunk.c_str(), chunk.size(), 0);
            pos += chunkSize;
        }

        // Send the final chunk
        std::string finalChunk = "0\r\n\r\n";
        send(fd, finalChunk.c_str(), finalChunk.size(), 0);
        file.close();
    }

    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        (void)argv;
        std::cout << "correct input : ./webserv [configuration file]" << std::endl;
        return EXIT_FAILURE;
    }

    Server *server = new Server();
    int serverSocket = 0;
    serverSocket = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, getprotobyname("tcp")->p_proto);
    if (serverSocket < 0)
        return std::cerr << "opening stream socket." << std::endl, EXIT_FAILURE;

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

    sockaddr_in clientAddress;
    socklen_t clientLen = sizeof(clientAddress);

    std::cout << "Server is listening" << std::endl;

    struct epoll_event ev, events[MAX_EVENTS];
    int listen_sock, conn_sock, nfds, epollfd;
    listen_sock = serverSocket;
    epollfd = epoll_create1(0);
    if (epollfd < 0)
        return std::cerr << "Failed to create epoll file descriptor" << std::endl, EXIT_FAILURE;

    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1)
        return std::cerr << "epoll_ctl: listen_sock" << std::endl, EXIT_FAILURE;

    std::string httpResponse = "HTTP/1.1 200 OK\r\nDate: Mon, 20 Jan 2025 12:00:00 GMT\r\nServer: Apache/2.4.41 (Ubuntu)\r\nContent-Type: text/html\r\nContent-Length: 1234\r\n\r\n<html>\r\n<head><title>Example Page</title></head>\r\n<body>\r\n<h1>Welcome to the Example Page</h1>\r\n</body>\r\n</html>";

    while (true)
    {

        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1)
            return std::cerr << "epoll_wait" << std::endl, EXIT_FAILURE;
        int n = 0;
        int d = 0;
        for (n = 0; n < nfds; n++)
        {
            if (events[n].data.fd == listen_sock)
            {
                std::cout << "connection ...\n";
                conn_sock = accept(listen_sock, (struct sockaddr *)&clientAddress, &clientLen);
                if (conn_sock == -1)
                    return std::cerr << "accept" << std::endl, EXIT_FAILURE;
                setnonblocking(conn_sock);
                ev.events = EPOLLIN | EPOLLOUT;
                ev.data.fd = conn_sock;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1)
                    return std::cerr << "epoll_ctl: conn_sock" << std::endl, EXIT_FAILURE;
            }
            else if (events[n].events & EPOLLIN)
            {
                std::cout << "+++++++++++++++++block request ....." << endl;
                char buffer[CHUNK_SIZE];
                int len = recv(events[n].data.fd, buffer, 100, 0);
                buffer[len] = '\0';
                if (len != 100) 
                {
                    epoll_event ev1;
                    ev1.events = EPOLLOUT;
                    ev1.data.fd = events[n].data.fd;
                    if (epoll_ctl(epollfd, EPOLL_CTL_MOD, events[n].data.fd, &ev1) == -1)
                        return std::cerr << "epoll_ctl: conn_sock11" << std::endl, EXIT_FAILURE;
                }
                std::cout << buffer << std::endl;
            }
            else if (events[n].events & EPOLLOUT)
            {
                std::cout << "+++++++++++++++++block respond ....." << endl;

                send(events[n].data.fd, httpResponse.c_str(), httpResponse.size(), 0);
                close(events[n].data.fd);
                // int r = do_use_fd(events[n].data.fd, server);
                // if (r == -1)
                //     EXIT_FAILURE;
            }
        }
    }

    close(serverSocket);
    delete server;
    return EXIT_SUCCESS;
}
