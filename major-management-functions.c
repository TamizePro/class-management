#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "save-load-functions.h"
#include "minor-management-functions.h"
#define MATH_INDEX 0
#define ENGLISH_INDEX 1
#define FRENCH_INDEX 2
#define PHYSICS_INDEX 3
#define COMPUTER_INDEX 4

StudentList* initialise()
{
	StudentList *listStudents = (StudentList*)malloc(sizeof(StudentList));

	listStudents->firstStudent = NULL;
	listStudents->effectiveNumber = 0;
	listStudents->bestAverage = 0;
	listStudents->worstAverage = 0;
	listStudents->classAverage = 0;

	return listStudents;
}
void printStudentInfo(Student *student1)
{
	printf("------------------------------------------------------------------------------------\n");
	printf("Name: %s",student1->name);
	printf("Id: %s\n",student1->id);
	printf("Age: %d\n",student1->age);
	printf("Score in Maths: %3.3f/20\n",student1->score[MATH_INDEX]);
	printf("Score in English: %3.3f/20\n",student1->score[ENGLISH_INDEX]);
	printf("Score in French: %3.3f/20\n",student1->score[FRENCH_INDEX]);
	printf("Score in Physics: %3.3f/20\n",student1->score[PHYSICS_INDEX]);
	printf("Score in Computer Science: %3.3f/20\n",student1->score[COMPUTER_INDEX]);
	printf("Overall average: %3.3f/20\n",student1->average);
	printf("rank: %d\n",student1->rank);
}
void showInfoStudents(StudentList *listStudents)
{
	Student *currentStudent = listStudents->firstStudent;

	while(currentStudent != NULL)
	{
		printStudentInfo(currentStudent);
		currentStudent = currentStudent->nextStudent;
	}
}
void addStudent(StudentList *listStudents,char* nameStudent,char* idStudent,int ageStudent,float studentScore[])
{
	Student *newStudent = (Student*)malloc(sizeof(Student));

	strcpy(newStudent->name,nameStudent);
	strcpy(newStudent->id,idStudent);
	newStudent->age = ageStudent;
	newStudent->score[MATH_INDEX] = studentScore[MATH_INDEX];
	newStudent->score[ENGLISH_INDEX] = studentScore[ENGLISH_INDEX];
	newStudent->score[FRENCH_INDEX] = studentScore[FRENCH_INDEX];
	newStudent->score[PHYSICS_INDEX] = studentScore[PHYSICS_INDEX];
	newStudent->score[COMPUTER_INDEX] = studentScore[COMPUTER_INDEX];
	newStudent->average = studentAverage(studentScore);
	newStudent->nextStudent = NULL;

	Student *student = listStudents->firstStudent;
	
	if (student == NULL)
	{
		listStudents->firstStudent = newStudent;
	}else
	{
		while(student->nextStudent != NULL)
		{
			student = student->nextStudent;
		}
		student->nextStudent = newStudent;
	}
}
int isUnique(StudentList *listStudents,char *chain)
{
	Student *currentStudent = listStudents->firstStudent;
	char *position = NULL;
	int result = 1;

	while(currentStudent != NULL)
	{
		position = strstr(currentStudent->id,chain);

		if (position != NULL)
		{
			result = 0;
			break;
		}
		currentStudent = currentStudent->nextStudent;
	}

	return result;
}
void getUniqueId(StudentList *listStudents,char *idStudent)
{
	int valid = 1;

	do
	{
		printf("Id: ");
		fgets(idStudent,15,stdin);
		upperCase(idStudent);
		controlChain(idStudent);
		valid = isUnique(listStudents,idStudent);

		if (valid == 0)
		{
			printf("The id you have entered is already posessed by another student!\n");
		}
	} while (valid == 0);
}
void getStudentInfo(StudentList* listStudents,char* nameStudent,char* idStudent,int ageStudent, float* scoreStudent)
{
	printf("------------------------------------------------------------------------------------\n");
	printf("Name: ");
	fgets(nameStudent,40,stdin);
	upperCase(nameStudent);
	getUniqueId(listStudents,idStudent);
	printf("Age: ");
	scanf("%d",&ageStudent);
	printf("Score in Maths: ");
	scanf("%f",scoreStudent+MATH_INDEX);	printf("Score in English: ");
	scanf("%f",scoreStudent+ENGLISH_INDEX);
	printf("Score in French: ");
	scanf("%f",scoreStudent+FRENCH_INDEX);
	printf("Score in Physics: ");
	scanf("%f",scoreStudent+PHYSICS_INDEX);
	printf("Score in Computer Science: ");
	scanf("%f",scoreStudent+COMPUTER_INDEX);
	getchar();
	addStudent(listStudents,nameStudent,idStudent,ageStudent,scoreStudent);
}
void deleteStudents(StudentList *listStudents)
{
	Student *currentStudent = listStudents->firstStudent,*toDelete = NULL;

	while(currentStudent != NULL)
	{
		toDelete = currentStudent;
		currentStudent = currentStudent->nextStudent;
		free(toDelete);
	}

	listStudents->firstStudent = NULL;
}
void search(StudentList *listStudents,StudentList *correspondingStudentsList,char *chain,int choice)
{
	Student *currentStudent = listStudents->firstStudent;
	char *position = NULL;

	upperCase(chain);//put each character of the chain in uppercase letters

	while(currentStudent != NULL)
	{
		//To choose to search by name or by id
		if (choice == 1)
		{
			position = strstr(currentStudent->name,chain);
		}else
		{
			position = strstr(currentStudent->id,chain);
		}

		if (position != NULL)
		{
			//All the corresponding students in the main link list are added to a new link list
			addStudent(correspondingStudentsList,currentStudent->name,currentStudent->id,currentStudent->age,currentStudent->score);
			Student *currentCorrespondingStudent = correspondingStudentsList->firstStudent;

			while(currentCorrespondingStudent->nextStudent != NULL)
			{
				currentCorrespondingStudent = currentCorrespondingStudent->nextStudent;
			}
			/*since the rank of a student is initialised when that student is added to the link list 
			we need to change it with that of the current student in the main linked list*/
			currentCorrespondingStudent->rank = currentStudent->rank;
		}
		currentStudent = currentStudent->nextStudent;
	}
}
void deleteOneStudent(StudentList *listStudents,char *chain)
{
	Student *previousStudent = listStudents->firstStudent,*currentStudent = listStudents->firstStudent,*toDelete = NULL;

	while(currentStudent != NULL)
	{
		char *position = strstr(currentStudent->name,chain);//deletes only the student which contains chain

		if (position != NULL)
		{//all the cases are taken into consideration
			toDelete = currentStudent;
			if (currentStudent == listStudents->firstStudent)
			{
				listStudents->firstStudent = listStudents->firstStudent->nextStudent;//To link the students before and after the one that was deleted
			}
			previousStudent->nextStudent = currentStudent->nextStudent;//To link the students before and after the one that was deleted
			free(toDelete);
			break;
		} 
		previousStudent = currentStudent;
		currentStudent = currentStudent->nextStudent;
	}
}
void copyStudent(Student *student1,Student *student2)
{
	strcpy(student1->name,student2->name);
	strcpy(student1->id,student2->id);
	student1->age = student2->age;
	student1->rank = student2->rank;
	student1->score[MATH_INDEX] = student2->score[MATH_INDEX];
	student1->score[ENGLISH_INDEX] = student2->score[ENGLISH_INDEX];
	student1->score[FRENCH_INDEX] = student2->score[FRENCH_INDEX];
	student1->score[PHYSICS_INDEX] = student2->score[PHYSICS_INDEX];
	student1->score[COMPUTER_INDEX] = student2->score[COMPUTER_INDEX];
	student1->average = student2->average;
}
void exchangeStudents(Student *student1,Student *student2)
{
	Student *student3 = (Student*)malloc(sizeof(Student));

	copyStudent(student3,student2);
	copyStudent(student2,student1);
	copyStudent(student1,student3);
	free(student3);
}
void sortStudents(StudentList *listStudents)
{
	Student *currentStudent = listStudents->firstStudent;
	int sort = 0;

	while(currentStudent != NULL)
	{
		Student *toExchange = currentStudent->nextStudent;

		while(toExchange != NULL)
		{
			sort = isSortAlphabetic(currentStudent->name,toExchange->name);
			//if the first name comes after the second name in alphabetical order
			if (sort == 0)
			{
				exchangeStudents(currentStudent,toExchange);
			}
			toExchange = toExchange->nextStudent;
		}
		currentStudent = currentStudent->nextStudent;
	}
}
void getBestAverage(StudentList *listStudents)
{
	Student *currentStudent = listStudents->firstStudent;

	listStudents->bestAverage = 0;

	while(currentStudent != NULL)
	{
		if (listStudents->bestAverage < currentStudent->average)
		{
			listStudents->bestAverage = currentStudent->average;
		}
		currentStudent = currentStudent->nextStudent;
	}
}
void getWorstAverage(StudentList *listStudents)
{
	Student *currentStudent = listStudents->firstStudent;

	listStudents->worstAverage = 20;

	while(currentStudent != NULL)
	{
		if (listStudents-> worstAverage > currentStudent->average)
		{
			listStudents->worstAverage = currentStudent->average;
		}
		currentStudent = currentStudent->nextStudent;
	}	
}
void getClassAverage(StudentList *listStudents)
{
	Student *currentStudent = listStudents->firstStudent;

	while(currentStudent != NULL)
	{//sums the different averages of eavh student of the class
		listStudents->classAverage += currentStudent->average;
		currentStudent = currentStudent->nextStudent;
	}//divides the sum of the averages of each student by the number of students
	listStudents->classAverage /= listStudents->effectiveNumber;
}
void adjustRankingExAequo(StudentList *listStudents)
{
	Student *currentStudent = listStudents->firstStudent;

	while(currentStudent != NULL)
	{
		Student *exAequoStudent = currentStudent->nextStudent;

		while(exAequoStudent != NULL)
		{
			if (currentStudent->average == exAequoStudent->average)
			{
				int rank1 = currentStudent->rank,rank2 = exAequoStudent->rank;

				currentStudent->rank = ((rank1 < rank2)?rank1:rank2);
				exAequoStudent->rank = ((rank1 < rank2)?rank1:rank2);
			}
			exAequoStudent = exAequoStudent->nextStudent;
		}
		currentStudent = currentStudent->nextStudent;
	}
}
void controlRanking(StudentList *listStudents)
{
	Student *currentStudent = listStudents->firstStudent;

	listStudents->effectiveNumber = 0;

	while(currentStudent != NULL)
	{
		listStudents->effectiveNumber++;
		currentStudent->rank = listStudents->effectiveNumber;
		currentStudent = currentStudent->nextStudent;
	}//recounts the number of students in the class
}
void updateStudentListInfo(StudentList *listStudents)
{
	sortStudentsByRank(listStudents);
	controlRanking(listStudents);
	adjustRankingExAequo(listStudents);
	getClassAverage(listStudents);
	getBestAverage(listStudents);
	getWorstAverage(listStudents);
}
void printStudentListInfo(StudentList *listStudents)
{
	printf("------------------------------------------------------------------------------------\n");
	printf("The class has an effective of %d students\n", listStudents->effectiveNumber);
	printf("The maximum average is %3.3f/20\n",listStudents->bestAverage);
	printf("The minimum average is %3.3f/20\n",listStudents->worstAverage);
	printf("The class has a general average of %3.3f/20\n",listStudents->classAverage);
}
void sortStudentsByRank(StudentList *listStudents)
{
	Student *currentStudent = listStudents->firstStudent;

	while(currentStudent != NULL)
	{
		Student *toExchange = currentStudent->nextStudent;

		while(toExchange != NULL)
		{
			if (currentStudent->average < toExchange->average)
			{
				exchangeStudents(currentStudent,toExchange);
			}
			toExchange = toExchange->nextStudent;
		}
		currentStudent = currentStudent->nextStudent;
	}
}