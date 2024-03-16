#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; // Element found, return index
        }
    }
    return -1; // Element not found
}

int main() {
    FILE *inputFile, *outputFile;
    int size, key;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read array size from input file
    fscanf(inputFile, "%d", &size);

    // Read array elements from input file
    int arr[size];
    for (int i = 0; i < size; ++i) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    // Read the element to search from input file
    fscanf(inputFile, "%d", &key);

    // Close input file
    fclose(inputFile);

    // Perform linear search
    int index = linearSearch(arr, size, key);

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write result to output file
    if (index != -1) {
        fprintf(outputFile, "Element %d found at index %d.\n", key, index);
    } else {
        fprintf(outputFile, "Element %d not found in the array.\n", key);
    }

    // Close output file
    fclose(outputFile);

    printf("Search result has been written to 'output.txt'\n");

    return 0;
}

