/*
Name: Aqeel Parpia
Student number:
Email: aparpia@myseneca.ca
Workshop: w3-logic
Section: MM
Date: 2/02/2017
*/

#include <stdio.h>
#define MAXDAYS 10
int main()
{
	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");

	int number = 0;
	int highd[MAXDAYS];
	int lowd[MAXDAYS];
	int flag = 1;
	int i;

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &number);

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

	return 0;

}
