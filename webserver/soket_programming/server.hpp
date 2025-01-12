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

using namespace std;

#define TRUE 1

class Server
{
private:
    /* data */
public:
    Server(const Server& Init);
    Server& operator=(const Server& Init);
    ~Server();
};

inline std::string getContentType(const std::string &path)
{
    if (path.rfind(".html") == path.length() - 5)
        return "text/html";
    if (path.rfind(".css") == path.length() - 4)
        return "text/css";
    if (path.rfind(".js") == path.length() - 3)
        return "application/javascript";
    if (path.rfind(".json") == path.length() - 5)
        return "application/json";
    if (path.rfind(".xml") == path.length() - 4)
        return "application/xml";
    if (path.rfind(".mp4") == path.length() - 4)
        return "video/mp4";
    if (path.rfind(".mp3") == path.length() - 4)
        return "audio/mpeg";
    if (path.rfind(".wav") == path.length() - 4)
        return "audio/wav";
    if (path.rfind(".ogg") == path.length() - 4)
        return "audio/ogg";
    if (path.rfind(".png") == path.length() - 4)
        return "image/png";
    if (path.rfind(".jpg") == path.length() - 4)
        return "image/jpeg";
    if (path.rfind(".jpeg") == path.length() - 5)
        return "image/jpeg";
    if (path.rfind(".gif") == path.length() - 4)
        return "image/gif";
    if (path.rfind(".svg") == path.length() - 4)
        return "image/svg+xml";
    if (path.rfind(".ico") == path.length() - 4)
        return "image/x-icon";
    return "application/octet-stream";
}

#endif