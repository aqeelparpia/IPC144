/*
 Name: AQEEL PARPIA
 Student number: 127921161
 Email: aparpia@mysenenca.ca
 Milestone: 2
 Section: MM
 Date: 24 March 2017
 */



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define statements:

#define LINEAR 1
#define FORM 0

// Constant TAX value:

const double TAX = 0.13;


// Function Prototypes Milestone 1:

// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);

// app interface
int yes(void);
int menu(void);
void GroceryInventorySystem(void);

struct Item {
    double price;
    int sku;
    int isTaxed;
    int quantity;
    int minQuantity;
    char name[21];
};

//void GroceryInventorySystem(void);
//int menu(void);


// Function Prototypes Milesone 2:

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int  sku);
void displayItem(struct Item item,int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);


// Function Implementations Milestone 1:

void welcome(void)
{
    printf("---=== Grocery Inventory System ===---\n");
    printf("\n");
    
};


void printTitle(void)
{
    printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
    printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
};

void printFooter(double gTotal)
{
    printf("--------------------------------------------------------+----------------\n");
    
    if(gTotal > 0)
    {
        printf("                                           Grand Total: |%12.2lf\n",gTotal);
    }
    
};


void flushKeyboard(void)
{
    char keyboard;
    do
    {
        scanf("%c",&keyboard);
        
    }while(keyboard != '\n');
    
};

void pause(void)
{
    printf("Press <ENTER> to continue...");
    flushKeyboard();
};

int getInt(void)
{
    int value;
    char NL = 'x';
    
    while(NL != '\n')
    {
        scanf("%d%c",&value, &NL);
        if (NL != '\n')
        {
            flushKeyboard();
            printf("Invalid integer, please try again: ");
        }
    } return value;
};

int getIntLimited(int lowerLimit,int upperLimit)
{
    int value;
    
    do {
        value = getInt();
        if(lowerLimit > value || upperLimit < value )
        {
            printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
            
        }
    }while ( lowerLimit > value || upperLimit < value);
    return value;
};

double getDouble(void)
{
    double value;
    char NL = 'x';
    
    while(NL != '\n')
    {
        scanf("%lf%c",&value, &NL);
        if (NL != '\n')
        {
            flushKeyboard();
            printf("Invalid number, please try again: ");
        }
    } return value;
    
};

double getDoubleLimited(double lowerLimit,double upperLimit)
{
    double value;
    
    do
    {
        value = getDouble();
        if(lowerLimit > value || upperLimit < value )
        {
            printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
            
        }
    }while ( lowerLimit > value || upperLimit < value);
    return value;
    
};

int yes(void)
{
    char input;
    int ret = 0;
    
    do
    {
        scanf("%c", &input);
        flushKeyboard();
        if ( input != 'Y' && input != 'y' && input != 'N' && input != 'n')
        {
            printf("Only (Y)es or (N)o are acceptable: ");
        }
    } while (input != 'Y' && input != 'y' && input != 'N' && input != 'n');
    if (input == 'y' || input == 'Y')
    {
        ret = 1;
    }
    return ret;
    
};

int menu(void)
{
    int no;
    int low = 0;
    int high = 7;
    printf("1- List all items\n");
    printf("2- Search by SKU\n");
    printf("3- Checkout an item\n");
    printf("4- Stock an item\n");
    printf("5- Add new item or update item\n");
    printf("6- delete item\n");
    printf("7- Search by name\n");
    printf("0- Exit program\n");
    printf("> ");
    no = getIntLimited(low, high);
    return no;
};

void GroceryInventorySystem(void) { //Option for user selection
    int option, flag = 0;
    welcome();
    
    do {
        option = menu();
        switch (option) {
            case 0:
                printf("Exit the program? (Y)es/(N)o: ");
                flag = yes();
                break;
                
            case 1:
                printf("List Items under construction!\n");
                pause();
                break;
                
            case 2:
                printf("Search Items under construction!\n");
                pause();
                break;
                
            case 3:
                printf("Checkout Item under construction!\n");
                pause();
                break;
                
            case 4:
                printf("Stock Item under construction!\n");
                pause();
                break;
                
            case 5:
                printf("Add/Update Item under construction!\n");
                pause();
                break;
                
            case 6:
                printf("Delete Item under construction!\n");
                pause();
                break;
                
            case 7:
                printf("Search by name under construction!\n");
                pause();
                break;
        }
    } while (flag == 0);
}



// Function Implementations Milestone 2:


double totalAfterTax(struct Item item )
{
    
    double amount = 0;
    amount = (item.price * item.quantity);
    
    if (item.isTaxed>0){
        amount = amount + (amount * TAX);
    }
    
    return amount;
};



int isLowQuantity(struct Item item){
    
    int min_item;
    if (item.quantity < item.minQuantity)
    {
        min_item = 1;
    }
    else
    {
        min_item = 0;
    }
    
    return min_item;
};


struct Item itemEntry(int sku) {
    struct Item items;
    printf("        SKU: %d\n", sku);
    items.sku = sku;
    
    printf("       Name: ");
    scanf(" %20[^\n]", items.name);
    flushKeyboard();
    
    printf("      Price: ");
    items.price = getDouble();
    
    printf("   Quantity: ");
    items.quantity = getInt();
    
    printf("Minimum Qty: ");
    items.minQuantity = getInt();
    
    printf("   Is Taxed: ");
    items.isTaxed = yes();
    
    return items;
};

void displayItem(struct Item item, int linear){
    
    
    char iTax1[4] = "Yes";
    char iTax2[4] = "No";
    if (linear == LINEAR) {
        printf("|");
        printf("%3d", item.sku);
        printf("|");
        printf("%-20s", item.name);
        printf("|");
        printf("%8.2lf", item.price);
        printf("|  ");
        if (item.isTaxed == 1) {
            printf("%3s", iTax1);
        }
        else {
            printf("%3s", iTax2);
        }
        printf("| ");
        printf("%3d", item.quantity);
        printf(" | ");
        printf("%3d", item.minQuantity);
        printf(" |");
        printf("%12.2lf", totalAfterTax(item));
        printf("|");
        if (isLowQuantity(item) == 1) {
            printf("***");
        }
        printf("\n");
    }
    
    else {
        printf("        SKU: %d\n", item.sku);
        printf("       Name: %s\n", item.name);
        printf("      Price: %.2lf\n", item.price);
        printf("   Quantity: %d\n", item.quantity);
        printf("Minimum Qty: %d\n", item.minQuantity);
        if (item.isTaxed == 1) {
            printf("   Is Taxed: %s\n", iTax1);
        }
        else {
            printf("   Is Taxed: %s\n", iTax2);
        }
        if (isLowQuantity(item) == 1) {
            printf("WARNING: Quantity low, please order ASAP!!!\n");
        }
    }
}
void listItems(const struct Item item[], int noOfItems){
    int i = 0;
    double grand = 0;
    
    printTitle();
    for (i = 0;  i < noOfItems; i++)
    {
        printf("%-4d", (i + 1));
        displayItem(item[i], LINEAR);
        grand += totalAfterTax(item[i]);
    }
    printFooter(grand);
};

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index){
    int i;
    int flag = 0;
    
    for (i = 0; i < NoOfRecs && !flag; i++) {
        if (item[i].sku == sku)
        {
            *index = i;
            flag= 1;
        }
    }
    
    return flag;
};





















