#include "server.hpp"


std::string readFile(const std::string &path)
{
    // std::ifstream file(path, std::ios::binary);
    // webserver/soket_programming/NFT-preview-card-component/image-equilibrium.jpg
    std::string new_path;
    if (path.find(".html") != std::string::npos){
        new_path = path;
    }
    else
        new_path = "/var/www/NFT-preview-card-component/" + path;
    
    std::ifstream file(new_path);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << new_path << std::endl;
        return "";
    }
    std::stringstream content;
    content << file.rdbuf();
    file.close();
    return content.str();
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        (void)argv;
        std::cout << "correct input : ./webserv [configuration file]" << std::endl;
        return EXIT_FAILURE;
    }

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
        return perror("opening stream socket."), EXIT_FAILURE;

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    int len = sizeof(serverAddress);

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
                {
                    std::cout << "Ending connections" << std::endl;
                }
                else
                {
                    std::string request(buffer);
                    std::cout << "Received request: " << request << std::endl;
                    std::string filePath = "/var/www/NFT-preview-card-component/index.html";
                    if (request.find("GET / ") == std::string::npos)
                    {
                        size_t startPos = request.find("GET /") + 5;
                        size_t endPos = request.find(" HTTP/");
                        filePath = request.substr(startPos, endPos - startPos);
                    }
                    std::cout << "file path --> " << filePath << std::endl;
                    std::string content = readFile(filePath);
                    if (content.empty())
                    {
                        std::string notFound = "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
                        write(msgsocket, notFound.c_str(), notFound.length());
                    }
                    else
                    {
                        std::ostringstream oss;
                        oss << content.length();
                        std::string str = oss.str();
                        std::string contentType = getContentType(filePath);
                        std::string httpResponse = "HTTP/1.1 200 OK\r\n"
                                                   "Content-Type: " + contentType + "\r\n"
                                                    "Content-Length: " + str + "\r\n"
                                                    "\r\n" + content;
                        write(msgsocket, httpResponse.c_str(), httpResponse.length());
                    }
                }
            } while (rval > 0);
            close(msgsocket);
        }
    } while (true);

    close(serverSocket);
    return EXIT_SUCCESS;
}