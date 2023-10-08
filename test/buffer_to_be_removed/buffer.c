#include "buffer.h"
void buffer_init(buffer * b, char * c_str) {
    char * buf = OOP_GET(buffer, *b, buf);
    if (c_str) {
        OOP_GET(buffer, *b, size) = strlen(c_str);
        while (*c_str != '\0') {
            *buf = *c_str;
            c_str++;
            buf++;
        }
    } else {
        OOP_GET(buffer, *b, size) = 0;
    }
    *buf = '\0';
    
}

int buffer_print(buffer * b) {
    return printf((const char *) OOP_GET(buffer, *b, buf));
}

int buffer_append(buffer * b, buffer * to_append) {
    if (MAX_BUFFER_LENGTH <= OOP_GET(buffer, *b, size) + OOP_GET(buffer, *to_append, size)) {
        return 0; // no characters written to b
    }
    char * b1 = OOP_GET(buffer, *b, buf) + OOP_GET(buffer, *b, size); // point to end of buffer
    char * b2 = OOP_GET(buffer, *to_append, buf);
    while (*b2 != '\0') {
        *b1 = *b2;
        b2++;
        b1++;
    }
    *b1 = '\0';
    OOP_GET(buffer, *b, size) += OOP_GET(buffer, *to_append, size);
    return OOP_GET(buffer, *to_append, size);
}