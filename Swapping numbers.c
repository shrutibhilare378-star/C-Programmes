#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void array_traversal();
void swap_numbers(int *a, int *b);
void string_manipulation();

int main() {
    int choice;

    while (1) {
        printf("\n=== Pointer Operations Menu ===\n");
        printf("1. Array Traversal using Pointers\n");
        printf("2. Swap Numbers using Pointers\n");
        printf("3. Dynamic String Manipulation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                array_traversal();
                break;

            case 2: {
                int x, y;
                printf("Enter two numbers: ");
                scanf("%d %d", &x, &y);
                printf("Before swap: x = %d, y = %d\n", x, y);
                swap_numbers(&x, &y);
                printf("After swap: x = %d, y = %d\n", x, y);
                break;
            }

            case 3:
                string_manipulation();
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
