#include <stdio.h>
#include <foobar.h>
void test_no_return(foobar * fb, int c, float f) {
    printf("in test_no_return, sum %d + %d + %f = %f\n", fb->a, c, f, fb->a + c + f);
}
double test_return(foobar_return * fb, int c, float f) {
    return fb->b + c + f;
}

IMPLEMENT_CALLABLE(foobar, test_no_return)
IMPLEMENT_CALLABLE(foobar_return, test_return)