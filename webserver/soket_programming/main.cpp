#include "main.hpp"

int main()
{

    /* At this part we are creating a socket, and checking if an
    error may accure, if it does we must incounter return value
    of an correct creating a socket is -1. */

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
        return perror("opening stream socket."), EXIT_FAILURE;

    /* We define so set of info related to the socket like wich family
    is used when it comes to the versin of IPs
    and port by using htons that transform an unsigned machine
    byte order to network byte order. as well as sin_addr which define
    we can work and listen with all the available IPs */

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    int len = sizeof(serverAddress);
    /* bind() is used to bind a socket to a specific address and port,
    making the socket listen for incoming connection requests on that address and port */

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
        return perror("binding stream socket."), EXIT_FAILURE;

    /* Find out assigned port and print it out with the help of getsockname function*/
    if (getsockname(serverSocket, (struct sockaddr *)&serverAddress, (socklen_t *)&len) == -1)
        return perror("getting socket name."), EXIT_FAILURE;
    std::cout << "Socket port " << ntohs(serverAddress.sin_port) << std::endl;

    /* The listen() function applies only to stream sockets. It indicates a readiness to accept
    client connection requests, and creates a connection request queue of length
    backlog to queue incoming connection requests */
    /* Start accepting connections. */
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
                else
                    std::cout << buffer << std::endl;
            } while (rval > 0);
    } while (TRUE);
    
    return EXIT_SUCCESS;
}