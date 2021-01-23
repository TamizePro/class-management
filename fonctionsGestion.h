typedef struct Student Student;
struct Student
{
	char name[40],id[11];
	int age;
	float score[5],average;
	Student *nextStudent;
};
void initialise(Student **chain,int tableSize);
void showInfoStudents(Student **chain,int tableSize);
int hash(char chain[]);
Student* searchHashTable(char *chain);
void addStudent(Student **table,char* nameStudent,char* idStudent,int ageStudent,float studentScore[],int sizeScoreTable);
void deleteStudents(Student **table,int tableSize);
void userInterface();
float studentAverage(float *studentScore,int sizeScoreTable);