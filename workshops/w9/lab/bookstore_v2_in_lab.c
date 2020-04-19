//  -------------------------------------------------
//Name: Aqeel Parpia
//Student number:127921161
//Email:aparpia@matrix.senecac.on.ca
//Workshop: w9 lab
//Section: MM
//Date: 29/03/2017
//  -------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_TITLE_SIZE 21

//Type the struct here

struct Book {
    int _isbn;
    float _price;
    int _year;
    int _qty;
    char _title[MAX_TITLE_SIZE + 1];
};


//Type the function prototypes herevoid menu();

void menu();
int readRecord(FILE *fp, struct Book *b2read);
void displayInventory(const char filename[]);
float calculateCapital(const char filename[]);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);
void searchInventory(FILE *fp, const int isbn2find);


int main()
{
    //Type your code here:
    
    char filename[]= "inventory.txt";
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
                displayInventory(filename);
                break;
            case 2:
                //addBook();
                break;
            case 3:
                //checkPrice();
                break;
                
            case 4:
                calculateCapital(filename);
                printf("The total capital is: $%.2f.\n", calculateCapital(filename));
                break;
            default:
                printf("Invalid input, try again:\n");
        }
    } while (option != 0);
    
    return 0;
}


void menu()
{
    printf("Please select from the following options:\n");
    printf("1) Display the inventory.\n");
    printf("2) Add a book to the inventory.\n");
    printf("3) Check price.\n");
    printf("4) Calculate total capital of the store.\n");
    printf("0) Exit.\n\n");
}

void displayInventory(const char filename[])
{
    //Define an object of struct Book
    struct Book books;
    
    //Open the file, and check for null pointer
    FILE *fp = NULL;
    fp =fopen(filename,"r");
    if (fp !=NULL) {
        
        //If the file is properly opened, display headers, similar to workshop 8
        
        printf("\n\n");
        printf("Inventory\n");
        printf("===================================================\n");
        printf("ISBN      Title               Year Price  Quantity\n");
        printf("---------+-------------------+----+-------+--------\n");
        
        //Use a while loop to call readRecord and display the records.
        //while(/*call readRecord and check its return value*/)
        //display the record
        while (readRecord(fp,&books)==5){
            printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", books._isbn, books._title, books._year, books._price, books._qty);
        }
        printf("===================================================\n\n");  //Display the footer
    }
    
    fclose(fp);   //Close the file
}

float calculateCapital(const char filename[])
{
    
    
    //Define an object of struct Book
    struct Book books;
    
    //Define and initialize total_capital
    float total_capital = 0;
    
    //Open the file, and check for null pointer
    FILE *fp = NULL;
    fp = fopen(filename,"r");
    if (fp != NULL){
        while(readRecord(fp,&books)==5){
            total_capital=total_capital+books._price * books._qty;
        }
        
    }
    //Display the footer
    
    //Close the file
    fclose(fp);
    
    //return the total_capital
    return total_capital;
}

int readRecord(FILE *fp, struct Book *b2read)
{
    //Define a variable int rv = 0
    int rv=0;
    
    rv = fscanf(fp, "%d;%f;%d;%d;%21[^\n]", &b2read->_isbn, &b2read->_price, &b2read->_year, &b2read->_qty, b2read->_title);
    
    return rv;
}


void addBook(const char filename[], struct Book *b2Add)
{
    printf("Not implemented!\n");
}

void checkPrice(const char filename[],const int isbn2find)
{
    printf("Not implemented!\n");
}

void searchInventory(FILE *fp,const int isbn2find)
{
    printf("Not implemented!\n");
}


