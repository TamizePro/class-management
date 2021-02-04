#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "major-management-functions.h"
#include "minor-management-functions.h"

void searchUserInterface(StudentList *listStudents)
{
	StudentList *correspondenceList = initialise();
	char searchChain[40];
	int searchMenuChoice1 = 0,searchMenuChoice2 = 0;

	do
	{
		printf("************************************SEARCH**MENU************************************\n");
		printf("Please enter the name of the student you're looking for.\n");
		fgets(searchChain,40,stdin);
		controlChain(searchChain);
		search(listStudents,correspondenceList,searchChain,5);

		if (correspondenceList->firstStudent == NULL)
		{
		  	printf("No student has a name corresponding to what you entered!\n");
		  	searchMenuChoice1 = getSearchChoice1();
		}else if (correspondenceList->firstStudent->nextStudent == NULL)
		{
		  	char studentName[40],studentId[11];
		    int studentAge;
			float studentScore[5];

		  	printf("This is the only student corresponding to your entry.\n");
		  	showInfoStudents(correspondenceList);
		  	searchMenuChoice2 = getSearchChoice2();

		  	switch(searchMenuChoice2)
		  	{
		  	  	case 1:
		  	  		deleteOneStudent(listStudents,searchChain);
		  	  		getStudentInfo(listStudents,studentName,studentId,studentAge,studentScore,5);
		  	  		sortStudents(listStudents);
		  	  	    searchMenuChoice1 = getSearchChoice1();
		  	  	    break;
		  	  	case 2:
					deleteOneStudent(listStudents,searchChain);
					printf("The data of the student was deleted!\n");
					searchMenuChoice1 = getSearchChoice1();
					break;
			}
		}else
		{
		  	printf("These are the students corresponding to your entry.\n");
		  	showInfoStudents(correspondenceList);
		  	searchMenuChoice1 = getSearchChoice1();
		}
		deleteStudents(correspondenceList);
	}while (searchMenuChoice1 != 2 && searchMenuChoice2 != 4);
}