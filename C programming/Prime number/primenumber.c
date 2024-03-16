#include<stdio.h>
#include<math.h>
#include<string.h>

int isprime(int n) {
    int i;
    if (n <= 1)
        return 0;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    FILE *input, *output;
    char a[100];

    input = fopen("openfile.txt", "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }
    fscanf(input, "%d", &n);
    fclose(input);

    if (isprime(n))
        strcpy(a, "Is prime");
    else
        strcpy(a, "Is not prime");

    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error opening output file");
        return 1;
    }
    fprintf(output, "%s", a);
    fclose(output);

    return 0;
}
