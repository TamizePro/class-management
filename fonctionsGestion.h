typedef struct Student Student;
struct Student
{
	char name[40],id[11];
	int age;
	float score[5],average;
	Student *nextStudent;
};
typedef struct StudentList StudentList;
struct StudentList
{
	Student *firstStudent;
};
StudentList* initialise();
void showInfoStudents(StudentList *listStudents);
void addStudent(StudentList *listStudents,char* nameStudent,char* idStudent,int ageStudent,float studentScore[],int sizeScoreTable);
void deleteStudents(StudentList *listStudents);
void userInterface();
float studentAverage(float *studentScore,int sizeScoreTable);