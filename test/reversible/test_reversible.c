#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <foobar.h>

int FooBar_iter_(FooBar * fbable, FooBarIterator * fbator, char * start, char * stop) {
    OOP_INIT(FooBarIterator, *fbator);
    fbator->fb = fbable;
    fbator->pccur = start;
    fbator->pcstop = stop;
    fbator->stop_ = ITERATOR_PAUSE;
    
    return ITERATOR_GO;
}

int FooBar_iter(void * fbable, void * fbator) {
    if (!fbable || !fbator) {
        return ITERATOR_FAIL;
    }
    FooBar * fb = (FooBar *) fbable;
    if (fb->str == NULL) {
        return ITERATOR_FAIL;
    }
    if (fb->reversed) {
        return FooBar_iter_(fb, fbator, fb->str + strlen(fb->str) - 1, fb->str - 1);
    } else {
        return FooBar_iter_(fb, fbator, fb->str, fb->str + strlen(fb->str));
    }
}

int FooBar_reversed(void * fbable, void * fbator) {
    if (!fbable || !fbator) {
        return ITERATOR_FAIL;
    }
    FooBar * fb = (FooBar *) fbable;
    if (fb->str == NULL) {
        return ITERATOR_FAIL;
    }
    if (fb->reversed) {
        return FooBar_iter_(fb, fbator, fb->str, fb->str + strlen(fb->str));
    } else {
        return FooBar_iter_(fb, fbator, fb->str + strlen(fb->str) - 1, fb->str - 1);
    }
}

int FooBar_reverse(void * fb) {
    ((FooBar *)fb)->reversed = !((FooBar *)fb)->reversed;
    return 0;
}

int FooBarIterator_iter(void * fbable, void * fbator) {
    FooBarIterator * fbi = (FooBarIterator *) fbable;
    if (fbi->fb->str > fbi->pcstop) {
        return FooBar_reversed(fbi->fb, fbator);
    } else {
        return FooBar_iter(fbi->fb, fbator);
    }
}

int FooBarIterator_next(void * fbator, void * el) {
    FooBarIterator * fbator_ = (FooBarIterator * ) fbator;
    char * out = fbator_->pccur;
    if (fbator_->pccur == fbator_->pcstop) {
        fbator_->stop_ = ITERATOR_STOP;
    } else {
        fbator_->stop_ = ITERATOR_GO;
        if (fbator_->pcstop > fbator_->pccur) {
            fbator_->pccur++;
        } else {
            fbator_->pccur--;
        }
    }
    *((char *) el) = *out;
    return 0;
}

int FooBarIterator_stop(void * fbator) {
    if (!fbator) {
        return ITERATOR_STOP;
    }
    
    return ((FooBarIterator *)fbator)->stop_;
}

int main() {
    OOP_DECLARE(FooBar, fb);
    fb.str = "pneumonoultramicroscopicsilicovolcanoconiosis";

    printf("\nIterate with while loop...\n");

    OOP_DECLARE(FooBarIterator, fbi);
    REVERSED(FooBar, &fb, &fbi);
    {
    char c = '\0';
    NEXT(FooBarIterator, &fbi, &c);
    while (STOP(FooBarIterator, &fbi) != ITERATOR_STOP) {
        printf("%c", c);
        NEXT(FooBarIterator, &fbi, &c);
    }
    }

    printf("\nTrying to iterate with FOR_EACH...\n");

    {
    FOR_EACH(char, c, FooBar, &fb, FooBarIterator) {
        printf("%c", c);
    }
    }

    OOP_INTERFACE(FooBar, fb, Reversible).reverse(&fb);
    printf("\nTrying to iterate with FOR_EACH after reverse()...\n");

    {
    FOR_EACH(char, c, FooBar, &fb, FooBarIterator) {
        printf("%c", c);
    }
    }
    
    OOP_INTERFACE(FooBar, fb, Reversible).reverse(&fb);
    printf("\nTrying to iterate with FOR_EACH after reverse() 2x...\n");
    
    {
    FOR_EACH(char, c, FooBar, &fb, FooBarIterator) {
        printf("%c", c);
    }
    }

    printf("\nSuccessful. Exiting...\n");
    
    return 0;
}