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
    		fprintf(saveFile,"%s;%s;%d;",currentStudent->name,currentStudent->id,currentStudent->age);
    		fprintf(saveFile, "%f;",currentStudent->score[MATH_INDEX]);
    		fprintf(saveFile, "%f;",currentStudent->score[ENGLISH_INDEX]);
    		fprintf(saveFile, "%f;",currentStudent->score[FRENCH_INDEX]);
    		fprintf(saveFile, "%f;",currentStudent->score[PHYSICS_INDEX]);
    		fprintf(saveFile, "%f\n",currentStudent->score[COMPUTER_INDEX]);
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
	char data[TAILLE_MAX] = "",studentName[40],studentId[11];
    int studentAge = 0;
    float studentScore[5];

	saveFile = fopen("save.ajud","r");

	if (saveFile != NULL)
    {
        while(fgets(data,TAILLE_MAX,saveFile) != NULL)
        {
            partitionData(data,studentName,studentId,&studentAge,studentScore);
            treatName(studentName);
            addStudent(listStudents,studentName,studentId,studentAge,studentScore,5);
        }
        fclose(saveFile);
    }
    else
    {
    	printf("The save file cannot be opened! Please try again later!!\n");
    }
}
void partitionData(char *mainChain,char *studentName,char *studentId,int *studentAge,float *studentScore)
{
    char *string = NULL;

    string = strtok(mainChain,";");
    for (int i = 0; i < 8; ++i)
    {
        switch(i)
        {
            case 0:
                strcpy(studentName,string);
                break;
            case 1:
                strcpy(studentId,string);
                break;
            case 2:
                *studentAge = (int)strtol(string,NULL,10);
                break;
            case 3:
                studentScore[MATH_INDEX] = (float)strtod(string,NULL);
                break;
            case 4:
                studentScore[ENGLISH_INDEX] = (float)strtod(string,NULL);
                break;
            case 5:
                studentScore[FRENCH_INDEX] = (float)strtod(string,NULL);
                break;
            case 6:
                studentScore[PHYSICS_INDEX] = (float)strtod(string,NULL);
                break;
            case 7:
                studentScore[COMPUTER_INDEX] = (float)strtod(string,NULL);
                break;
        }
        string = strtok(NULL,";");
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