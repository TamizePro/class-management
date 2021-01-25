#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctionsGestion.h"
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
		printf("--------------------------------------------------------------------------\n");
		printf("Name: %s",currentStudent->name);
		printf("Id: %s\n",currentStudent->id);
		printf("Age: %d\n",currentStudent->age);
		printf("Score in Maths: %f\n",currentStudent->score[MATH_INDEX]);
		printf("Score in English: %f\n",currentStudent->score[ENGLISH_INDEX]);
		printf("Score in French: %f\n",currentStudent->score[FRENCH_INDEX]);
		printf("Score in Physics: %f\n",currentStudent->score[PHYSICS_INDEX]);
		printf("Score in Computer Science: %f\n",currentStudent->score[COMPUTER_INDEX]);
		printf("Overall average: %f\n",currentStudent->average);
		currentStudent = currentStudent->nextStudent;
	}
}
float studentAverage(float *studentScore,int sizeScoreTable)
{
	int mean = 0;

	for (int i = 0; i < sizeScoreTable; ++i)
	{
		mean += studentScore[i];
	}
	mean /= sizeScoreTable;

	return mean;
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
