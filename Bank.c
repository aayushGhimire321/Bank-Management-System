#include <stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_CUSTOMERS 100


//Structure to represent a customer
struct Customer {
    char name[50];
    int accountNumber;
    float balance;
};

// Array to store customers
struct Customer customers[MAX_CUSTOMERS];
int numCustomers = 0;


//Function prototypes 
void addCustomer();
void displayCustomer();
void deposit();
void withdraw();


// Function to add a new customer
void addCustomer() {
    if (numCustomers < MAX_CUSTOMERS) {
        printf("Enter customer name: ");
        scanf("%s", customers[numCustomers].name);
        printf("Enter account number: ");
        scanf("%d", &customers[numCustomers].accountNumber);
        printf("Enter initial balance: ");
        scanf("%f", &customers[numCustomers].balance);
        numCustomers++;
    } else {
        printf("Maximum number of customers reached.\n");
    }
}

// Function to display customer details
void displayCustomer() {
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    int found = 0;
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accNum) {
            printf("Customer Name: %s\n", customers[i].name);
            printf("Account Number: %d\n", customers[i].accountNumber);
            printf("Balance: %.2f\n", customers[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Customer with account number %d not found.\n", accNum);
    }
}

// Function to deposit funds
void deposit() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    int found = 0;
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            customers[i].balance += amount;
            printf("Amount deposited successfully.\n");
            printf("Updated balance: %.2f\n", customers[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Customer with account number %d not found.\n", accNum);
    }
}

// Function to withdraw funds
void withdraw() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    int found = 0;
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                printf("Amount withdrawn successfully.\n");
                printf("Updated balance: %.2f\n", customers[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Customer with account number %d not found.\n", accNum);
    }
}
int main() {
    int choice;
    do {
        printf("\nBank Management System\n");
        printf("1. Add Customer\n");
        printf("2. Display Customer\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                displayCustomer();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
