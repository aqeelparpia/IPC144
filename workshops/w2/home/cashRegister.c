/* Name : Aqeel Parpia
Student id : 127921161
Date : Jan 25 2017  */

#include <stdio.h>
int main(void) {

	double amount, balancel, balanceq, gst, balanceO, balanced, balancen, balancep;
	int Loonies, Quarters, dimes, nickles, pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	gst = amount*.13 + .005;
	printf("GST: %.2lf\n", gst);

	balanceO = amount + gst;
	printf("Balance owing: $%.2lf\n", balanceO);

	Loonies = balanceO / 1;
	balancel = balanceO - (Loonies * 1);
	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, balancel);

	Quarters = balancel / 0.25;
	balanceq = balancel - (Quarters * 0.25);
	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, balanceq);

	dimes = (balanceq / 10) * 100;
	balanced = balanceq - (dimes*0.10);
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, balanced);

	nickles = (balanced / 5) * 100;
	balancen = balanced - (nickles * .05);
	printf("Nickels required: %d, balance owing $%.2lf\n", nickles, balancen);

	pennies = (balancen * 100);
	balancep = balancen - (pennies * .01);
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, balancep);


	return 0;
}
