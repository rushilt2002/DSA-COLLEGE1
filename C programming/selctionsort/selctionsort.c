#include <stdio.h>

// Function to perform selection sort on an array
void selectionSort(int arr[], int size) {
    int i, j, minIndex, temp;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[minIndex] with arr[i]
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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

    // Perform selection sort on the array
    selectionSort(arr, size);

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
