#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <foobar.h>

int FooBar_iter(void * fbable, void * fbator) {
    if (!fbable || !fbator) {
        return ITERATOR_FAIL;
    }
    FooBarIterator * fbr = (FooBarIterator *) fbator;
    OOP_INIT(FooBarIterator, *fbr);
    fbr->fb = (FooBar *) fbable;
    fbr->pc = fbr->fb->str;
    return (fbr->pc ? ITERATOR_GO : ITERATOR_FAIL);
}

int FooBarIterator_iter(void * fbable, void * fbator) {
    return FooBar_iter(((FooBarIterator *) fbable)->fb, fbator);
}

int FooBarIterator_next(void * fbator, void * pdest) {
    FooBarIterator * fbator_ = (FooBarIterator * ) fbator;
    if (!fbator || !pdest) {
        return ITERATOR_FAIL;
    }
    char * pdest_ = (char *) pdest;
    *pdest_ = *(fbator_->pc++);
    return ((*pdest_ == '\0') ? ITERATOR_STOP : ITERATOR_GO);
}

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

bool FooBar_contains(void * fb, void * c) {
    return strchr(OOP_GET(FooBar, *(FooBar *)fb, str), *(char *)c) != NULL;
}

size_t FooBar_len(void * fb) {
    return strlen(OOP_GET(FooBar, *(FooBar*)fb, str));
}

int main() {
    OOP_DECLARE(FooBar, fb);
    //INIT(FooBar, &fb, "pneumonoultramicroscopicsilicovolcanoconiosis");
    fb.str = "pneumonoultramicroscopicsilicovolcanoconiosis";

    printf("string in initialized FooBar: %s\nlength = %zu\nis empty? %d", fb.str, LEN(FooBar, &fb), IS_EMPTY(FooBar, &fb));

    printf("\nIterate with while loop...\n");

    OOP_DECLARE(FooBarIterator, fbi);
    ITER(FooBar, &fb, &fbi);
    {
    char c = '\0';
    while (!NEXT(FooBarIterator, &fbi, &c)) {
        printf("%c", c);
    }
    }

    printf("\nTrying to iterate with FOR_EACH...\n");

    FOR_EACH(char, c, FooBar, &fb, FooBarIterator) {
        printf("%c", c);
    }
    printf("\n");

    c = 'v';
    printf("is %c in initialized FooBar: %d\n", c, CONTAINS(FooBar, &fb, &c));
    c = 'z';
    printf("is %c in initialized FooBar: %d\n", c, CONTAINS(FooBar, &fb, &c));
    c = '?';
    printf("is %c in initialized FooBar: %d\n", c, CONTAINS(FooBar, &fb, &c));

    printf("Successful. Exiting...\n");
    
    return 0;
}