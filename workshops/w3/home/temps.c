/*
Name: Aqeel Parpia
Student number:
Email: aparpia@myseneca.ca
Workshop: w3-logic
Section: MM
Date: 2/02/2017
*/

#include <stdio.h>
#define NUMS 4

int main()
{

	int i, highv = 0, lowv = 0, H = 0, L = 0, highd = 0, lowd = 0;
	float avg = 0.0;



	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 0; i < NUMS; i++)
	{

		printf("\nEnter the high value for day %d: ", i+1);
		scanf("%d", &highv);

		printf("\nEnter the low value for day %d: ", i+1);
		scanf("%d", &lowv);

		if (highv < lowv || highv > 40 || lowv < -40)
		{
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");


			printf("\nEnter the high value for day %d: ", i+1);
			scanf("%d", &highv);

			printf("\nEnter the low value for day %d: ", i+1);
			scanf("%d", &lowv);


		}


		if (H < highv)
		{
			H = highv;
			highd= i+1;
		}

		if (L > lowv)
		{
			L = lowv;
			lowd = i+1;

		}

		avg = highv + lowv + avg;


	}
	printf("\nThe average (mean) temperature was: %.2lf\n", (avg / (NUMS * 2)));
	printf("The highest temperature was %d, on day %d\n", H, highd);
	printf("The lowest temperature was %d, on day %d\n", L, lowd);

	return 0;

}
