#include <stdio.h>

// Function to perform insertion sort on an array
void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key,
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int size;

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

    // Close input file
    fclose(inputFile);

    // Perform insertion sort on the array
    insertionSort(arr, size);

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write sorted array to output file
    for (int i = 0; i < size; ++i) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fprintf(outputFile, "\n");

    // Close output file
    fclose(outputFile);

    printf("Sorted array has been written to 'output.txt'\n");

    return 0;
}
