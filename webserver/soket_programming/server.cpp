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

std::string readFile(const std::string &path, int fd)
{
    if (path.empty())
        return "";
    if (path.find("=") != std::string::npos)
    {
        std::string test = path.substr(path.find("=") + 1, path.length());
        std::cout << "<<<<<[" << test << ">>>>>]" << "\n";
        test = "/var/www/Resources/" + test;
        std::ifstream file1(test.c_str());
        if (!file1.is_open())
            std::cout << "I was here" << std::endl;
        else
        {
            std::stringstream content;
            content << file1.rdbuf();
            file1.close();
            for (size_t i = 0; i < content.str().length(); i++){
                std::cout << content.str().at(i);
            }
            std::cout << "I was here is able to open " << content.str().length() <<  std::endl;
        }
        return "";
    }
    std::string new_path;
    new_path = "/var/www/Resources/" + path;
    std::ifstream file(new_path.c_str());
    if (!file.is_open())
    {
        std::cerr << "Failed to open file:: " << new_path << std::endl;
        return "";
    }
    (void)fd;
    // else{

    //     return new_path;
    // }
    // return NULL;

    // int rval;
    // (void)rval;
    // char buffer[BUFFER_SIZE];

    // memset(buffer, 0, sizeof(buffer));
    // rval = read(fd, buffer, sizeof(buffer));
    // std::string return_chunked = buffer;
    // return return_chunked;
    // //-----------------
    
    
    
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
    // std::string filePath = "/index.html";
    std::string filePath = "/upload.html";
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

int do_use_fd(int fd, Server *server)
{
    int rval;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    rval = recv(fd, buffer, sizeof(buffer), 0);

    if (rval == 0)
    {
        std::cout << "Client disconnected" << std::endl;
        close(fd);
    }
    else
    {
        std::string request(buffer);
        std::string filePath = server->parsRequest(request);
        std::string content = readFile(filePath, fd);
        
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
            send(fd, notFound.c_str(), notFound.length(), 0);
        }
        else
        {
            std::string contentType = server->getContentType(filePath); 
            std::string httpResponse = server->creatHttpResponse(contentType, content);
            // std::cout << "---->>>>>>>" <<  httpResponse << std::endl;
            // constract the httpresponse without the content
            // read a pace of the file content ???????? (function with static variable > set the static variable to null if the eof has
            // occured so 
            send(fd, httpResponse.c_str(), httpResponse.length(), 0);
        }
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

    while (true)
    {

        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1)
            return std::cerr << "epoll_wait" << std::endl, EXIT_FAILURE;
        int n = 0;
        for (n = 0; n < nfds; ++n)
        {
            if (events[n].data.fd == listen_sock)
            {
                conn_sock = accept(listen_sock, (struct sockaddr *)&clientAddress, &clientLen);
                if (conn_sock == -1)
                    return std::cerr << "accept" << std::endl, EXIT_FAILURE;
                setnonblocking(conn_sock);
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = conn_sock;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1)
                    return std::cerr << "epoll_ctl: conn_sock" << std::endl, EXIT_FAILURE;
            }
            else
            {
                int r = do_use_fd(events[n].data.fd, server);
                if (r == -1)
                    EXIT_FAILURE;
            }
        }
    }

    close(serverSocket);
    delete server;
    return EXIT_SUCCESS;
}
