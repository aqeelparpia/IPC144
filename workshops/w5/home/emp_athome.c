/*
Name:Aqeel Parpia
Student number: 127921161
Email:aparpia@myseneca.ca
Workshop: w5-Structures
Section: MM
Date: 17 feb 2017
*/

// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"


// Create two switch-cases for option 3 & 4 after case 2.
// Implement "Update Salary" and "Remove Employee"
// functionality as per instructions
// inside the relevant case statements


#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 4

// Declare Struct Employee
struct Employee {
	int Id;
	int Age;
	double Salary;
};


/* main program */
int main(void)
{

	int option = 0;
	int i;
	int Id;
	int tracker = 0;
	int flag = 0;
	double Newsalary = 0;
	struct Employee emp[SIZE] = { { 0 },{ 0 } ,{ 0 },{ 0 } };

	printf("---=== EMPLOYEE DATA ===---\n");

	// Declare a struct Employee array "emp" with SIZE elements
	// and initialize all elements to zero

	do {
		// Print the option list
		printf("\n");
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");


		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");


		switch (option)
		{
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1: // Display Employee Data
				// @IN-LAB
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++)

				if (emp[i].Id > 0)
				{
					printf("%6d%9d%11.2lf\n", emp[i].Id, emp[i].Age, emp[i].Salary);
				}



			// Use "%6d%9d%11.2lf" formatting in a
			// printf statement to display
			// employee id, age and salary of
			// all  employees using a loop construct

			// The loop construct will be run for SIZE times
			// and will only display Employee data
			// where the EmployeeID is > 0

			break;

		case 2:	// Adding Employee
				// @IN-LAB
			printf("Adding Employee\n");
			printf("===============\n");
			if (tracker < SIZE)
			{

				printf("Enter Employee ID: ");
				scanf("%d", &emp[tracker].Id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[tracker].Age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[tracker].Salary);
				tracker++;
			}

			else
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}






			// Check for limits on the array and add employee
			// data accordingly.



			break;
		case 3:
			flag = 0;
			printf("Update Employee Salary\n");
			printf("======================\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &Id);


				for (i = 0; i < tracker && flag == 0; i++)
				{
					if (Id == emp[i].Id)
					{

						printf("The current salary is %.2lf\n", emp[i].Salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &Newsalary);
						emp[i].Salary = Newsalary;
						flag = 1;
						
					}
				}
			} while (flag != 1);

			break;

		case 4:

			flag = 0;
			printf("Remove Employee\n");
			printf("===============\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &Id);

				for (i = 0; i < SIZE; i++)
				{
					if (Id == emp[i].Id)
					{
						printf("Employee %d will be removed", emp[i].Id);
						emp[i].Id = 0;
						tracker--;
						flag = 1;
						printf("\n");
					}
				}
			} while (flag != 1);
			break;
		default:

			printf("ERROR: Incorrect Option: Try Again\n");



		}


	} while (option != 0);
	return 0;
}
