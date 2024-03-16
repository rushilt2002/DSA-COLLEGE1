#include <stdio.h>

int main() {
    FILE *file;

    // Open a file named "output.txt" for writing
    file = fopen("output.txt", "w");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1; // Return 1 to indicate failure
    }

    // Write "hello world" to the file
    fprintf(file, "hello world\n");

    // Close the file
    fclose(file);

    return 0; // Return 0 to indicate success
}
