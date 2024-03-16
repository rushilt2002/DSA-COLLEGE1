#include <stdio.h>

// Function to read a matrix from a file
void readMatrix(FILE *file, int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
}

// Function to write a matrix to a file
void writeMatrix(FILE *file, int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}

// Function to perform matrix addition
void matrixAddition(int result[][100], int matrix1[][100], int matrix2[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to perform matrix subtraction
void matrixSubtraction(int result[][100], int matrix1[][100], int matrix2[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to perform matrix multiplication
void matrixMultiplication(int result[][100], int matrix1[][100], int rows1, int cols1, int matrix2[][100], int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to perform matrix transpose
void matrixTranspose(int result[][100], int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    FILE *inputFile1, *inputFile2, *outputFile;
    int rows1, cols1, rows2, cols2;

    // Open first input file
    inputFile1 = fopen("input1.txt", "r");
    if (inputFile1 == NULL) {
        printf("Error opening first input file!\n");
        return 1;
    }

    // Read dimensions of first matrix from first input file
    fscanf(inputFile1, "%d %d", &rows1, &cols1);

    // Allocate memory for first matrix
    int matrix1[100][100];

    // Read first matrix from first input file
    readMatrix(inputFile1, matrix1, rows1, cols1);

    // Close first input file
    fclose(inputFile1);

    // Open second input file
    inputFile2 = fopen("input2.txt", "r");
    if (inputFile2 == NULL) {
        printf("Error opening second input file!\n");
        return 1;
    }

    // Read dimensions of second matrix from second input file
    fscanf(inputFile2, "%d %d", &rows2, &cols2);

    // Allocate memory for second matrix
    int matrix2[100][100];

    // Read second matrix from second input file
    readMatrix(inputFile2, matrix2, rows2, cols2);

    // Close second input file
    fclose(inputFile2);

    // Check if matrices are compatible for addition, subtraction, and multiplication
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices are not compatible for addition, subtraction, and multiplication!\n");
        return 1;
    }

    // Perform matrix addition
    int additionResult[100][100];
    matrixAddition(additionResult, matrix1, matrix2, rows1, cols1);

    // Perform matrix subtraction
    int subtractionResult[100][100];
    matrixSubtraction(subtractionResult, matrix1, matrix2, rows1, cols1);

    // Perform matrix multiplication
    int multiplicationResult[100][100];
    matrixMultiplication(multiplicationResult, matrix1, rows1, cols1, matrix2, cols2);

    // Perform matrix transpose for the first matrix
    int transposeResult1[100][100];
    matrixTranspose(transposeResult1, matrix1, rows1, cols1);

    // Perform matrix transpose for the second matrix
    int transposeResult2[100][100];
    matrixTranspose(transposeResult2, matrix2, rows2, cols2);

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write results to output file
    fprintf(outputFile, "Matrix Addition:\n");
    writeMatrix(outputFile, additionResult, rows1, cols1);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Matrix Subtraction:\n");
    writeMatrix(outputFile, subtractionResult, rows1, cols1);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Matrix Multiplication:\n");
    writeMatrix(outputFile, multiplicationResult, rows1, cols2);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Transpose of First Matrix:\n");
    writeMatrix(outputFile, transposeResult1, cols1, rows1);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Transpose of Second Matrix:\n");
    writeMatrix(outputFile, transposeResult2, cols2, rows2);
    fprintf(outputFile, "\n");

    // Close output file
    fclose(outputFile);

    printf("Matrix operations result has been written to 'output.txt'\n");

    return 0;
}
