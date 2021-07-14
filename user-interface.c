#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "minor-management-functions.h"
#include "save-load-functions.h"
#define MATH_INDEX 0
#define ENGLISH_INDEX 1
#define FRENCH_INDEX 2
#define PHYSICS_INDEX 3
#define COMPUTER_INDEX 4

void userInterface()
{
	int choice = 0;
    StudentList *myListStudents = initialise();

    loadData(myListStudents);
    updateStudentListInfo(myListStudents);
	printf("Hello sir, What would you like to do ?\n");

	do
	{
		choice = getChoice();	

		switch(choice)
		{
			case 1: ;
				char studentName[40],studentId[15];
		    	int studentAge;
				float studentScore[5];

				getStudentInfo(myListStudents,studentName,studentId,studentAge,studentScore);
				updateStudentListInfo(myListStudents);
				break;
			case 2:
				if(myListStudents->firstStudent == NULL)
				{
					printf("There are no students!!\n");
			    }else
			    {
			    	printf("This is the beginning of the list of students\n");
			    	showInfoStudents(myListStudents);
			    	printf("------------------------------------------------------------------------------------\n");
			  		printf("This is the end of the list of students\n");
			    }
			    break;
			case 3:
				if(myListStudents->firstStudent == NULL)
				{
					printf("There are no students!!\n");
			    }else
				{
					int deleteChoice = getDeleteValidation();

					if (deleteChoice == 1)
					{
						deleteStudents(myListStudents);
						printf("The data of all the students has been deleted!\n");
					}
			    }
			    break;
		  	case 4:
		  	    if (myListStudents->firstStudent == NULL)
		  	    {
		  	  	  printf("There is no student for the search to be done!\n");
		  	    }else
		  	    {
					searchUserInterface(myListStudents);
		  	    }
		  	    break;
		  	case 5:
				printStudentListInfo(myListStudents);
				break;
			case 6: ;
				int orderChoice = getStudentsOrder();

				if (orderChoice == 1)
				{
					sortStudents(myListStudents);
				}else
				{
					sortStudentsByRank(myListStudents);
				}
				break;
			case 7:
				saveData(myListStudents);
				deleteStudents(myListStudents);
			  	break;
		}
	}while(choice != 7);
	
	free(myListStudents);
}