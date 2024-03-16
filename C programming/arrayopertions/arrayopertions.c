#include <stdio.h>

// Function to find the largest element in the array
int findLargest(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the smallest element in the array
int findSmallest(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the sum of elements in the array
int findSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the average of elements in the array
float findAverage(int arr[], int size) {
    int sum = findSum(arr, size);
    return (float) sum / size;
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

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Find largest element and write to output file
    int largest = findLargest(arr, size);
    fprintf(outputFile, "Largest element in the array: %d\n", largest);

    // Find smallest element and write to output file
    int smallest = findSmallest(arr, size);
    fprintf(outputFile, "Smallest element in the array: %d\n", smallest);

    // Find sum of elements and write to output file
    int sum = findSum(arr, size);
    fprintf(outputFile, "Sum of elements in the array: %d\n", sum);

    // Find average of elements and write to output file
    float average = findAverage(arr, size);
    fprintf(outputFile, "Average of elements in the array: %.2f\n", average);

    // Close output file
    fclose(outputFile);

    printf("Results have been written to 'output.txt'\n");

    return 0;
}

