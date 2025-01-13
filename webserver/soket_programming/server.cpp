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
    std::string new_path;
    new_path = "/var/www/NFT-preview-card-component/" + path;
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
    std::cout << "Received request: " << request << std::endl;
    std::string filePath = "index.html";
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
    (void)request;
    std::cout << "Received request: " << request << std::endl;
    std::string filePath = "errorPage.html";
    // if (request.find("GET / ") == std::string::npos)
    // {
    //     size_t startPos = request.find("GET /") + 5;
    //     size_t endPos = request.find(" HTTP/");
    //     filePath = request.substr(startPos, endPos - startPos);
    // }
    return filePath;
}

std::string Server::creatHttpResponse(std::string contentType, std::string content)
{
    std::ostringstream oss;
    oss << content.length();
    std::string str = oss.str();

    std::string httpResponse = "HTTP/1.1 200 OK\r\n"
                            "Content-Type: " + contentType + "\r\n"
                            "Content-Length: " + str + "\r\n"
                            "\r\n" + content;
    return httpResponse;
}

std::string Server::creatHttpResponseForPage404(std::string contentType, std::string content)
{
    std::ostringstream oss;
    oss << content.length();
    std::string str = oss.str();

    std::string httpResponse = "HTTP/1.1 404 Not Found\r\n"
                            "Content-Type: " + contentType + "\r\n"
                            "Content-Length: " + str + "\r\n"
                            "\r\n" + content;
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
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
        return perror("opening stream socket."), EXIT_FAILURE;

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    int len = sizeof(serverAddress);
    int a = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEPORT, &a, sizeof(int)) < 0)
        return perror(NULL), EXIT_FAILURE;
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
        return perror("binding stream socket"), EXIT_FAILURE;

    if (getsockname(serverSocket, (struct sockaddr *)&serverAddress, (socklen_t *)&len) == -1)
        return perror("getting socket name."), EXIT_FAILURE;
    std::cout << "Socket port " << ntohs(serverAddress.sin_port) << std::endl;

    if (listen(serverSocket, 5) < 0)
        return perror("listen stream socket"), EXIT_FAILURE;

    int msgsocket = 0;
    char buffer[1024];
    size_t rval = 0;

    sockaddr_in clientAddress;
    socklen_t clientLen = sizeof(clientAddress);
    do
    {
        msgsocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientLen);
        if (msgsocket < 0)
            return perror("accept stream socket"), EXIT_FAILURE;
        else
        {
            do
            {
                memset(buffer, 0, sizeof(buffer));
                rval = recv(msgsocket, buffer, sizeof(buffer), 0);
                if (rval == 0)
                    std::cout << "Ending connections" << std::endl;
                else
                {
                    std::string request(buffer);
                    std::string filePath = server->parsRequest(request);
                    std::string content = readFile(filePath);
                    if (content.empty())
                    {
                        std::string new_path;
                        new_path = "/var/www/Errors/404/" + server->parsRequest404(request);
                        std::ifstream file(new_path.c_str());
                        if (!file.is_open())
                        {
                            std::cerr << "Failed to open file:: " << new_path << std::endl;
                            return perror(NULL), EXIT_FAILURE;
                        }
                        std::stringstream content_v1;
                        content_v1 << file.rdbuf();
                        file.close();
                        content = content_v1.str();         
                        std::string contentType = server->getContentType(new_path);
                        std::string notFound = server->creatHttpResponseForPage404(contentType, content);
                        send(msgsocket, notFound.c_str(), notFound.length(), 0);
                    }
                    else
                    {
                        std::string contentType = server->getContentType(filePath);
                        std::string httpResponse = server->creatHttpResponse(contentType, content);
                        send(msgsocket, httpResponse.c_str(), httpResponse.length(), 0);
                    }
                }
            } while (rval > 0);
            close(msgsocket);
        }
    } while (true);

    close(serverSocket);
    return EXIT_SUCCESS;
}
