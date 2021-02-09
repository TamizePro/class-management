#include "major-management-functions.h"
#include "minor-management-functions.h"

void saveData(StudentList *listStudents);//empties the savefile before writing in it
void loadData(StudentList *listStudents);//reads the save file
void partitionData(char *mainChain,char *studentName,char *studentId,int *studentAge,float *studentScore);
//segments the data in a given line of the file
void treatName(char *chain);//reputs the '\n' character