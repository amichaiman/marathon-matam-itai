#include <stdio.h>

#define BITS_IN_BYTE 8

void cyclic_byte_array_left(unsigned char* array, unsigned int size, unsigned int n) {
    int i, j;
    unsigned int leftmost_bit_val;

    for (i=0; i<n; i++) {
        leftmost_bit_val = array[0]>>BITS_IN_BYTE-1;
        for (j=0; j<size; j++) {
            array[j] <<= 1;
            array[j] |= j == size-1 ? leftmost_bit_val : array[j+1]>>BITS_IN_BYTE-1 ;
        }
    }
}

void print_array(unsigned char *array, int size) {
    int i;
    for (i=0; i<size; i++) {
        printf("%d\t", array[i]);
    }
    putchar('\n');
}
int main() {
    unsigned char array[] = {0x1, 0x1};
    print_array(array, 2);
    cyclic_byte_array_left(array, 2, 9);
    print_array(array, 2);
    return 0;
}
