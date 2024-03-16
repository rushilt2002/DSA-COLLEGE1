#include <stdio.h>

int main() {
    int limit, a = 0, b = 1, nextTerm;

    FILE *inputFile;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    if (fscanf(inputFile, "%d", &limit) != 1) {
        printf("Error reading limit from input file!\n");
        fclose(inputFile);
        return 1;
    }

    fclose(inputFile);

    FILE *outputFile;
    outputFile = fopen("fibonacci_series.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    fprintf(outputFile, "Fibonacci Series up to %d terms:\n", limit);

    for (int i = 1; i <= limit; ++i) {
        fprintf(outputFile, "%d, ", a);
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }

    fclose(outputFile);

    printf("Fibonacci series up to %d terms has been written to 'fibonacci_series.txt'\n", limit);

    return 0;
}

