int getChoice(); //gets the choice of the user in the main menu
int getSearchOption();//gets the choice of the user in the main search menu
int getSearchChoice1();//gets the choice of the user in the first sub search menu
int getSearchChoice2();//gets the choice of the user in the second sub search menu
void printSearchMenuMain();//prints main search menu
void printMenu();//prints the main menu
void printSearchMenu1();//prints the first search sub menu
void printSearchMenu2();//prints the second search sub menu
void printSortOptions();//prints a sub menu to select the sorting order of the students
void printDeleteValidationMenu();//prints a sub menu to comfirm the deletion of the information of all the students
int getDeleteValidation();//gets the confirmation choice of the user about the information of all the information
int getStudentsOrder();//gets the  sorting choice of the user before their information is displayed
void controlChain(char *chain);//removes the character '\n' before a search is done
void upperCase(char *chain);//puts all the letters of a string in upper case letters 
int isSortAlphabetic(char *chain1,char *chain2);//tells if 2 strings are sorted alphabetically
int isSortValue(float value1,float value2);
float studentAverage(float *studentScore);//calculates the average of a student