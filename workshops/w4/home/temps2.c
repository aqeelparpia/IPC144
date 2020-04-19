/*
Name: Aqeel Parpia
Student number:
Email: aparpia@myseneca.ca
Workshop: w4-Arrays
Section: MM
Date: 10/02/2017
*/

#include <stdio.h>
#define MAXDAYS 10
int main()
{
	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");


	int number = 0;
	int Anumber = 0;
	int highd[MAXDAYS];
	int lowd[MAXDAYS];
	int flag = 1;
	int i;
	double mean = 0.0;


	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &number);
        printf("\n");

	do
	{
		if (number >= 3 && number <= 10)
		{
			for (i = 0; i < number; i++)
			{
				printf("Day %d - High: ", i + 1);
				scanf("%d", &highd[i]);
				printf("Day %d - Low: ", i + 1);
				scanf("%d", &lowd[i]);
			}
			flag = 1;
		}


		else
		{
			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &number);
			printf("\n");
			flag = 0;
		}
	} while (flag == 0);


	printf("\nDay  Hi  Low\n");
	for (i = 0; i < number; i++)
		printf("%-3d %2d   %3d\n", i + 1, highd[i], lowd[i]);


	flag = 0;


	do
	{
		if (flag == 0)
		{
			printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", number);
			scanf("%d", &Anumber);
			flag = 1;
		}


		else if (Anumber > number && flag == 1)
		{
			printf("\nInvalid entry, please enter a number between 1 and 4, inclusive: ");
			scanf("%d", &Anumber);
			flag = 1;
		}
		else
		{
			for (i = 0; i < Anumber; i++)
				mean = mean + highd[i] + lowd[i];
			printf("\nThe average temperature up to day %d is: %.2lf\n", Anumber, mean / (2 * Anumber));
			flag = 0;
			mean = 0.0;
		}
	} while (Anumber >= 0);

        	printf("\nGoodbye!\n\n");
	


	return 0;


}

