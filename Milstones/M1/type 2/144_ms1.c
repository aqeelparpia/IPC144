/*
 Name: AQEEL PARPIA
 Student number: 127921161
 Email: aparpia@mysenenca.ca
 Milestone: 1
 Section: MM
 Date: 15 March 2017
 */




#include <stdio.h>
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
void GroceryInventorySystem(void);
int menu(void);


// code your functions here:

void welcome (void)
{
    printf("---=== Grocery Inventory System ===---\n");
    printf("\n");
        
}
    

void printTitle(void)
{
    printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
    printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double gTotal)
{
    printf("--------------------------------------------------------+----------------\n");
    
    if(gTotal > 0)
    {
        printf("                                           Grand Total: |%12.2lf\n",gTotal);
    }
    
}



void flushKeyboard(void)
{
    char keyboard;
    do
    {
        scanf("%c",&keyboard);
        
    }while(keyboard != '\n');
}

void pause(void)
{
    printf("Press <ENTER> to continue...");
    flushKeyboard();
}

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
}

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
}

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
    
}

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
    
}


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
    
}

int menu(void)
{
    int numb;
    int min = 0;
    int max = 7;
    printf("1- List all items\n");
    printf("2- Search by SKU\n");
    printf("3- Checkout an item\n");
    printf("4- Stock an item\n");
    printf("5- Add new item or update item\n");
    printf("6- delete item\n");
    printf("7- Search by name\n");
    printf("0- Exit program\n");
    printf("> ");
    numb = getIntLimited(min, max);
    return numb;
}

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


