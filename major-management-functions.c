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

	return listStudents;
}
void showInfoStudents(StudentList *listStudents)
{
	Student *currentStudent = listStudents->firstStudent;

	while(currentStudent != NULL)
	{
		printf("------------------------------------------------------------------------------------\n");
		printf("Name: %s",currentStudent->name);
		printf("Id: %s\n",currentStudent->id);
		printf("Age: %d\n",currentStudent->age);
		printf("Score in Maths: %3.3f\n",currentStudent->score[MATH_INDEX]);
		printf("Score in English: %3.3f\n",currentStudent->score[ENGLISH_INDEX]);
		printf("Score in French: %3.3f\n",currentStudent->score[FRENCH_INDEX]);
		printf("Score in Physics: %3.3f\n",currentStudent->score[PHYSICS_INDEX]);
		printf("Score in Computer Science: %3.3f\n",currentStudent->score[COMPUTER_INDEX]);
		printf("Overall average: %3.3f\n",currentStudent->average);
		currentStudent = currentStudent->nextStudent;
	}
}
void addStudent(StudentList *listStudents,char* nameStudent,char* idStudent,int ageStudent,float studentScore[],int sizeScoreTable)
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
	newStudent->average = studentAverage(studentScore,sizeScoreTable);
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
void getStudentInfo(StudentList* listStudents,char* nameStudent,char* idStudent,int ageStudent, float* scoreStudent,int sizeScoreTable)
{
	printf("------------------------------------------------------------------------------------\n");
	printf("Name: ");
	fgets(nameStudent,40,stdin);
	upperCase(nameStudent);
	printf("Id: ");
	fgets(idStudent,15,stdin);
	printf("Age: ");
	scanf("%d",&ageStudent);
	printf("Score in Maths: ");
	scanf("%f",scoreStudent+MATH_INDEX);
	printf("Score in English: ");
	scanf("%f",scoreStudent+ENGLISH_INDEX);
	printf("Score in French: ");
	scanf("%f",scoreStudent+FRENCH_INDEX);
	printf("Score in Physics: ");
	scanf("%f",scoreStudent+PHYSICS_INDEX);
	printf("Score in Computer Science: ");
	scanf("%f",scoreStudent+COMPUTER_INDEX);
	getchar();
	addStudent(listStudents,nameStudent,idStudent,ageStudent,scoreStudent,sizeScoreTable);
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
void search(StudentList *listStudents,StudentList *correspondingStudentsList,char *chain,int sizeScoreTable)
{
	Student *currentStudent = listStudents->firstStudent;

	upperCase(chain);

	while(currentStudent != NULL)
	{
		char *position = strstr(currentStudent->name,chain);

		if (position != NULL)
		{
			addStudent(correspondingStudentsList,currentStudent->name,currentStudent->id,currentStudent->age,currentStudent->score,sizeScoreTable);
		}
		currentStudent = currentStudent->nextStudent;
	}
}
void deleteOneStudent(StudentList *listStudents,char *chain)
{
	Student *previousStudent = listStudents->firstStudent,*currentStudent = listStudents->firstStudent,*toDelete = NULL;

	while(currentStudent != NULL)
	{
		char *position = strstr(currentStudent->name,chain);

		if (position != NULL)
		{
			toDelete = currentStudent;
			if (currentStudent == listStudents->firstStudent)
			{
				listStudents->firstStudent = listStudents->firstStudent->nextStudent;
			}
			previousStudent->nextStudent = currentStudent->nextStudent;
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
		Student *toExchange =currentStudent->nextStudent;

		while(toExchange != NULL)
		{
			sort = isSortAlphabetic(currentStudent->name,toExchange->name);
			if (sort == 0)
			{
				exchangeStudents(currentStudent,toExchange);
			}
			toExchange = toExchange->nextStudent;
		}
		currentStudent = currentStudent->nextStudent;
	}
}