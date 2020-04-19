/*
Name: Aqeel Parpia
Student number:
Email: aparpia@myseneca.ca
Workshop: w3-logic
Section: MM
Date: 2/02/2017
*/

#include <stdio.h>
#define NUMS 3

int main(void)
{

	int i, highv = 0, lowv = 0;
	float avg = 0.0;



	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 1; i <= NUMS;)
	{

		printf("\nEnter the high value for day %d: ", i);
		scanf("%d", &highv);
        
        printf("\nEnter the low value for day %d: ", i);
		scanf("%d", &lowv);

		if (highv < lowv || highv > 40 || lowv < -40)
		{
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");


			printf("\nEnter the high value for day %d: ", i);
			scanf("%d", &highv);

			printf("\nEnter the low value for day %d: ", i);
			scanf("%d", &lowv);

	
		}
        
		avg = highv + lowv + avg;

		i++;

	}
	printf("\nThe average (mean) temperature was: %.2lf\n", (avg / (NUMS * 2)));

	return 0;

}
