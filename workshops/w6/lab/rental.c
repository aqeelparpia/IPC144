/*
 Name:Aqeel Parpia
 Student number: 127921161
 Email:aparpia@myseneca.ca
 Workshop: w6
 Section: MM
 Date: 25 feb 2017
 */

/*
 == Vehicle Rentals ==
 
 Author	: Gayan Gamage
 Date	: 14-02-2017
 Revision: 1.0
 Workshop: #6 in-Lab
 
 */


#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km

// Structure Declaration for Vehicle Rentals
struct Rental
{
    int id;						// ID of the Rental Vehicle
    double baseDay;				// Daily Base Price
    double earnings;			// Total earnings from this rental
};


/* prototype functions addPositive Here*/
double addPositive(double amount, double newAmount);



/* Implement Function addPositive Here*/
double addPositive(double amount, double newAmount)
{
    if (newAmount > 0)
        amount = amount + newAmount;
    return amount;
}




/* main program */
int main()
{
    const int noVehicles = 2;			// Number of Vehicles
    int option;							// Variable to store the option selected
    int flag;							// Flag to support vehicle ID find
    int tempID;							// To hold user input for vehicle ID
    int i = 0;							// Variable for "for-loop" counters
    
    
    // Initialize the struct Vehicle Rental
    struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 } };
    
    /*Declare Your Variables Here*/
    
    int check = 0 , Days = 0, Distance = 0;
    double baseprice = 0.0 , Discost = 0.0, charge = 0.0 , earnings = 0.0 ;
    
    
    printf("***** Rental Vehicle Management App *****\n");
    
    do
    {
        // Display the option list
        printf("\n1.) Rental Status\n");
        printf("2.) Apply Charges\n");
        printf("0.) Log out\n\n");
        printf("Please enter an option to continue: ");
        
        scanf("%d", &option);
        
        switch (option)
        {
            case 0: // Exit the program
                break;
                
            case 1: // Rental Vehicle Status
                
                i = 0;
                printf("\n-- Rental Vehicle Status --\n\n");
                printf("ID#      Earnings\n");
                printf("-------- ----------\n");
                
                while (i< check)
                {
                    printf("%8d %10.2lf\n",vRent[i].id,vRent[i].earnings );
                    i++;
                }
                
                // Use "%8d %10.2lf" formatting to display ID and Earnings for each rental
                // using a loop construct
                
                break;
                
            case 2: // Calculate Rental Charges
                
                flag = -1;
                printf("\n-- Rental Charges --\n\n");
                printf("Enter vehicle ID: ");
                scanf("%d", &tempID);
                
                // Finding the correct vehicle index
                for (i = 0; i < noVehicles && flag == -1; i++)
                {
                    if (tempID == vRent[i].id)
                    {
                        flag = i;
                    }
                }
                
                if (flag != -1)
                {
                    check++;
                    
                    // Capture #days for the rental from user input
                    printf("Enter Rental Period (in Days): ");
                    scanf("%d", &Days);
                    
                    // Calculate the base price (baseDay * Days)
                    
                    baseprice = vRent[flag].baseDay * Days;
                    
                    // Calculate cost for Kilometers driven using "distRate1 & 2 above"
                    
                    printf("Enter kilometers driven: ");
                    scanf("%d", &Distance);
                    
                    if (Distance > 0)
                    {
                        if (Distance <= 100)
                            Discost = Distance * distRate1;
                        
                        else
                        {
                            Distance = Distance - 100;
                            Discost = Distance * distRate2 + 100 * distRate1;
                        }
                        
                    }
                    
                    // Add base Price and cost for kilometer driven in to a new variable
                    // "charge"
                    
                    charge = baseprice + Discost;
                    
                    
                    /* Call addPositive function with current earnings for the rental and
                     charge(calculated above) as arguments and assign the returned
                     result back to earnings
                     */
                    
                    
                    vRent[flag].earnings= addPositive(earnings, charge);
                    
                    
                    
                    // Display Base Charge, cost for km and the Total
                    printf("\nBase   kmCost Total\n");
                    printf("====== ====== ======\n");
                    printf("%6.2lf %6.2lf %6.2lf\n", baseprice, Discost, vRent[flag].earnings);
                    // Use "%6.2lf %6.2lf %6.2lf" formatting inside a printf statement
                    
                }
                else {
                    printf("ERROR: Vehicle ID does not exist.\n");
                }
                
                break;
                
                
            default:
                printf("Error: Please enter a valid option to continue\n\n");
                break;
        }
        
        
    } while (option != 0);
    
    printf("\n");
    
    return 0;
}

/* SAMPLE INPUT/OUTPUT EXPECTED 
 
 
 
 ***** Rental Vehicle Management App *****
 
 1.) Rental Status
 2.) Apply Charges
 0.) Log out
 
 Please enter an option to continue: 2
 
 -- Rental Charges --
 
 Enter vehicle ID: 123
 Enter Rental Period (in Days): 2
 Enter kilometers driven: 125
 
 Base   kmCost Total
 ====== ====== ======
 19.90  81.25 101.15
 
 1.) Rental Status
 2.) Apply Charges
 0.) Log out
 
 Please enter an option to continue: 2
 
 -- Rental Charges --
 
 Enter vehicle ID: 124
 Enter Rental Period (in Days): 3
 Enter kilometers driven: 79
 
 Base   kmCost Total
 ====== ====== ======
 59.85  54.51 114.36
 
 1.) Rental Status
 2.) Apply Charges
 0.) Log out
 
 Please enter an option to continue: 2
 
 -- Rental Charges --
 
 Enter vehicle ID: 125
 ERROR: Vehicle ID does not exist.
 
 1.) Rental Status
 2.) Apply Charges
 0.) Log out
 
 Please enter an option to continue: 1
 
 -- Rental Vehicle Status --
 
 ID#      Earnings
 -------- ----------
 123     101.15
 124     114.36
 
 1.) Rental Status
 2.) Apply Charges
 0.) Log out
 
 Please enter an option to continue: */
