#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// Function to calculate the area of a triangle
float triangleArea(float base, float height) {
    return 0.5 * base * height;
}

// Function to calculate the area of a circle
float circleArea(float radius) {
    return PI * radius * radius;
}

// Function to calculate the area of a rectangle
float rectangleArea(float length, float width) {
    return length * width;
}

int main() {
    FILE *inputFile, *outputFile;
    int choice;
    float area;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        fclose(inputFile);
        return 1;
    }

    // Read choice from input file
    fscanf(inputFile, "%d", &choice);

    switch (choice) {
        case 1: // Triangle
            {
                float base, height;
                // Read base and height from input file
                fscanf(inputFile, "%f %f", &base, &height);
                area = triangleArea(base, height);
                fprintf(outputFile, "Area of the triangle: %.2f\n", area);
                break;
            }
        case 2: // Circle
            {
                float radius;
                // Read radius from input file
                fscanf(inputFile, "%f", &radius);
                area = circleArea(radius);
                fprintf(outputFile, "Area of the circle: %.2f\n", area);
                break;
            }
        case 3: // Rectangle
            {
                float length, width;
                // Read length and width from input file
                fscanf(inputFile, "%f %f", &length, &width);
                area = rectangleArea(length, width);
                fprintf(outputFile, "Area of the rectangle: %.2f\n", area);
                break;
            }
        default:
            fprintf(outputFile, "Invalid choice!\n");
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

