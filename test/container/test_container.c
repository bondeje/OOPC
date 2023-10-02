#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <foobar.h>

/*
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

FooBar * FooBar_new_(char * str) {
    FooBar * fb = (FooBar *) malloc(sizeof(FooBar));
    if (!fb) {
        return fb;
    }
    OOP_INIT(FooBar, *fb);

    FooBar_init_(fb, str);
    return fb;
}

void * FooBar_new(unsigned int n, ...) {
    if (n) {
        va_list args;
        va_start(args, n);
        char * str = va_arg(args, char *);
        va_end(args);
        return FooBar_new_(str);
    }
    return NULL;
}
int FooBar_del(void * fb) {
    free(fb);
    return 0;
}
*/

bool FooBar_contains(void * fb, void * c) {
    return strchr(OOP_GET(FooBar, *(FooBar *)fb, str), *(char *)c) != NULL;
}

int main() {
    char c;
    OOP_DECLARE(FooBar, fb);
    //INIT(FooBar, &fb, "what is foobar?");
    fb.str = "what is foobar?";
    printf("string in initialized FooBar: %s\n", OOP_GET(FooBar, fb, str));

    c = 'a';
    printf("is %c in initialized FooBar: %d\n", c, CONTAINS(FooBar, &fb, &c));
    c = 'z';
    printf("is %c in initialized FooBar: %d\n", c, CONTAINS(FooBar, &fb, &c));
    c = '?';
    printf("is %c in initialized FooBar: %d\n", c, CONTAINS(FooBar, &fb, &c));

    fb.str = "what's in a name?";
    //FooBar * fb2 = NEW(FooBar, "what's in a name?");
    printf("string in alloc'd FooBar: %s\n", OOP_GET(FooBar, fb, str));

    c = 'a';
    printf("is %c in alloc'd FooBar: %d\n", c, CONTAINS(FooBar, &fb, &c));
    c = 'z';
    printf("is %c in alloc'd FooBar: %d\n", c, CONTAINS(FooBar, &fb, &c));
    c = '?';
    printf("is %c in alloc'd FooBar: %d\n", c, CONTAINS(FooBar, &fb, &c));
    
    //DEL(FooBar, fb2);
    return 0;
}