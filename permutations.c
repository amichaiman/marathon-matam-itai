#include <stdio.h>
#include <string.h>

void swap(char* p1, char* p2) {
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
// "hello"
//  0  1  2  3  4  5
// [h][e][l][l][o][0]
void print_permutations(char *str, int l, int r) {
    int i;
    if (l >= r) {
        puts(str);
        return;
    }
    for (i=l+1; i<r; i++) {
        swap(str+i, str+l); //switch between l and i
        print_permutations(str, l+1, r);
        swap(str+i, str+l);
    }
}
int main() {
    char s[] = "hello";
    print_permutations(s, 0, (int) strlen(s));
    return 0;
}
