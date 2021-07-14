#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "minor-management-functions.h"

void printMenu()
{
	printf("*************************************MAIN**MENU*************************************\n");
	printf("1.)Add a student.\n");
	printf("2.)Show all students.\n");
	printf("3.)Delete all students.\n");
	printf("4.)Search for a student.\n");
	printf("5.)See the general information of the class.\n");
	printf("6.)Sort the class.\n");
	printf("7.)Stop working.\n");
	printf("Please select(write) the number corresponding to your choice .\n");
}
int getChoice()
{
	long menuChoice = 0;
	char control[10] = {'0'};

	do
	{
		printMenu();
		fgets(control,10,stdin);
		menuChoice = (int)strtol(control,NULL,10);
	}while(menuChoice > 7 || menuChoice < 1);

	return menuChoice;
}
void printSearchMenu1()
{
	printf("**************************************SUB**MENU*************************************\n");
	printf("What would you like to do?\n");
	printf("1.)Search again.\n");
	printf("2.)Stop searching.\n");
	printf("Please select(write) the number corresponding to your choice .\n");
}
void printSearchMenu2()
{
	printf("**************************************SUB**MENU*************************************\n");
	printf("What would you like to do with the student?\n");
	printf("1.)Update the data of the student.\n");
	printf("2.)Delete the data of the student.\n");
	printf("3.)Search again.\n");
	printf("4.)Stop searching.\n");
	printf("Please select(write) the number corresponding to your choice .\n");
}
int getSearchChoice1()
{
	int searchChoice = 0;
	char control[10] = {'0'};

	do
	{
		printSearchMenu1();
		fgets(control,10,stdin);
		searchChoice = (int)strtol(control,NULL,10);
	} while (searchChoice > 2 || searchChoice < 1);

	return searchChoice;
}
int getSearchChoice2()
{
	int searchChoice = 0;
	char control[10] = {'0'};

	do
	{
		printSearchMenu2();
		fgets(control,10,stdin);
		searchChoice = (int)strtol(control,NULL,10);
	}while (searchChoice > 4 || searchChoice < 1);

	return searchChoice;
}
void printSearchMenuMain()
{
	printf("************************************SEARCH**MENU************************************\n");
	printf("What would you like to do?\n");
	printf("1.)Search by name.\n");
	printf("2.)search by id.\n");
	printf("3.)return to the main menu.\n");
	printf("Please select(write) the number corresponding to your choice .\n");
}
int getSearchOption()
{
	int searchChoice = 0;
	char control[10] = {'0'};

	do
	{
		printSearchMenuMain();
		fgets(control,10,stdin);
		searchChoice = (int)strtol(control,NULL,10);
	}while (searchChoice > 3 || searchChoice < 1);

	return searchChoice;
}
void printDeleteValidationMenu()
{
	printf("*********************************DELETE*ALL*STUDENTS********************************\n");
	printf("Are you sure you want to delete the information of all the students?\n");
	printf("1.)Yes.\n");
	printf("2.)No.\n");
	printf("Please select(write) the number corresponding to your choice .\n");
}
int getDeleteValidation()
{
	int confirmChoice = 0;
	char control[10] = {'0'};

	do
	{
		printDeleteValidationMenu();
		fgets(control,10,stdin);
		confirmChoice = (int)strtol(control,NULL,10);
	}while (confirmChoice > 2 || confirmChoice < 1);

	return confirmChoice;
}
void printSortOptions()
{
	printf("*********************************SORT**ALL**STUDENTS********************************\n");
	printf("Which order will you prefer?\n");
	printf("1.)Alphabetical order.\n");
	printf("2.)Ranking order.\n");
	printf("Please select(write) the number corresponding to your choice .\n");
}
int getStudentsOrder()
{
	int sortChoice = 0;
	char control[10] = {'0'};

	do
	{
		printSortOptions();
		fgets(control,10,stdin);
		sortChoice = (int)strtol(control,NULL,10);
	}while (sortChoice > 2 || sortChoice < 1);

	return sortChoice;
}
void controlChain(char *chain)
{
	int i = 0;

	while (chain[i] != '\0')
	{ 
		if (chain[i] == '\n')
		{
			chain[i] = 0;
		}
        i++; 
    }
}
void upperCase(char *chain)
{
	int i = 0;

	while (chain[i] != '\0')
	{ 
		chain[i] = toupper(chain[i]);
        i++; 
    }
}
float studentAverage(float *studentScore)
{
	float mean = 0;

	for (int i = 0; i < 5; ++i)
	{
		mean += studentScore[i];//sums the different scores
	}
	mean /= 5;

	return mean;
}
int isSortAlphabetic(char *chain1,char *chain2)
{
	int i = 0,result;

	while(chain1[i] == chain2[i])
	{
		i++;
	}
	if (chain1[i] < chain2[i])
	{
		result = 1;//chain1 comes before chain2 inthe alphabetical order
	}else
	{
		result = 0;//chain1 comes after chain2 inthe alphabetical order
	}

	return result;
}

int isSortValue(float value1,float value2)
{
	int i = 0,result;

	if (value1 <= value2)
	{
		result = 1;
	}else
	{
		result = 0;
	}
	
	return result;
}