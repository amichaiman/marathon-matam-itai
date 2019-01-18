#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void wc(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "ERROR: failed to open file");
        exit(2);
    }
    int lines=0, words=0, chars=0;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
        if (c == ' ') {
            words++;
        } else if (c == '\n') {
            lines++;
            words++;
        }
        chars++;
    }
    printf("lines: %d, words: %d, chars: %d\n", lines, words, chars);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: ./<executable> <filename>");
        exit(1);
    }
    wc(argv[1]);
    return 0;
}
