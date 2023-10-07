#include <stdlib.h>
#include <stdio.h>
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

int main() {
    OOP_DECLARE(FooBar, fb);
    fb.str = "pneumonoultramicroscopicsilicovolcanoconiosis";

    printf("\nIterate with while loop...\n");

    OOP_DECLARE(FooBarIterator, fbi);
    if (!ITER(FooBar, &fb, &fbi)) {
        char c = '\0';
        while (!NEXT(FooBarIterator, &fbi, &c)) {
            printf("%c", c);
        }
    }
    
    printf("\nTrying to iterate with FOR_EACH...\n");

    FOR_EACH(char, c, FooBar, &fb, FooBarIterator) {
        printf("%c", c);
    }

    printf("\nSuccessful. Exiting...\n");
    
    return 0;
}