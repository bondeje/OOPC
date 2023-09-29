#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <foobar.h>

void FooBar_init_(FooBar * fb, char * str) {
    fb->str = str;
}

int FooBar_init(void * fb, unsigned int n, ...) {
    if (n) {
        va_list args;
        va_start(args, n);
        char * str = va_arg(args, char *);
        va_end(args);
        FooBar_init_(fb, str);
        return 0;
    }
    return 1;
}

int main() {
    OOP_DECLARE(FooBar, fb);
    INIT(FooBar, &fb, "what is foobar?");
    printf("string in initialized FooBar: %s\n", OOP_GET(FooBar, fb, str));

    return 0;
}