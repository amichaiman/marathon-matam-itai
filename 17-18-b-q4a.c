#include <stdio.h>

int is_permutation(char *s1, char *s2) {
    char difference[26] = {0};
    int i;
    while (*s1) {
        difference[*(s1++)]++;
    }
    while (*s2) {
        difference[*(s2++)]--;
    }

    for (i=0; i<26; i++) {
        if (difference[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("it is%s a permutation\n", is_permutation("hello", "olleh") ? "" : "n't");
    return 0;
}
