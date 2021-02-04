typedef struct Student Student;
struct Student
{
	char name[40],id[15];
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
void searchUserInterface(StudentList *listStudents);
void copyStudent(Student *student1,Student *student2);
void exchangeStudents(Student *student1,Student *student2);
void sortStudents(StudentList *listStudents);
void deleteOneStudent(StudentList *listStudents,char *chain);
void search(StudentList *listStudents,StudentList *correspondingStudentsList,char *chain,int sizeScoreTable);
void getStudentInfo(StudentList *listStudents,char *nameStudent,char *idStudent,int ageStudent, float *scoreStudent,int sizeScoreTable);