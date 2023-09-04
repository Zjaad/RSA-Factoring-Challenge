#include <stdio.h>
#include <stdlib.h>
#include "factorize.h"

void factorize(int nb) {
    int factors[100];
    int cnt = 0;
    int x = 2;
    
    while (x * x <= nb) {
        while (nb % x == 0) {
            factors[cnt++] = x;
            nb /= x;
        }
        x++;
    }
    
    if (nb > 1) {
        factors[cnt++] = nb;
    }
    
    for (int y = 0; y < cnt - 1; y++) {
        printf("%d*", factors[y]);
    }
    
    printf("%d\n", factors[cnt - 1]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./factorize <file>\n");
        return 1;
    }

    char *input_filename = argv[1];
    FILE *file = fopen(input_filename, "r");

    if (file == NULL) {
        printf("Error: Can't open file '%s'\n", input_filename);
        return 1;
    }

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        int nb = atoi(line);
        factorize(nb);
    }

    fclose(file);
    return 0;
}
