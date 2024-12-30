#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct parsedInfo {
    bool badRequest;
    int startOfContent;

    char Method[16];
    char Version[16];
    char Uri[8192];
    //* add hashtable to hold header fields */
};
typedef struct parsedInfo parsedInfo;

/** 
 * Given a buffer it returns a struct with all the request info or NULL for error.
**/
parsedInfo* parseRequest(char* buffer);

int parseRequestLine(parsedInfo* info, char* buffer);

int parseHeaderFields(parsedInfo* info, char* buffer);

void deleteParseRequest(parsedInfo**);
