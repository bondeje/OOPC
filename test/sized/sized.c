#include <stdio.h>
#include <string.h>
#include <foobar.h>

size_t FooBar_len(void * fb) {
    return strlen(OOP_GET(FooBar, *(FooBar*)fb, str));
}

int main() {
    
    OOP_DECLARE(FooBar, fb);
    OOP_GET(FooBar, fb, str) = "what is foobar?";
    printf("string in initialized FooBar: %s\nlength = %zu\n", OOP_GET(FooBar, fb, str), LEN(FooBar, &fb));
        
    return 0;
}