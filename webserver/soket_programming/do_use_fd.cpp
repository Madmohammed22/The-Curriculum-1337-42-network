#include "server.hpp"

int do_use_fd_test(int fd, Server *server, std::string& request)
{

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
