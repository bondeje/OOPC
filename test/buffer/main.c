#include "buffer.h"

int main(int argc, char ** args) {
    if (argc > 2) {
        OOP_DECLARE(buffer, b1);
        OOP_GET(buffer, b1, init)(&b1, args[1]);
        OOP_DECLARE(buffer, b2);
        OOP_GET(buffer, b2, init)(&b2, args[2]);

        if (OOP_GET(buffer, b1, append)(&b1, &b2)) {
            printf("successfully concatenated two buffers:\n");
            OOP_GET(buffer, b1, print)(&b1);
        } else {
            printf("insufficient buffer space to concatenate two buffers:\n");
            OOP_GET(buffer, b1, print)(&b1);
            printf("\n");
            OOP_GET(buffer, b2, print)(&b2);
        }
        printf("\n");
    }
    return 0;
}