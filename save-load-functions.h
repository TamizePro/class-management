#include "major-management-functions.h"
#include "minor-management-functions.h"

void saveData(StudentList *listStudents);
void loadData(StudentList *listStudents);
void partitionData(char *mainChain,char *studentName,char *studentId,int *studentAge,float *studentScore);
void treatName(char *chain);