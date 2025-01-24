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

using namespace std;
#define TRUE 1
#define MAX_EVENTS 10
#define CHUNK_SIZE 100

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
    std::vector<string> buffer;

public:
    Reader();
    Reader(const Reader& Init);
    Reader& operator=(const Reader& Init);
    ~Reader();

public:
    bool TheBalancedParentheses(std::string file);
};


#endif
