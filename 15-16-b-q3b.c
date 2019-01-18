#include <stdio.h>

typedef enum {false, true} bool;

bool is_bigger(void* a, void* b) {
    return (long)a > (long)b ? true : false;
}

void generic_bubble_sort(void** array, int size, bool(*is_bigger)(void*, void*)) {
    int i, j;
    void* temp;
    for (i=size; i>1; i--) {
        for (j=0; j<i-1; j++) {
            if (is_bigger(array[j], array[j+1])) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void print_array(long *arr, int size) {
    int i;
    for (i=0; i<size; i++) {
        printf("%ld\t", arr[i]);
    }
    putchar('\n');
}

int main() {
    long arr[] = {1,6,3,3,2,6,8,4,3};

    print_array(arr, sizeof(arr)/ sizeof(*arr));
    generic_bubble_sort((void **) arr, sizeof( arr) / sizeof(*arr), is_bigger);
    print_array(arr, sizeof(arr)/ sizeof(*arr));

    return 0;
}