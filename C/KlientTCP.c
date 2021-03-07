#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT_SERWERA 50000
#define ROZMIAR_BUFORA 256

/*int createTCPsocket(int domain, int type, int protocol)
{
    int socket;
    socket = socket(domain, type, protocol);
    if (socket < 0)
        return perror("Socket error");
    exit(1);
    else return socket;
} */


int main()
{
    int gniazdo, conn;
    struct sockaddr_in serwer = { };
    serwer.sin_family = AF_INET;
    serwer.sin_port = htons( PORT_SERWERA);
    inet_pton( AF_INET, "127.0.0.1", &serwer.sin_addr );

    char bufor[ROZMIAR_BUFORA]= "...";
    gniazdo= socket(AF_INET, SOCK_STREAM, 0);
    if (gniazdo < 0)
    {
        perror("socket error");
        exit(-1);
    }
    conn = connect(gniazdo, (struct sockaddr *) &serwer, sizeof(serwer));
    if (conn < 0)
    {
        perror("Connection error");
        exit(2);
    }
    send(gniazdo, bufor, sizeof(bufor), 0);

    while (recv(gniazdo, bufor, sizeof(bufor), 0) > 0)
    {
        puts(bufor);
    }
    return 0;
}





