#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct parsedInfo {
    char Method[16];
    char Version[16];
    char Uri[4192];
    //* add DA to hold header fields */
};
typedef struct parsedInfo parsedInfo;

/*
* Parses a HTTP request into its individual parts given the buffer containing the entire request
* and the index at which the content part starts. Returns -1 if request is ill formed. -2 if URI is too long. -3 for error.
* 0 for normal function.
*/
int parseRequest(parsedInfo* info, char* buffer, int contentStart);

/*
* Helper function to parse request line. Returns -1 if request is ill formed. -2 if URI is too long. -3 for error.
* Otherwise returns the start index of Header fields.
*/
int parseRequestLine(parsedInfo* info, char* buffer, int startIndex, int contentStart);

/*
* Helper function to parse header fields. Returns -1 if request is ill formed. -3 for error. 0 for normal function.
*/
int parseHeaderFields(parsedInfo* info, char* buffer, int startIndex, int contentStart);

void deleteParseRequest(parsedInfo** info);

/*
* Find the last index of the response section contained inside the buffer. -1 if it doesn't exist. -2 for error.
* Works without null termination
*/
int findContentStartIndex(char* buffer, int bufferSize);

