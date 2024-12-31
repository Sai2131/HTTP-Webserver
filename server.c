#include <arpa/inet.h>
#include <sys/socket.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

#define PORT 55555

int main(void){

    /*
    parsedInfo* info = parseRequest("GET uristuff HTTP/1.1\r\nkey1:val1\r\nkey2: val2 \r\n key3: val4\r\n\r\nthisiscontent", 63);
    printf("%s\n", info->Method);
    printf("%s\n", info->Uri);
    printf("%s\n", info->Version);
    */

    char str[75] = "GET uristuff HTTP/1.1\r\nkey1:val1\r\nkey2: val2 \r\n key3: val4\r\n\r\nthisiscontent";
    int x = findContentStartIndex(str, 75);
    parsedInfo info;
    parseRequest(&info, str, x);

    printf("%s\n", info.Method);
    printf("%s\n", info.Uri);
    printf("%s\n", info.Version);
    
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
