#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "accounts.dat"

typedef struct {
    int acc_no;
    char name[50];
    float balance;
} Account;

// Function Prototypes
void create_account();
void deposit();
void withdraw();
void display_account();
void menu();

int main() {
    menu();
    return 0;
}

// Display menu
void menu() {
    int choice;
    while (1) {
        printf("\n=== Bank Management System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_account(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: display_account(); break;
            case 5: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
}

// Create a new account
void create_account() {
    Account acc;
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter name: ");
    scanf(" %[^\n]", acc.name);
    printf("Enter initial balance: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);

    printf("Account created successfully.\n");
}

// Deposit to an account
void deposit() {
    int acc_no, found = 0;
    float amount;
    Account acc;

    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter account number to deposit into: ");
    scanf("%d", &acc_no);

    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            acc.balance += amount;

            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, fp);
            printf("Deposit successful. New balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

// Withdraw from an account
void withdraw() {
    int acc_no, found = 0;
    float amount;
    Account acc;

    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter account number to withdraw from: ");
    scanf("%d", &acc_no);

    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (acc.balance >= amount) {
                acc.balance -= amount;
                fseek(fp, -sizeof(Account), SEEK_CUR);
                fwrite(&acc, sizeof(Account), 1, fp);
                printf("Withdrawal successful. New balance: %.2f\n", acc.balance);
            } else {
                printf("Insufficient balance.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

// Display account details
void display_account() {
    int acc_no, found = 0;
    Account acc;

    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter account number to display: ");
    scanf("%d", &acc_no);

    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("\n=== Account Details ===\n");
            printf("Account No: %d\n", acc.acc_no);
            printf("Name      : %s\n", acc.name);
            printf("Balance   : %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}
