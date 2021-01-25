#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctionsGestion.h"
#define MATH_INDEX 0
#define ENGLISH_INDEX 1
#define FRENCH_INDEX 2
#define PHYSICS_INDEX 3
#define COMPUTER_INDEX 4

void userInterface()
{
	long choice = 0;
	char control[100] = {'0'};
    StudentList *myListStudents;

    myListStudents = initialise();
	printf("Hello sir, What would you like to do ?\n");

	do
	{
		printf("***********************************MENU***********************************\n");
		printf("1.)Add a student.\n");
		printf("2.)Show all students.\n");
		printf("3.)Delete all students.\n");
		printf("4.)Stop working.\n");
			
		do
		{
			printf("Please select(write) the number corresponding to your choice .\n");
			scanf("%s",control);
			choice = strtol(control,NULL,10);
		}while(choice > 4 || choice < 1);

		char studentName[40],studentId[11];
		int studentAge;
		float studentScore[5];

		switch(choice)
		{
			case 1:
			  printf("--------------------------------------------------------------------------\n");
			  printf("Name: ");
			  getchar();
			  fgets(studentName,40,stdin);
			  printf("Id: ");
			  fgets(studentId,11,stdin);
			  printf("Age: ");
			  scanf("%d",&studentAge);
			  printf("Score in Maths: ");
			  scanf("%f",studentScore+MATH_INDEX);
			  printf("Score in English: ");
			  scanf("%f",studentScore+ENGLISH_INDEX);
			  printf("Score in French: ");
			  scanf("%f",studentScore+FRENCH_INDEX);
			  printf("Score in Physics: ");
			  scanf("%f",studentScore+PHYSICS_INDEX);
			  printf("Score in Computer Science: ");
			  scanf("%f",studentScore+COMPUTER_INDEX);
			  addStudent(myListStudents,studentName,studentId,studentAge,studentScore,5);
			  break;
			case 2:
		      showInfoStudents(myListStudents);
			  break;
			case 3:
			  deleteStudents(myListStudents);
			  printf("The data of all the students has been deleted!\n");
			  break;
		  	case 4:
			  printf("Thanks for your hard work\n");
			  break;
		}
	}while(choice != 4);
}