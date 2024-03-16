#include <stdio.h>

int reverseNumber(int number) {
    int reversedNumber = 0, remainder;

    while (number != 0) {
        remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number /= 10;
    }

    return reversedNumber;
}

int main() {
    int number, reversedNumber;
    FILE *inputFile, *outputFile;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    if (fscanf(inputFile, "%d", &number) != 1) {
        printf("Error reading number from input file!\n");
        fclose(inputFile);
        return 1;
    }

    fclose(inputFile);

    reversedNumber = reverseNumber(number);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    fprintf(outputFile, "Reversed number: %d\n", reversedNumber);

    fclose(outputFile);

    printf("Reversed number has been written to 'output.txt'\n");

    return 0;
}

