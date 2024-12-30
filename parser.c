#include "parser.h"

parsedInfo* parseRequest(char* buffer){
    parsedInfo* requestInfo = malloc(sizeof(parsedInfo));
    if(requestInfo == NULL){
        return NULL;
    }

    int index;
    index = parseRequestLine(requestInfo, buffer);
    if(index < 0){
        deleteParseRequest(&requestInfo);
        return NULL;
    }

    index = parseHeaderFields(requestInfo, buffer+index);
    if(index < 0){
        deleteParseRequest(&requestInfo);
        return NULL;
    }
    requestInfo->startOfContent = index;

    return requestInfo;
}

//Returns index of end of request line
int parseRequestLine(parsedInfo* info, char* buffer){
    return 0;
}

//Returns index of end of header field
int parseHeaderFields(parsedInfo* info, char* buffer){
    return 0;
}

void deleteParseRequest(parsedInfo** info){
    free((*info));
    *info = NULL;
}
