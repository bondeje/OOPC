#include <oopc.h>
INCLUDE_OOPC
INCLUDE <stdio.h>
INCLUDE <string.h>
DEFINE MAX_BUFFER_LENGTH 1024
TYPEDEF(struct buffer, buffer)
void buffer_init(buffer * b, char * c_str);
int buffer_print(buffer * b);
int buffer_append(buffer * b, buffer * to_append);
CLASS(buffer, 
    MEMBER(int, size)
    ARRAY_MEMBER(char, buf, MAX_BUFFER_LENGTH)
    CLASS_FUNCTION(buffer_init, void, init, buffer *, char *)
    CLASS_FUNCTION(buffer_print, int, print, buffer *)
    CLASS_FUNCTION(buffer_append, int, append, buffer *, buffer *)
)