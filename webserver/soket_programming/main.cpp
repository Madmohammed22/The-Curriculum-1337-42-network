#include "main.hpp"

int main(int argc, char **argv)
{

    if (argc < 2){
        (void)argv;
       std::cout << "correct input : ./webserver <config_file>" << std::endl;
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

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
        return perror("binding stream socket."), EXIT_FAILURE;

    if (getsockname(serverSocket, (struct sockaddr *)&serverAddress, (socklen_t *)&len) == -1)
        return perror("getting socket name."), EXIT_FAILURE;
    std::cout << "Socket port " << ntohs(serverAddress.sin_port) << std::endl;

    if (listen(serverSocket, 5) < 0)
        return perror("listen stream socket"), EXIT_FAILURE;

    int msgsocket = 0;
    char buffer[1024];
    
    size_t rval = 0;
    do
    {
        msgsocket = accept(serverSocket, (struct sockaddr *)0, (socklen_t *)(int *)0);
        if (msgsocket < 0)
            return perror("accept stream socket"), EXIT_FAILURE;
        else
            do
            {
                memset(buffer, 0, sizeof(buffer));
                rval = read(msgsocket, buffer, sizeof(buffer));
                if (rval < 0)
                    return perror("reading stream message"), EXIT_FAILURE;
                if (rval == 0)
                    std::cout << "Ending connections" << std::endl;
                else{
                    std::string terminate = buffer;
                    if (terminate == "EOF")
                        exit(0);
                    std::cout << buffer << std::endl;
                }
            } while (rval > 0);
    } while (TRUE);

    return EXIT_SUCCESS;
}