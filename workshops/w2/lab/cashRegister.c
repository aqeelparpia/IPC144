/* Name : Aqeel Parpia
Student id : 127921161
Date : Jan 25 2017  */

#include <stdio.h>
int main(void) {

	double amount, balancel, balanceq;
	int Loonies, Quarters;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	Loonies = amount / 1;
	balancel = amount - (Loonies * 1);

	Quarters = balancel / 0.25;
	balanceq = balancel - (Quarters * 0.25);

	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, balancel);
	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, balanceq);









	return 0;
}






