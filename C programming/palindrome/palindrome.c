#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindromeNumber(int number) {
    int reversedNumber = 0, originalNumber = number;

    while (number != 0) {
        int remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number /= 10;
    }

    return originalNumber == reversedNumber;
}

bool isPalindromeString(char *str) {
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; ++i, --j) {
        if (str[i] != str[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    FILE *inputFile, *outputFile;
    char input[100];
    int number;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read input from file
    if (fscanf(inputFile, "%s", input) != 1) {
        printf("Error reading input from file!\n");
        fclose(inputFile);
        return 1;
    }

    fclose(inputFile);

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Check if input is a number or a string
    if (sscanf(input, "%d", &number) == 1) {
        // Input is a number
        if (isPalindromeNumber(number)) {
            printf("%d is a palindrome number.\n", number);
            fprintf(outputFile, "%d is a palindrome number.\n", number);
        } else {
            printf("%d is not a palindrome number.\n", number);
            fprintf(outputFile, "%d is not a palindrome number.\n", number);
        }
    } else {
        // Input is a string
        if (isPalindromeString(input)) {
            printf("%s is a palindrome string.\n", input);
            fprintf(outputFile, "%s is a palindrome string.\n", input);
        } else {
            printf("%s is not a palindrome string.\n", input);
            fprintf(outputFile, "%s is not a palindrome string.\n", input);
        }
    }

    fclose(outputFile);
    printf("Result has been written to 'output.txt'\n");

    return 0;
}

