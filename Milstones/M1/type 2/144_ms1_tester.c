// Final Project Milestone 1
// Student defined values tester
// Version 1.0
// Date	2017/03/07
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the UI tools
// and Application User Interface for submission.
//
/////////////////////////////////////////////////////////////////
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


int main(void) {
   //int iVal;
   //double dVal;
    
   welcome();

    //testing the App interface
   GroceryInventorySystem();
   //---------------------------------------------------------------

   return 0;
}

