#include <arpa/inet.h>
#include <sys/socket.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

#define PORT 55555

int main(void){

    parsedInfo* info = parseRequest("GET uri HTTP/1.1");
    return 0;
}

/*

int main(void){

    int serverFD = socket(AF_INET, SOCK_STREAM, 0);

    int opt = 1;
    setsockopt(serverFD, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(serverFD, (struct sockaddr*)&address, sizeof(address));

    listen(serverFD, 64);

    int connectionFD;
    while(1){
        connectionFD = accept(serverFD, (struct sockaddr*)&address, &addrlen);
        handleRequest(connectionFD);
    }

    return 0;
}

void handleRequest(int connectionFD){

}

*/
