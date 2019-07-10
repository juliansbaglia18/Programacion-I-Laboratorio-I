FILE* openFILE (char* fileName);
FILE* openFILEWrite(char* fileName);
int parser_EmployeeFromText(FILE* pFile , void* this);
int parser_EmployeeListToText (FILE* pFile, void* this);
