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
	int searchMainChoice = 0,searchSubChoice1 = 0,searchSubChoice2 = 0;

	do
	{
		searchMainChoice = getSearchOption();

		if (searchMainChoice == 1)
		{
			printf("Please enter the name of the student you're looking for.\n");
		}else if (searchMainChoice == 2)
		{
			printf("Please enter the id of the student you're looking for.\n");
		}

		if (searchMainChoice != 3)
		{
			fgets(searchChain,40,stdin);
			controlChain(searchChain);
			search(listStudents,correspondenceList,searchChain,searchMainChoice);
			printSearchResults(listStudents,correspondenceList,searchChain,&searchSubChoice1,&searchSubChoice2);
		}
		deleteStudents(correspondenceList);
	}while (searchMainChoice != 3 && searchSubChoice1 != 2 && searchSubChoice2 != 4);

	free(correspondenceList);
}
void printSearchResults(StudentList *listStudents,StudentList *correspondingStudentsList,char *chain,int *subChoice1,int *subChoice2)
{
	if (correspondingStudentsList->firstStudent == NULL)
	{
	  	printf("No student has a name corresponding to what you entered!\n");
	  	*subChoice1 = getSearchChoice1();
	}else if (correspondingStudentsList->firstStudent->nextStudent == NULL)
	{
	  	printf("This is the only student corresponding to your entry:\n");
	  	showInfoStudents(correspondingStudentsList);
	  	*subChoice2 = getSearchChoice2();

	  	switch(*subChoice2)
	  	{
	  	  	case 1: ;
	  	  		char studentName[40],studentId[15];
	    		int studentAge;
				float studentScore[5];

	  	  		deleteOneStudent(listStudents,chain);
	  	  		updateStudentListInfo(listStudents);
	  	  		getStudentInfo(listStudents,studentName,studentId,studentAge,studentScore);
	  	  	    *subChoice1 = getSearchChoice1();
	  	  	    break;
		    case 2:
				deleteOneStudent(listStudents,chain);
				printf("The data of the student was deleted!\n");
				updateStudentListInfo(listStudents);
				*subChoice1 = getSearchChoice1();
				break;
		}
	}else
	{
	  	printf("These are the students corresponding to your entry:\n");
	  	printf("------------------------------------------------------------------------------------\n");
	  	showInfoStudents(correspondingStudentsList);
	  	printf("This is the end of the list of students\n");
	  	*subChoice1 = getSearchChoice1();
	}
}