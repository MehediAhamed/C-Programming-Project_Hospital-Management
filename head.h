#pragma once
// foreground light colours
#define fgBlack "\e[30m"
#define fgRed "\e[31m"
#define fgGreen "\e[32m"
#define fgYellow "\e[33m"
#define fgBlue "\e[34m"
#define fgMagenta "\e[35m"
#define fgCyan "\e[36m"
// back ground colours
#define bgBlack "\e[40m"
#define bgRed "\e[41m"
#define bgGreen "\e[42m"
#define bgYellow "\e[43m"
#define bgBlue "\e[44m"
#define bgMagenta "\e[45m"
#define bgCyan "\e[46m"
#define bgWhite "\e[47m"
#define Reset "\e[0m"

void txtColor(char a[]);
void bgColor( char b[]);
// FUNCTION DECLERATION
void welcomeScreen(void);      // welcomeScreen function decleration
void titleShow(void);          // titleShow function decleration
void mainMenu(void);           // mainMenu function decleration
void loginScreen(void);        // loginScreen function decleration
void addRecord(void);          // addRecord function declaration
void exitFunc(void);           // exitFunc function declaration
void listFunc();               // listFunc to list the patient details
void recordFind(void);         // recordFind function declaration
void recordEdit(void);         // recordEdit function declaration
void recordDelete(void);       // recordDelete function declaration
void gotoxy(short x, short Y); // Defines gotoxy() for ANSI C compilers.
void billPrint();              // Prints patient's bill

typedef struct Patient // list of global variables
{

    int Age;
    char Gender, Doctor[20];
    char firstName[20], lastName[20];
    char contactNo[15], Problem[20];
    char Address[60],Bgroup[10];
    char Covid[4],Nurse[20];
    char Date[11];
    int bedNo,oxygen,nDay;
} patient;

patient p, temp; //Global Variable