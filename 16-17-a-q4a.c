#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int similar_lower_case_characters(char c1, char c2) {
    return tolower(c1) == tolower(c2);
}

int similar(char *s1, char *s2, int(*are_similar)(char, char)){
    while (*s1 || *s2) {
        if (isspace(*s1)) {
            s1++;
        } else if (isspace(*s2)) {
            s2++;
        } else if (!(*s1) || !(*s2) || !are_similar(*s1++, *s2++)) {
            return FALSE;
        }
    }
    return TRUE;
}
int main() {
    char *s1 = "Mary had a little lamb";
    char *s2 = "MARY    HAD   A   LITTLE   LAMB";

    printf("the strings are%s similar!\n", similar(s1, s2, similar_lower_case_characters) ? "" : "n't");
    return 0;
}