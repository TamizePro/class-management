typedef struct Student Student;
struct Student//contains the personal information of each student
{
	char name[40],id[15];
	int age,rank;
	float score[5],average;
	Student *nextStudent;
};
typedef struct StudentList StudentList;
struct StudentList//contains the general information about the class or listof students
{
	Student *firstStudent;
	int effectiveNumber;
	float classAverage,bestAverage,worstAverage;
};
StudentList* initialise();//generates a list of students and initialises all the sub-variables
int isUnique(StudentList *listStudents,char *chain);//checks if the identification number of a given student is not that of a different student
void showInfoStudents(StudentList *listStudents);//shows the information of all the students
void updateStudentListInfo(StudentList *listStudents);//updates the information of the class
void getBestAverage(StudentList *listStudents);//gets the highest average of the class
void getWorstAverage(StudentList *listStudents);//gets the lowest average of the class
void getClassAverage(StudentList *listStudents);//gets the general average of the class
void addStudent(StudentList *listStudents,char* nameStudent,char* idStudent,int ageStudent,float studentScore[]);
//adds a new student at the end of the link list
void deleteStudents(StudentList *listStudents);//deletes all the students from the list
void userInterface();//a basic visual interface to facilitate the manipulation of the program
void searchUserInterface(StudentList *listStudents);//a sub menu to ease research
void printSearchResults(StudentList *listStudents,StudentList *correspondingStudentsList,char *chain,int *subChoice1,int *subChoice2);//prints the results of the search
void copyStudent(Student *student1,Student *student2);//copies the information of a student into another
void exchangeStudents(Student *student1,Student *student2);//exchanges the information of 2 students
void sortStudents(StudentList *listStudents);//sorts the students in alphabetical order
void deleteOneStudent(StudentList *listStudents,char *chain);//deletes a particular student
void search(StudentList *listStudents,StudentList *correspondingStudentsList,char *chain,int choice);
//searches for a particular student  based on the name or id
void getUniqueId(StudentList *listStudents,char *idStudent);//receives the id entered by the user only if it is not owned by another
void getStudentInfo(StudentList *listStudents,char *nameStudent,char *idStudent,int ageStudent, float *scoreStudent);
//gets the student's information before adding it
void printStudentListInfo(StudentList *listStudents);//shows the general information of the list of students or class
void printStudentInfo(Student *student1);//shows the information of a given student
void controlRanking(StudentList *listStudents);//ensures the ranking is proper especially after a student was deleted
void adjustRankingExAequo(StudentList *listStudents);//adjusts the ranking to show which students have the same rank
void sortStudentsByRank(StudentList *listStudents);//sorts the students by rank