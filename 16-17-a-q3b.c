#include <stdio.h>

#define BITS_IN_BYTE 8

unsigned int get_number_of_ones(unsigned int n) {
    unsigned int num_on_ones = 0;
    while (n) {
        num_on_ones += n&0x1;
        n >>= 1;
    }
    return num_on_ones;
}

unsigned int get_biggest_unsigned_int(unsigned int n) {
    unsigned int num_of_ones = get_number_of_ones(n);

    if (num_of_ones == 0 || num_of_ones == 1) {
        return num_of_ones;
    }

    return (~0 << (sizeof(int)*BITS_IN_BYTE-num_of_ones+1))|0x1;
}
int main() {
    printf("%x\n", get_biggest_unsigned_int(15));
    return 0;
}
