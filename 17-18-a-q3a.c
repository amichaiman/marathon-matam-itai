#include <stdio.h>

#define BITS_IN_BYTE 8

unsigned char cyclic_byte_left(unsigned char b, unsigned int n) {
    return b<<(n%BITS_IN_BYTE) | b>>(BITS_IN_BYTE - n%BITS_IN_BYTE);
}

int main() {
    unsigned char b = 0x1;
    printf("%d %d\n", b, cyclic_byte_left(b, 16));
    return 0;
}
