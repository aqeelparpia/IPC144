/*
 Name: AQEEL PARPIA
 Student number: 127921161
 Email: aparpia@mysenenca.ca
 Milestone: 4fp
 Section: MM
 Date: 09 April 2017
 */

#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// Define statements:

#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define MAX_ITEM_NO 500
#define DATAFILE "items.txt"

// Constant TAX value:

const double TAX = 0.13;

struct Item
{
    double price;
    int sku;
    int isTaxed;
    int quantity;
    int minQuantity;
    char name[21];
};

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

// Function Prototypes Milesone 2:
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item,int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

// Function Prototypes Milesone 3:
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int* NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

// Function Prototypes Milestone 4
void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char fileName[], int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr);

//Main function for running this application
int main(void)
{
    GroceryInventorySystem();
    return 0;
}

// Function Implementations Milestone 1:

void welcome(void)
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
    
    if (gTotal > 0)
    {
        printf("                                           Grand Total: |%12.2lf\n", gTotal);
    }
    
}


void flushKeyboard(void)
{
    char keyboard;
    do
    {
        scanf("%c", &keyboard);
        
    } while (keyboard != '\n');
    
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
    
    while (NL != '\n')
    {
        scanf("%d%c", &value, &NL);
        if (NL != '\n')
        {
            flushKeyboard();
            printf("Invalid integer, please try again: ");
        }
    }
    return value;
}


int getIntLimited(int lowerLimit, int upperLimit)
{
    int value;
    
    do
    {
        value = getInt();
        if (lowerLimit > value || upperLimit < value)
        {
            printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
            
        }
    } while (lowerLimit > value || upperLimit < value);
    return value;
}


double getDouble(void)
{
    double value;
    char NL = 'x';
    
    while (NL != '\n')
    {
        scanf("%lf%c", &value, &NL);
        if (NL != '\n')
        {
            flushKeyboard();
            printf("Invalid number, please try again: ");
        }
    }
    return value;
}


double getDoubleLimited(double lowerLimit, double upperLimit)
{
    double value;
    
    do
    {
        value = getDouble();
        if (lowerLimit > value || upperLimit < value)
        {
            printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
            
        }
    } while (lowerLimit > value || upperLimit < value);
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
        if (input != 'Y' && input != 'y' && input != 'N' && input != 'n')
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
}


void GroceryInventorySystem(void){  //Option for user selection
    struct Item groceryitem[MAX_ITEM_NO];
    int records;
    int option, flag = 0;
    
    welcome();
    
    if (loadItems(groceryitem , DATAFILE , &records)==0) {
        printf("Could not read from %s.\n", DATAFILE);
    }
    
    do {
        option = menu();
        switch (option) {
            case 0:
                printf("Exit the program? (Y)es/(N)o): ");
                flag = yes();
                break;
                
            case 1:
                
                listItems(groceryitem, records);
                pause();
                break;
                
            case 2:
                search(groceryitem, records);
                pause();
                break;
                
            case 3:
                
                adjustQuantity(groceryitem, records, CHECKOUT);
                if (saveItems(groceryitem, DATAFILE, records) == 0)
                {
                    printf("Could not update data file %s\n", DATAFILE);
                }
                
                pause();
                break;
                
            case 4:
                adjustQuantity(groceryitem, records, STOCK);
                pause();
                break;
                
            case 5:
                addOrUpdateItem(groceryitem, &records);
                if (saveItems(groceryitem, DATAFILE, records) == 0)
                {
                    printf("Could not update data file %s\n", DATAFILE);
                }
                pause();
                break;
                
            case 6:
                printf("Not implemented!\n");
                pause();
                break;
                
            case 7:
                printf("Not implemented!\n");
                pause();
                break;
        }
    } while (flag == 0);
}


// Function Implementations Milestone 2:

double totalAfterTax(struct Item item )
{
    
    double amount = 0;
    amount = (item.price* item.quantity);
    
    if (item.isTaxed>0)
    {
        amount = amount + (amount* TAX);
    }
    
    return amount;
}


int isLowQuantity(struct Item item)
{
    
    int min_item;
    if (item.quantity <= item.minQuantity)
    {
        min_item = 1;
    }
    else
    {
        min_item = 0;
    }
    
    return min_item;
}


struct Item itemEntry(int sku)
{
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
}


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
        if (item.isTaxed == 1)
        {
            printf("%3s", iTax1);
        }
        else
        {
            printf("%3s", iTax2);
        }
        
        printf("| ");
        printf("%3d", item.quantity);
        printf(" | ");
        printf("%3d", item.minQuantity);
        printf(" |");
        printf("%12.2lf", totalAfterTax(item));
        printf("|");
        
        if (isLowQuantity(item) == 1)
        {
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
        
        if (item.isTaxed == 1)
        {
            printf("   Is Taxed: %s\n", iTax1);
        }
        
        else
        {
            printf("   Is Taxed: %s\n", iTax2);
        }
        
        if (isLowQuantity(item) == 1)
        {
            printf("WARNING: Quantity low, please order ASAP!!!\n");
        }
    }
}


void listItems(const struct Item item[], int noOfItems){
    int i = 0;
    double grand = 0;
    
    printTitle();
    for (i = 0;  i<noOfItems; i++)
    {
        printf("%-4d", (i + 1));
        displayItem(item[i], LINEAR);
        grand += totalAfterTax(item[i]);
    }
    
    printFooter(grand);
}


