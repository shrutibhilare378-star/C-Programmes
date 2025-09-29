#include <stdio.h>

#define MAX 10

// Function Prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    while (1) {
        printf("\n=== Matrix Operations Menu ===\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of rows and columns: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter elements of first matrix:\n");
                inputMatrix(a, r1, c1);

                printf("Enter elements of second matrix:\n");
                inputMatrix(b, r1, c1);

                addMatrix(a, b, result, r1, c1);

                printf("Result (Addition):\n");
                printMatrix(result, r1, c1);
                break;

            case 2:
                printf("Enter number of rows and columns: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter elements of first matrix:\n");
                inputMatrix(a, r1, c1);

                printf("Enter elements of second matrix:\n");
                inputMatrix(b, r1, c1);

                subtractMatrix(a, b, result, r1, c1);

                printf("Result (Subtraction):\n");
                printMatrix(result, r1, c1);
                break;

            case 3:
                printf("Enter rows and columns of first matrix: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter rows and columns of second matrix: ");
                scanf("%d%d", &r2, &c2);

                if (c1 != r2) {
                    printf("Error: Matrix multiplication not possible!\n");
                    break;
                }

                printf("Enter elements of first matrix:\n");
                inputMatrix(a, r1, c1);

                printf("Enter elements of second matrix:\n");
                inputMatrix(b, r2, c2);

                multiplyMatrix(a, b, result, r1, c1, c2);

                printf("Result (Multiplication):\n");
                printMatrix(result, r1, c2);
                break;

            case 4:
                printf("Enter number of rows and columns: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter matrix elements:\n");
                inputMatrix(a, r1, c1);

                transposeMatrix(a, result, r1, c1);

                printf("Transpose of the matrix:\n");
                printMatrix(result, c1, r1);
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
