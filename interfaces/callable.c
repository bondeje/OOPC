#include <stdarg.h>
#include <callable.h>

void vCallable_init(void * self, unsigned int n, va_list vargs) {
    Callable * cb = (Callable *) self;
    void * obj = va_arg(vargs, void *);
    call_t func = va_arg(vargs, call_t);
    cb->obj = obj;
    cb->call = func;
}

void * Callable_new(unsigned int n, ...) {
    Callable * cb = (Callable * ) malloc(sizeof(Callable));
    if (!cb) {
        return NULL;
    }
    va_list vargs;
    va_start(vargs, n);
    vCallable_init(cb, n, vargs)
    va_end(vargs);
}

void Callable_init(void * self, unsigned int n, ...) {
    if (n < 1) { // insufficient arguments. clear the callable
        Callable * cb = (Callable *) self;
        OOP_INIT(Callable, *cb);
        return;
    }
    va_list vargs;
    va_start(vargs, n);
    vCallable_init(self, n, vargs);
    va_end(vargs);
}

void Callable_del(void * self) {
    free(self);
}