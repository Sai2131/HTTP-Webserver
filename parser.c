#include "parser.h"

int findContentStartIndex(char* buffer, int bufferSize){
    if(buffer == NULL){
        perror("Null parameter(s) in findContentStartIndex()");
        exit(EXIT_FAILURE);
    }

    char lastElement = buffer[bufferSize-1];
    buffer[bufferSize-1] = '\0';

    char* startOfContentPtr = strstr(buffer, "\r\n\r");
    if(startOfContentPtr == NULL){
        buffer[bufferSize-1] = lastElement;
        return -1;
    }

    int lastIndex = startOfContentPtr - buffer + 3;
    if(buffer[lastIndex] != '\n'){
        buffer[bufferSize-1] = lastElement;
        return -1;
    }

    buffer[bufferSize-1] = lastElement;
    return lastIndex;
}

int parseRequest(parsedInfo* info, char* buffer, int contentStart){
    if(info == NULL || buffer == NULL){
        perror("Null parameter(s) in parseRequest()");
        exit(EXIT_FAILURE);
    }

    //Set the last CLRF to null for strstr to work
    buffer[contentStart-1] = '\0';
    buffer[contentStart-2] = '\0';

    int index = parseRequestLine(info, buffer, 0, contentStart);
    if(index < 0){
        return index;
    }

    
    index = parseHeaderFields(info, buffer, index, contentStart);
    if(index < 0){
        return index;
    }
    
    return index;
}

int parseRequestLine(parsedInfo* info, char* buffer, int startIndex, int contentStart){
    if(info == NULL || buffer == NULL){
        perror("Null parameter(s) in parseRequestLine()");
        exit(EXIT_FAILURE);
    }

    char* endPtr;

    //Parse method
    endPtr = strstr(buffer, " ");
    if(endPtr == NULL){
        return -1;
    }
    strncpy(info->Method, buffer + startIndex, endPtr-buffer-startIndex);
    startIndex = endPtr-buffer + 1;

    //Parse uri
    endPtr = strstr(buffer+startIndex, " ");
    if(endPtr == NULL){
        return -1;
    }
    strncpy(info->Uri, buffer + startIndex, endPtr-buffer-startIndex);
    startIndex = endPtr-buffer+1;

    //Parse version
    endPtr = strstr(buffer+startIndex, "\r\n");
    if(endPtr == NULL){
        return -1;
    }
    strncpy(info->Version, buffer + startIndex, endPtr-buffer-startIndex);
    startIndex = endPtr-buffer+2;

    return startIndex;

}

int parseHeaderFields(parsedInfo* info, char* buffer, int startIndex, int contentStart){
    char* endPtr;
    while(1){
        endPtr = strstr(buffer, "\r\n");

    }
    return 0;
}



