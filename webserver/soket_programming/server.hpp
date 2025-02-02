#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <map>
#include <vector>
#include <fstream>
#include <stack>
#include <poll.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <poll.h>
#include <vector>
#include <sys/epoll.h>
#include <fcntl.h>

// using namespace std;

#define CHUNK_SIZE 1024
#define MAX_EVENTS 10

class Server
{
public:
    Server();
    Server(const Server& Init);
    Server& operator=(const Server& Init);
    ~Server();

public:
    std::string parsRequest(std::string request);
    std::string parsRequest404(std::string request);
    std::string getContentType(const std::string &path);
    std::string creatHttpResponse(std::string contentType, std::string content);
    std::string creatHttpResponseForPage404(std::string contentType, std::ifstream &file, std::string& s_content);
    
};

class Reader{
private :
    std::vector<std::string> buffer;

public:
    Reader();
    Reader(const Reader& Init);
    Reader& operator=(const Reader& Init);
    ~Reader();

public:
    bool TheBalancedParentheses(std::string file);
};


#endif


/*
std::string Server::parsRequest(const std::string &request, std::string &method, std::string &body) {
    if (request.empty())
        return "";
    
    std::cout << "Received request: " << request << std::endl;
    
    std::string filePath = "/index.html";
    size_t methodEnd = request.find(' ');
    if (methodEnd != std::string::npos) {
        method = request.substr(0, methodEnd);
    }

    if (method == "GET" || method == "POST") {
        size_t startPos = request.find(' ') + 1;
        size_t endPos = request.find(' ', startPos);
        if (endPos != std::string::npos) {
            filePath = request.substr(startPos, endPos - startPos);
        }

        if (method == "POST") {
            size_t bodyStart = request.find("\r\n\r\n");
            if (bodyStart != std::string::npos) {
                body = request.substr(bodyStart + 4);
            }
        }
    }
    return filePath;
} 
 */