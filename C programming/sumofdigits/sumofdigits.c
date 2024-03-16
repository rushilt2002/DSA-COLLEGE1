#include <stdio.h>

int main() {
    int number, sum = 0, digit;

    // Open input file
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read number from input file
    if (fscanf(inputFile, "%d", &number) != 1) {
        printf("Error reading number from input file!\n");
        fclose(inputFile);
        return 1;
    }

    // Close input file
    fclose(inputFile);

    // Iterate through each digit of the number
    while (number != 0) {
        // Extract the last digit
        digit = number % 10;
        // Add the digit to the sum
        sum += digit;
        // Remove the last digit from the number
        number /= 10;
    }

    // Open output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Print the sum of digits to the output file
    fprintf(outputFile, "Sum of digits: %d\n", sum);

    // Close output file
    fclose(outputFile);

    return 0;
}

