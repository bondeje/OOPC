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
    fbr->stop = ITERATOR_PAUSE;
    if (fbr->pc == NULL) {
        return ITERATOR_FAIL;
    }
    return ITERATOR_GO;
}

int FooBarIterator_iter(void * fbable, void * fbator) {
    return FooBar_iter(((FooBarIterator *) fbable)->fb, fbator);
}

void * FooBarIterator_next(void * fbator) {
    FooBarIterator * fbator_ = (FooBarIterator * ) fbator;
    char * out = fbator_->pc++;;
    if (*out == '\0') {
        fbator_->stop = ITERATOR_STOP;
    } else {
        fbator_->stop = ITERATOR_GO;
    }
    return (void *)out;
}

int FooBarIterator_stop(void * fbator) {
    if (!fbator) {
        return ITERATOR_STOP;
    }
    
    return ((FooBarIterator *)fbator)->stop;
}

int main() {
    OOP_DECLARE(FooBar, fb);
    fb.str = "pneumonoultramicroscopicsilicovolcanoconiosis";

    printf("\nIterate with while loop...\n");

    OOP_DECLARE(FooBarIterator, fbi);
    ITER(FooBar, &fb, &fbi);
    char c = *(char *) NEXT(FooBarIterator, &fbi);
    while (STOP(FooBarIterator, &fbi) != ITERATOR_STOP) {
        printf("%c\n", c);
        c = *(char *) NEXT(FooBarIterator, &fbi);
    }

    printf("\nTrying to iterate with FOR_EACH...\n");

    FOR_EACH(char, c, FooBar, &fb, FooBarIterator) {
        printf("%c\n", *c);
    }

    printf("Successful. Exiting...\n");
    
    return 0;
}