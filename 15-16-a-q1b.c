#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grep(char *filename, char *word) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "ERROR: failed to open file");
        exit(2);
    }
    char *line;
    size_t line_length=0;

    while (getline(&line, &line_length, fp) != -1) {
        if (strstr(line, word)) {
            puts(line);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "USAGE: ./<executable> <filename> <word>");
        exit(1);
    }
    grep(argv[1], argv[2]);
    return 0;
}
