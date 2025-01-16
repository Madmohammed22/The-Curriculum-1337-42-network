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
    std::cout << "[Server] Distructor is called" << std::endl;
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
    if (path.empty())
        return "";
    std::string new_path;
    new_path = "/var/www/Resources/" + path;
    std::ifstream file(new_path.c_str());
    if (!file.is_open())
    {
        std::cerr << "Failed to open file:: " << new_path << std::endl;
        return "";
    }
    std::stringstream content;
    content << file.rdbuf();
    file.close();
    return content.str();
}

std::string Server::parsRequest(std::string request)
{
    if (request.empty())
        return "";
    std::cout << "Received request: " << request << std::endl;
    std::string filePath = "video.mp4";
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
                                             "Content-Length: " +
                               str + "\r\n"
                                     "\r\n" +
                               content;
    return httpResponse;
}

std::string Server::creatHttpResponseForPage404(std::string contentType, std::ifstream &file)
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
                                             "Content-Length: " +
                               str + "\r\n"
                                     "\r\n" +
                               content;
    return httpResponse;
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
    serverSocket = socket(AF_INET, SOCK_STREAM, getprotobyname("tcp")->p_proto);
    if (serverSocket < 0)
        return perror("opening stream socket."), EXIT_FAILURE;

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

    // int msgsocket = 0;
    char buffer[1024];
    size_t rval = 0;
    sockaddr_in clientAddress;
    socklen_t clientLen = sizeof(clientAddress);

    std::cout << "Server is listening" << std::endl;

    std::vector<struct pollfd> poll_fds;
    struct pollfd server_poll_fd;
    server_poll_fd.fd = serverSocket;
    server_poll_fd.events = POLLIN;
    poll_fds.push_back(server_poll_fd);
    ///*
    while (true)
    {
        int num_fds = poll(&poll_fds[0], poll_fds.size(), 0);
        if (num_fds < 0){
            std::cout << "Poll error" << std::endl;
            continue;
        }

        for (std::vector<struct pollfd>::iterator it = poll_fds.begin(); it != poll_fds.end();)
        {
            // if (std::find(poll_fds.begin(), poll_fds.end(), ))
            if (it->fd == serverSocket && it->revents & POLLIN)
            {
                int new_socket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientLen);
                if (new_socket < 0)
                {
                    std::cerr << "Accept error" << std::endl;
                    continue;
                }

                struct pollfd client_poll_fd;
                client_poll_fd.fd = new_socket;
                client_poll_fd.events = POLLIN;
                poll_fds.push_back(client_poll_fd);
                ++it;
            }
            else if (it->revents && POLLIN)
            {
                memset(buffer, 0, sizeof(buffer));
                rval = recv(it->fd, buffer, sizeof(buffer), 0); // 
                if (rval == 0)
                {
                    std::cout << "Client disconnected" << std::endl;
                    close(it->fd);
                    it = poll_fds.erase(it);
                }
                else
                {
                    std::string request(buffer);
                    std::string filePath = server->parsRequest(request);
                    std::string content = readFile(filePath);
                    if (content.empty())
                    {
                        std::string path1 = "/var/www/Errors/404/";
                        std::string path2 = "errorPage.html";
                        std::string new_path = path1 + path2;
                        std::ifstream file(new_path.c_str());
                        if (!file.is_open())
                            return perror(NULL), delete server, EXIT_FAILURE;

                        std::string contentType = server->getContentType(new_path);
                        std::string notFound = server->creatHttpResponseForPage404(contentType, file);
                        send(it->fd, notFound.c_str(), notFound.length(), 0);
                    }
                    else
                    {
                        std::string contentType = server->getContentType(filePath);
                        std::string httpResponse = server->creatHttpResponse(contentType, content);
                        send(it->fd, httpResponse.c_str(), httpResponse.length(), 0);
                    }
                    ++it;
                }
            }
            else{
                ++it;
            }
        }
    }
    close(serverSocket);
    delete server;
    return EXIT_SUCCESS;
}
