#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rsa.h"

void checkFactor(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: ./rsa <file>\n");
        exit(1);
    }

    char *args[3];
    int cnt = 0;
    int nb2 = 1;

    for (int x = 1; x <= 3; x++) {
        args[cnt++] = argv[x];
    }

    if (strcmp(args[0], args[1]) == 0) {
        nb2 = atoi(args[2]);
    }

    int nb1 = atoi(args[1]);
    int rst = (nb2 > nb1) ? 1 : 0;

    if (rst == 1) {
        int nbcp = nb1;
        nb1 = nb2;
        nb2 = nbcp;
    }

    printf("%s=%s*%s\n", args[0], args[1], args[2]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./rsa <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file '%s'\n", argv[1]);
        return 1;
    }

    char li[100];

    while (fgets(li, sizeof(li), file)) {
        li[strcspn(li, "\n")] = '\0';  // Remove newline character
        checkFactor(4, (char *[]){argv[0], "factor", li});
    }

    fclose(file);
    return 0;
}
