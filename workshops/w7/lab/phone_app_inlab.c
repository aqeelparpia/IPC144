/*
 Name: AQEEL PARPIA
 Student number: 127921161
 Email: aparpia@mysenenca.ca
 Workshop: W7
 Section: MM
 Date: 9 MARCH 2017
 */

#include <stdio.h>
#define SIZE 3

void decompose(long long *phoneNumber, int *AAA, int *PPP, int *LLLL); // protottype of the function

void decompose(long long *phoneNumber, int *AAA, int *PPP, int *LLLL) // declaring of the function

{
    *AAA = *phoneNumber / 10000000.0;
    *PPP = *phoneNumber / 10000 % 1000;
    *LLLL = *phoneNumber % 10000;
    
}


/* main program */
int main(void) {
    
    int option;
    int tracker = 0;
    int i, j = 0;
    long long phoneNumber[SIZE] = { 0LL };
    
    int areacode[SIZE] = { 0 };
    int prefix[SIZE] = { 0 };
    int linenumber[SIZE] = { 0 };
    
    printf("---=== Phone Numbers ===---\n\n");
    
    do {
        // Display the Option List
        printf("1. Display Phone List\n");
        printf("2. Add a Number\n");
        printf("0. Exit\n\n");
        printf("Please select from the above options: ");
        scanf("%d", &option);
        printf("\n");
        
        switch (option) {
            case 0:
                // Exit the program
                
                printf("Exiting Phone Number App. Good Bye!!!\n");
                
                
                break;
            case 1: // Display the Phone List
                // @IN-LAB
                printf("Phone Numbers\n");
                printf("==============\n");
                // Display each number in decomposed form
                
                
                for (i = 0; i < tracker; i++)
                {
                    printf("(%3d)-%3d-%4d\n", areacode[i], prefix[i], linenumber[i]);
                }
                
              printf("\n"); 
                
                
                break;
            case 2:
                // Add a Phone Number
                // @IN-LAB
                printf("Add a Number\n");
                printf("============\n");
                
                if (j + 1 > SIZE)
                {
                    printf("ERROR!!! Phone Number List is Full\n");
                    printf("\n");
                    
                }
                else
                {
                    scanf("%lld", &phoneNumber[j]);
                    decompose(&phoneNumber[j], &areacode[j], &prefix[j], &linenumber[j]);
                    j++;
                    tracker++;
                    printf("\n");
                }
                
                
                break;
            default:
                printf("ERROR!!!: Incorrect Option: Try Again\n\n");
                
                
        }
        
    } while (option != 0);
    
    return 0;
}



