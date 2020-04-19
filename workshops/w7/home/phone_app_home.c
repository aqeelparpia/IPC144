/*
 Name: AQEEL PARPIA
 Student number: 127921161
 Email: aparpia@mysenenca.ca
 Milestone: 1
 Section: workshop 7 home
 Date: 16 March 2017
 */

#include <stdio.h>

#define SIZE 3


void decompose(const long long digits, int *area_code, int *prefix, int *linenumber) {
    *area_code = digits / 10000000.0;
    *prefix = (digits % 10000000) / 10000;
    *linenumber = digits % 10000;
}

int isValid(const long long Number);

int main(void) {
    long long phonenumber[SIZE] = { 0LL };
    int option;
    int areacode;
    int prefix;
    int linenumber;
    int i;
    int tracker = 0;
    long long number;
    int flag;
    
    printf("---=== Phone Numbers ===---\n\n");
    {
        
    }
    
    
    do {
        // Display the Option List
        printf("1. Display Phone List\n");
        printf("2. Add a Number\n");
        printf("0. Exit\n\n");
        printf("Please select from the above options: ");
        scanf("%d", &option);
        printf("\n");
        
        switch (option) {
            case 0:	// Exit the program
                printf("Exiting Phone Number App. Good Bye!!!\n");
                break;
                
            case 1: // Display the Phone List
                // @IN-LAB
                printf("Phone Numbers\n");
                printf("==============\n");
                // Display each number in decomposed form
                for (i = 0; i < tracker; i++) {
                    decompose(phonenumber[i], &areacode, &prefix, &linenumber);
                    printf("(%3d)-%3d-%4d\n", areacode, prefix, linenumber);
                }
                printf("\n");
                break;
                
                
                
                
            case 2:	// Add a Phone Number
                // @IN-LAB
                printf("Add a Number\n");
                printf("============\n");
                
                if (tracker < SIZE) {
                    scanf("%lld", &number);
                    flag = isValid(number);
                    if (flag == 0) {
                        phonenumber[tracker] = number;
                        tracker++;
                    }
                    else if (flag == 1) {
                        printf("ERROR!!! Phone Number is not Valid\n");
                    }
                }
                else {
                    printf("ERROR!!! Phone Number List is full \n");
                }
                printf("\n");
                break;
                
            default:
                printf("ERROR!!!: Incorrect Option: Try Again\n\n");
                break;
        }
        
    } while (option != 0);
    
    return 0;
}

int isValid(const long long Number) {
    int validity[3] = { 416, 647, 905 };
    int areacode, prefix, line;
    decompose(Number, &areacode, &prefix, &line);
    int flag = 1;
    int i;
    
    if (prefix >= 100 && prefix <= 999) {
        for (i = 0; i < 3; i++) {
            if (validity[i] == areacode)
                flag = 0;
        }
    }
    return flag;
}

