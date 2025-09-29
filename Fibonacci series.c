#include <stdio.h>

// Function Prototypes
int factorial(int n);
int fibonacci(int n);
int sum_of_digits(int n);

int main() {
    int choice, num, i;

    while (1) {
        printf("\n=== Recursive Function Menu ===\n");
        printf("1. Factorial\n");
        printf("2. Fibonacci Series\n");
        printf("3. Sum of Digits\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to calculate factorial: ");
                scanf("%d", &num);
                if (num < 0)
                    printf("Factorial not defined for negative numbers.\n");
                else
                    printf("Factorial of %d = %d\n", num, factorial(num));
                break;

            case 2:
                printf("Enter number of terms for Fibonacci series: ");
                scanf("%d", &num);
                printf("Fibonacci Series: ");
                for (i = 0; i < num; i++) {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                break;

            case 3:
                printf("Enter a number to find sum of its digits: ");
                scanf("%d", &num);
                if (num < 0) num = -num; // make it positive
                printf("Sum of digits = %d\n", sum_of_digits(num));
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
