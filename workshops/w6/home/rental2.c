/*
Name:Aqeel Parpia
Student number: 127921161
Email:aparpia@myseneca.ca
Workshop: w6-home
Section: MM
Date: 3 march 2017
*/

/*
== Vehicle Rentals ==

Author : Gayan Gamage
Date : 15-02-2017
Revision: 1.0
Workshop: #6 at-Home

*/

#include <stdio.h>

#define distRate1  0.69 // Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49 // Rate per Kilometer above 100km


// Structure Declaration for Vehicle Rentals
struct Rental
{
	int id; // ID of the Rental Vehicle
	double baseDay; // Daily Base Price
	double earnings; // Total earnings from this rental
};

/* prototype functions addPositive , taxCalc & subtractPositive*/
double addPositive(double amount, double newAmount);
double taxCalc(double price, double rate);
double subtractPositive(double amount, double newAmount);


/* Implement Function addPositive Here*/

double addPositive(double amount, double newAmount)
{
	if (newAmount > 0) {
		amount = amount + newAmount;
	}
	return amount;
}




/* Implement Function taxCalc Here */
double taxCalc(double price, double rate)
{
	double taxes;
	taxes = price * rate / 100;
	return taxes;
}



/* Implement Function subtractPositive Here*/
double subtractPositive(double amount, double newAmount)

{
	if (newAmount > 0)
	{
		amount = amount - newAmount;

	}
	return amount;
}



/* main program */
int main()
{
	const int noVehicles = 3; // Number of Vehicles [ Changed to 3]
	int option; // Variable to store the option selected
	int flag; // Flag to support vehicle ID find
	int tempID; // To hold user input for vehicle ID
	int i = 0; // Variable for "for-loop" counters

			   // Initialize the struct Vehicle Rental [ New addition for 3 Rentals]
	struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 },{ 125, 29.95, 0 } };

	double taxRate = 14; // Tax rate is 14%
	double discount = 5;    // Discount amount for rentals (in CAD)

							/*Declare Your Variables Here*/

	int Days;
	int Distance;
	double giftcard;
	double baseprice;
	double Discost;
	double charge = 0;
	double taxes;
	char input;






	printf("***** Rental Vehicle Management App *****\n");

	do
	{
		// Display the option list
        printf("\n");
		printf("1.) Rental Status\n");
		printf("2.) Apply Charges\n");
		printf("3.) Apply Taxes to All Rentals\n");
		printf("4.) Apply Gift Card\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");


		scanf("%d", &option);

		switch (option)
		{
		case 0: // Exit the program
			break;

		case 1: // Rental Vehicle Status

			printf("\n-- Rental Vehicle Status --\n\n");
			printf("ID#      Earnings\n");
			printf("-------- ----------\n");


			for (i = 0; i < noVehicles; i++)
			{
				printf("%8d %10.2lf\n", vRent[i].id, vRent[i].earnings);


			}

			// Use "%8d %10.2lf" formatting to display ID and Earnings for each rental

			/* Copy and Paste from In-Lab Case - 1 */


			break;

		case 2: // Calculate Rental Charges

			flag = -1;
			printf("\n-- Rental Charges --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);

			// Finding the correct vehicle index
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}

			if (flag != -1)
			{

				// Capture #days for the rental from user input
				/* Copy and Paste from In-Lab Case - 2 */

				printf("Enter Rental Period (in Days): ");
				scanf("%d", &Days);

				// Calculate the base price (baseDay * Days)
				/* Copy and Paste from In-Lab Case - 2 */

				baseprice = vRent[flag].baseDay * Days;


				// Calculate cost for Kilometers driven
				/* Copy and Paste from In-Lab Case - 2 */

				printf("Enter kilometers driven: ");
				scanf("%d", &Distance);

				if (Distance <= 100)
					Discost = Distance * distRate1;

				else
					Discost = distRate1 * 100 + (Distance - 100) * distRate2;




				// Add base Price and cost for kilometer driven in to a new variable "charge"
				/* Copy and Paste from In-Lab Case - 2 */

				charge = baseprice + Discost;


				/* Call addPositive function with current earnings for the rental and
				charge(calculated above) as arguments and assign the returned
				result back to earnings
				*/
				/* Copy and Paste from In-Lab Case - 2 */

				vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);


				// Apply Discount with a prompt for Y or N
				// If the user input is skipped without being prompted, have one space infront
				// of %c in the scanf statement => " %c" instead of "%c"

				printf("Apply Discount: ");
				scanf(" %c", &input);





				/* If the input is 'Y' or 'y' then call function subtractPositive with current earnings
				for the rental and discount (5 CAD) as arguments and assign the returned
				result back to earnings
				*/
				if (input == 'Y' || input == 'y')
				{
					vRent[flag].earnings = subtractPositive(vRent[flag].earnings, discount);

				}

				// Display Base Charge, cost for km and the Total
				printf("\nBase   kmCost DiscStatus Total\n");
				printf("====== ====== ========== ======\n");
				printf("%6.2lf %6.2lf %10c %6.2lf\n", baseprice, Discost, input, vRent[flag].earnings);
            
				// Use "%6.2lf %6.2lf %10c %6.2lf" formatting inside a printf statement


			}
			else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}


			break;

		case 3: // Apply Taxes to all Earnings

			printf("\n-- Apply Taxes To all Accounts--\n\n");

			printf("ID#      Earnings   Taxes\n");
			printf("-------- ---------- ------\n");

			// Iterate over all Rentals. For each rental, calculate the taxes by calling taxCalc
			// by passing current earnings and tax rate
			// Then call addPositive with current earnings and the taxes returned from taxCalc function
			// Then use "%8d %10.2lf %6.2lf" formatting to display ID, Earnings and taxes for each rental

			taxes = taxCalc(vRent[i].earnings, taxRate);
			vRent[i].earnings = addPositive(vRent[i].earnings, taxes);

			for (i = 0; i < noVehicles; i++)
			{
				taxes = taxCalc(vRent[i].earnings, taxRate);  //calling taxCalc function
				vRent[i].earnings = addPositive(vRent[i].earnings, taxes);  //calling addPositive 

				printf("%8d %10.2lf %6.2lf", vRent[i].id, vRent[i].earnings, taxes);
				printf("\n");
			}




			break;

		case 4: // Apply Gift Card

			flag = -1;
			printf("\n-- Apply Gift Card --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);


			// Finding the correct vehicle index
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}
			if (flag != -1) {

				// Capture Gift card amount
				printf("Enter Gift Card Amount: ");
				scanf("%lf", &giftcard);



				/* call function subtractPositive with current earnings for the rental and Gift card
				amount as arguments and assign the returned result back to earnings
				*/
				vRent[flag].earnings = subtractPositive(vRent[flag].earnings, giftcard);
				printf("Discount Applied\n");



			}
			else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}

			

			break;

		default:
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}


	} while (option != 0);


	return 0;
}

