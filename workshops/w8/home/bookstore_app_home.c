/*
 Name: Aqeel Parpia
 Student number:127921161
 Email:aparpia@matrix.senecac.on.ca
 Workshop: w8 home
 Section: MM
 Date: 28/03/2017
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
int searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);


int main(void)
{
    struct Book book[MAX_BOOKS]={{0}};
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
                checkPrice(book, MAX_BOOKS);
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


int searchInventory(const struct Book book[], const int isbn, const int size)
{
    int i;
    int found = -1;
    
    for (i = 0; i < size && found < 0; i++) {
        if (book[i]._isbn == isbn)
        {
            found = i;
        }
    }
    
    return found;
}


void addBook(struct Book book[], int *size)
{
    int Quantity;
    
    printf("ISBN:");
    scanf("%d", &book[*size]._isbn);
    while (getchar() != '\n');
    
    printf("Quantity:");
    scanf("%d", &book[*size]._qty);
    while (getchar() != '\n');
    
    if ((Quantity = searchInventory(book , book[*size]._isbn, *size)) != -1){
        book[Quantity]._qty=book[Quantity]._qty + book[*size]._qty;
        printf("The book exists in the repository, quantity is updated.\n\n");
    }
    
    else {
        
        if (*size == MAX_BOOKS) {
            printf("the inventoryis full\n");
        }
        
        else {
            
            printf("Title:");
            scanf("%20[^\n]", book[*size]._title);
            while (getchar() !='\n');
            printf("Year:");
            scanf("%d", &book[*size]._year);
            
            printf("Price:");
            scanf("%f", &book[*size]._price);
            
            printf("The book is successfully added to the inventory.\n\n");
            *size = *size + 1;
        }
        
    }
}


void checkPrice(const struct Book book[], const int size)
{
    int isbn;
    int tracker;
    
    printf("Please input the ISBN number of the book:\n\n");
    scanf("%d", &isbn);
    
    tracker = searchInventory(book, isbn, size);
    
    if (tracker == -1){
        printf("Book does not exist in the bookstore! Please try again.\n\n");
    }
    else {
        printf("Book %d costs $%.2lf\n\n", isbn, book[tracker]._price);
    }
}


