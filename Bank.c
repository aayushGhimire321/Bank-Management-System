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


