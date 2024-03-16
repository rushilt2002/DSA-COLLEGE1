 #include <stdio.h>

int main() {
    char ch;
    int a, b, c;
    FILE *input;

    input = fopen("simplecal.txt", "r");
    if (input == NULL) {
        perror("Error in opening file");
        return 1;
    }

    while (1) {
        if (fscanf(input, "%d", &a) != 1) {
            printf("Error reading operand a from file\n");
            break;
        }

        if (fscanf(input, "%d", &b) != 1) {
            printf("Error reading operand b from file\n");
            break;
        }

        if (fscanf(input, " %c", &ch) != 1) {
            printf("Error reading operator from file\n");
            break;
        }

        switch (ch) {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                if (b != 0) {
                    c = a / b;
                } else {
                    printf("Error: Division by zero\n");
                    continue;
                }
                break;
            default:
                printf("Error: Invalid operator\n");
                continue;
        }

        printf("Answer: %d\n", c);

        // Check for end of file
        if (feof(input)) {
            break;
        }
    }

    fclose(input);

    return 0;
}
