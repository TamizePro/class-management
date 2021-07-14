#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "save-load-functions.h"
#define TAILLE_MAX 104
#define MATH_INDEX 0
#define ENGLISH_INDEX 1
#define FRENCH_INDEX 2
#define PHYSICS_INDEX 3
#define COMPUTER_INDEX 4

void saveData(StudentList *listStudents)
{
	FILE *saveFile = NULL;

	saveFile = fopen("save.ajud","w+");

	if (saveFile != NULL)
    {
    	Student *currentStudent = listStudents->firstStudent;

    	while(currentStudent != NULL)
    	{
    		controlChain(currentStudent->name);
    		controlChain(currentStudent->id);
    		fprintf(saveFile,"%s %s %d ",currentStudent->name,currentStudent->id,currentStudent->age);
    		fprintf(saveFile, "%3.3f ",currentStudent->score[MATH_INDEX]);
    		fprintf(saveFile, "%3.3f ",currentStudent->score[ENGLISH_INDEX]);
    		fprintf(saveFile, "%3.3f ",currentStudent->score[FRENCH_INDEX]);
    		fprintf(saveFile, "%3.3f ",currentStudent->score[PHYSICS_INDEX]);
    		fprintf(saveFile, "%3.3f\n",currentStudent->score[COMPUTER_INDEX]);
    		currentStudent = currentStudent->nextStudent;
    	}
    	fclose(saveFile);
    }
    else
    {
    	printf("The save file cannot be opened! Please try again later!!\n");
    }
}
void loadData(StudentList *listStudents)
{
	FILE *saveFile = NULL;
	char data[TAILLE_MAX] = "",studentName[40],studentId[15];
    int studentAge = 0;
    float studentScore[5];

	saveFile = fopen("save.ajud","r");

	if (saveFile != NULL)
    {
        while(fgets(data,TAILLE_MAX,saveFile) != NULL)
        {
            sscanf(data, "%s %s %d %f %f %f %f %f", studentName, studentId, &studentAge, studentScore+MATH_INDEX,
                studentScore+ENGLISH_INDEX, studentScore+FRENCH_INDEX,  studentScore+PHYSICS_INDEX,  studentScore+COMPUTER_INDEX);
            treatName(studentName);
            addStudent(listStudents,studentName,studentId,studentAge,studentScore);
        }
        fclose(saveFile);
    }
    else
    {
    	printf("The save file cannot be opened! Please try again later!!\n");
    }
}
void treatName(char *chain)
{
    int i = 0;

    while(chain[i] != '\0')
    {
        i++;
    }
    if (chain[i] == '\0')
    {
        chain[i] = '\n';
        chain[i+1] = '\0';
    }
}