int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index){
    int i;
    int flag = 0;
    
    for (i = 0; i<NoOfRecs && !flag; i++)
    {
        if (item[i].sku == sku)
        {
            * index = i;
            flag= 1;
        }
    }
    return flag;
}


// Function Implementations Milestone 3:
void search(const struct Item item[], int NoOfRecs)
{
    int index;
    int input;
    int answer;
    
    printf("Please enter the SKU: ");
    input = getIntLimited(SKU_MIN, SKU_MAX);
    
    answer = locateItem(item, NoOfRecs, input, &index);
    
    if (answer == 1)
    {
        
        displayItem(item[index], FORM);
    }
    
    else
    {
        
        printf("Item not found!\n");
    }
}

void updateItem(struct Item* itemptr)
{
    
    struct Item item;
    
    printf("Enter new data:\n");
    item = itemEntry(itemptr->sku);
    printf("Overwrite old data? (Y)es/(N)o: ");
    
    int answer = yes();
    if (answer == 1)
    {
        * itemptr = item;
        printf("--== Updated! ==--\n");
    }
    
    else
    {
        printf("--== Aborted! ==--\n");
    }
    
}

void addItem(struct Item item[], int* NoOfRecs, int sku)
{
    struct Item newitem;
    
    if (* NoOfRecs >= MAX_ITEM_NO)
    {
        printf("Can not add new item; Storage Full!\n");
    }
    
    else
    {
        newitem = itemEntry(sku);
        printf("Add Item? (Y)es/(N)o: ");
        
        int answer = yes();
        if (answer == 1)
        {
            item[*NoOfRecs] = newitem;
            (* NoOfRecs)++;
            
            printf("--== Added! ==--\n");
        }
        
        else
        {
            printf("--== Aborted! ==--\n");
        }
    }
}

void addOrUpdateItem(struct Item item[], int* NoOfRecs)
{
    int input;
    int Index;
    int answer;
    
    
    printf("Please enter the SKU: ");
    input = getIntLimited(SKU_MIN, SKU_MAX);
    
    int found = locateItem(item, *NoOfRecs, input, &Index);
    
    if(found == 1)
    {
        displayItem(item[Index], FORM);
        printf("Item already exists, Update? (Y)es/(N)o: ");
        answer = yes();
        
        if (answer == 1)
        {
            updateItem(&item[Index]);
        }
        
        else
        {
            printf("--== Aborted! ==--\n");
            
        }
    }
    
    else
    {
        addItem(item, NoOfRecs , input);
    }
}


void adjustQuantity(struct Item item[], int NoOfRecs, int stock)
{
    int userQut;
    int sku;
    int flag = 0;
    int index;
    
    printf("Please enter the SKU: ");
    sku = getIntLimited(SKU_MIN, SKU_MAX);
    flag = locateItem(item, NoOfRecs, sku, &index);
    
    if(flag == 0)
    {
        printf("SKU not found in storage!\n");
    }
    
    else
    {
        displayItem(item[index], FORM);
        
        if(stock == STOCK)
        {
            printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ","to stock", MAX_QTY-item[index].quantity);
            userQut = getIntLimited(0, MAX_QTY-item[index].quantity);
            
            if(userQut == CHECKOUT)
            {
                printf("--== Aborted! ==--\n");
            }
            
            else
            {
                item[index].quantity += userQut;
                printf("--== Stocked! ==--\n");
            }
        }
        
        else if(stock == CHECKOUT)
        {
            printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", "to checkout", item[index].quantity);
            userQut = getIntLimited(0, item[index].quantity);
            
            if(userQut == CHECKOUT)
            {
                printf("--== Aborted! ==--\n");
            }
            
            else
            {
                item[index].quantity -= userQut;
                flag = isLowQuantity(item[index]);
                printf("--== Checked out! ==--\n");
            }
        }
        
        if (item[index].quantity <= item[index].minQuantity)
        {
            printf("Quantity is low, please reorder ASAP!!!\n");
        }
    }
}


//Milestone 4 functions
void saveItem(struct Item item, FILE* dataFile) 
{
    fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity,
            item.price, item.isTaxed, item.name);
    
}

int loadItem(struct Item* item, FILE* dataFile) 
{
    int found = 0;
    
    int number = fscanf(dataFile, "%d,%d,%d,%lf,%d,%20[^\n]", &(*item).sku, &(*item).quantity,
                        &(*item).minQuantity, &(*item).price, &(*item).isTaxed, (*item).name);
    
    if (number == 6) {    // if 6 numbers items read succesfully returns true.
        found = 1;
    }
    return found;
}

int saveItems(const struct Item item[], char fileName[],int NoOfRecs) 
{
    int i = 0;
    int found = 0;
    
    FILE* fp = NULL;
    fp = fopen(fileName, "w");
    if (fp != NULL) 
    {
        for (i=0; i<NoOfRecs; i++)
        {
            saveItem(item[i], fp);
        }
        found = 1;
        fclose(fp);
    }
    else {
        found=0;
    }
    return found;
}

int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr) {
    int i = 0;
    int found = 0;
    
    FILE* fp = NULL;
    fp = fopen(fileName, "r");
    if (fp != NULL) 
    {
        while (!feof(fp)) 
        {
            i += loadItem(&item[i], fp);
        }
        found = 1;
        * NoOfRecsPtr = i;
        fclose(fp);
    }
    else {
        found = 0;
    }
    return found;
}




