/*
 Name: Aqeel Parpia
 Student number:127921161
 Email:aparpia@matrix.senecac.on.ca
 Workshop: w8 lab
 Section: MM
 Date: 23/03/2017
 */


#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

#define MAX_TITLE_SIZE 20

#define MAX_BOOKS 10

struct Book {
    int _isbn;
    float _price;
    int _year;
    char _title[MAX_TITLE_SIZE + 1];
    int _qty;
};

void menu();
void displayInventory(const struct Book book[], const int size);
void searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);


int main(void)
{
    struct Book book[MAX_BOOKS];
    int size = 0;
    int option;
    
    printf("Welcome to the Book Store\n");
    printf("=========================\n");
    
    
    do {
        menu();
	printf("Select: ");
        scanf("%d", &option);
        
        switch (option) {
            case 0:
                printf("Goodbye!\n");
                break;
            case 1:
                displayInventory(book, size);
                break;
            case 2:
                addBook(book, &size);
                break;
            case 3:
                checkPrice(book, size);
                break;
            default:
                printf("Invalid input, try again:\n");
        }
    } while (option != 0);
    
    return 0;
}

void menu() {
    printf("Please select from the following options:\n");
    printf("1) Display the inventory.\n");
    printf("2) Add a book to the inventory.\n");
    printf("3) Check price.\n");
    printf("0) Exit.\n\n");
}


void displayInventory(const struct Book book[], const int size) {
    
    int i;
    if ((size) == 0) {
        
        printf("The inventory is empty!\n");
        printf("===================================================\n\n");
        
    }
    
    else {
        printf("\n\n");
        printf("Inventory\n");
        printf("===================================================\n");
        printf("ISBN      Title               Year Price  Quantity\n");
        printf("---------+-------------------+----+-------+--------\n");
        for (i = 0; i < size; i++)
            printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
        printf("===================================================\n\n");
    }
}

void addBook(struct Book book[], int *size)
{
    
    if (*size == MAX_BOOKS) {
        printf("the inventoryis full\n");
    }
    
    else {
        printf("ISBN:");
        scanf("%d", &book[*size]._isbn);
        
        printf("Title:");
        scanf("%*c%[^\n]", book[*size]._title);
        
        printf("Year:");
        scanf("%d", &book[*size]._year);
        
        printf("Price:");
        scanf("%f", &book[*size]._price);
        
        printf("Quantity:");
        scanf("%d", &book[*size]._qty);
        
        printf("The book is successfully added to the inventory.\n\n");
        *size = *size + 1;
    }
    
}


void searchInventory(const struct Book book[], const int isbn, const int size)
{
    printf("Not implemented\n");
}


void checkPrice(const struct Book book[], const int size)
{
    printf("Not implemented\n");
}
