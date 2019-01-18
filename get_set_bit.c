#include <stdio.h>

unsigned int get_bit(unsigned int n, unsigned int index) {
    return n >> index & 0x1;
}

unsigned int set_bit(unsigned int n, unsigned int index, unsigned int new_val) {
    unsigned int mask = (unsigned int) (1 << index);
    return new_val == 1 ? n|mask : n&(~mask);
}
