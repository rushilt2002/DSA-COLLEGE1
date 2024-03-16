#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If key greater, ignore left half
        if (arr[mid] < key) {
            low = mid + 1;
        }
        // If key is smaller, ignore right half
        else {
            high = mid - 1;
        }
    }

    // Element not found
    return -1;
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

    // Perform binary search
    int index = binarySearch(arr, size, key);

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

