#include <stdio.h>

void* max(void* a, void* b) {
    return (long)a > (long)b ? a : b;
}

void* find_max(void** array, int size, void*(*max)(void*, void*)) {
    void* biggest=array[0];
    int i;
    for (i=1; i<size; i++) {
        if (max(biggest, array[i]) == array[i]) {
            biggest = array[i];
        }
    }
    return biggest;
}

int main() {
    long array[] = {1,4,7,3,9,3,3,8,6};

    printf("The biggest element is: %ld\n", (long)find_max((void **) array, sizeof(array) / sizeof(*array), max));

    return 0;
}