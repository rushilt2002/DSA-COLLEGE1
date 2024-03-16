#include <stdio.h>
#include <string.h>

// Function to concatenate two strings
void concatenateStrings(char result[], const char str1[], const char str2[]) {
    strcpy(result, str1);
    strcat(result, str2);
}

// Function to copy a string
void copyString(char destination[], const char source[]) {
    strcpy(destination, source);
}

// Function to compare two strings
int compareStrings(const char str1[], const char str2[]) {
    return strcmp(str1, str2);
}

int main() {
    FILE *inputFile, *outputFile;
    char str1[100], str2[100], result[200];

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read strings from input file
    fscanf(inputFile, "%s %s", str1, str2);

    // Close input file
    fclose(inputFile);

    // Concatenate strings
    concatenateStrings(result, str1, str2);

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write concatenated string to output file
    fprintf(outputFile, "Concatenated string: %s\n", result);

    // Copy string
    copyString(result, str1);
    fprintf(outputFile, "Copied string: %s\n", result);

    // Compare strings
    int comparison = compareStrings(str1, str2);
    if (comparison == 0) {
        fprintf(outputFile, "Strings are equal.\n");
    } else if (comparison < 0) {
        fprintf(outputFile, "%s comes before %s.\n", str1, str2);
    } else {
        fprintf(outputFile, "%s comes after %s.\n", str1, str2);
    }

    // Close output file
    fclose(outputFile);

    printf("Results have been written to 'output.txt'\n");

    return 0;
}

