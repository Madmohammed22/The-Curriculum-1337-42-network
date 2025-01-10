#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
    if (argc < 2){
       std::cout << "correct input : ./webserver <config_file>" << std::endl;
       return EXIT_FAILURE;
    }

    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
        return perror("opening stream socket."), EXIT_FAILURE;

    sockaddr_in clientAddress;
    clientAddress.sin_family = AF_INET;
    clientAddress.sin_port = htons(8080);
    clientAddress.sin_addr.s_addr = INADDR_ANY;

    int len = sizeof(clientAddress);
    if (connect(clientSocket, (struct sockaddr *)&clientAddress, sizeof(clientAddress)) == -1)
        return perror("connecting stream socket"), EXIT_FAILURE;

    std::string message = argv[1];
    send(clientSocket, message.c_str(), message.length(), 0);
    close(clientSocket);
    return EXIT_SUCCESS;
}