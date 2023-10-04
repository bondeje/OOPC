#include <stdio.h>
#include <foobar.h>

int main() {
    OOP_DECLARE(foobar, fbnr);
    fbnr.a = -2;
    CALL(foobar, &fbnr, 4, 3.1); // should print -2 + 4 + 3.1 = 5.1

    double result = 0.0;
    OOP_DECLARE(foobar_return, fbr);
    fbr.b = -1;
    CALL(foobar_return, &fbr, &result, 5, 4.2);
    printf("result test_return, sum %d + %d + %f = %f\n", fbr.b, 5, 4.2, result); // should print -1 + 5 + 4.2 = 8.2
    return 0;
}