char ans = 0;
int ok, b, valid = 0;

void txtColor(char a[])
{
    printf("%s", a);
}

void bgColor(char b[])
{
    printf("%s", b);
}

void welcomeScreen(void) // function for welcome screen
{
    printf("\n\n\n\n\n\n");
    bgColor(bgCyan);
    txtColor(fgRed);
    printf("\n\t\t\t\t*****************************************");
    printf("\n\t\t\t\t|                WELCOME TO             |");
    printf("\n\t\t\t\t|     IUT HOSPITAL MANAGEMENT SYSTEM    |");
    printf("\n\t\t\t\t*****************************************");
    txtColor(Reset);
    bgColor(Reset);
    printf("\n\n\n\n\n PRESS ANY KEY TO CONTINUE-\n\n\n");
    getch(); // Use to hold screen for some seconds
    txtColor(fgGreen);
    printf("\n\n\t\t\t\t\tLOADING");
    for (int i = 0; i < 4; i++)
    {
        Sleep(600);
        printf("...");
    }
    txtColor(Reset);
    system("cls"); // Use to clear the screen
}

void titleShow(void) // function for title screen
{
    bgColor(bgCyan);
    txtColor(fgRed);
    printf("\n\n");
    printf("\t\t---------------------------------------------------------------------------------\n");
    printf("\t\t|                          >>>>   IUT HOSPITAL   <<<<                           |");
    printf("\n\t\t---------------------------------------------------------------------------------");
    txtColor(Reset);
    bgColor(Reset);
}

void mainMenu(void) // function decleration
{
    while (1)
    {
        system("cls");
        int choose;
        titleShow(); // call Title function
        printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
        printf("\n\t\t\t\t2. List Patients Record\n");
        printf("\n\t\t\t\t3. Search Patients Record\n");
        printf("\n\t\t\t\t4. Edit Patients Record\n");
        printf("\n\t\t\t\t5. Delete Patients Record\n");
        printf("\n\t\t\t\t6. Create the Bill Receipt\n");
        printf("\n\t\t\t\t7. Exit\n");
        printf("\n\n\n\n");
        txtColor(fgMagenta);
        printf("\t\t\t\tChoose from 1 to 7: ");
        scanf("%i", &choose);
        txtColor(Reset);

        switch (choose) // switch to differeht case
        {
        case 1:
            addRecord(); // Add_rec function is called
            break;
        case 2:
            listFunc(); // list view function is called
            break;
        case 3:
            recordFind(); // find function is called
            break;
        case 4:
            recordEdit(); // Edit function is called
            break;
        case 5:
            recordDelete(); // Delete function is called
            break;
        case 6:
            billPrint(); // bill function is called
            break;
        case 7:
            exitFunc(); // exit function is called
            break;
        default:
            printf("\t\t\t\t>>> INVALID ENTRY <<<\n\t\t\tPLEASE ENTER A VALID OPTION\n");
            getch(); // holds screen
        }            // end of switch
    }
}

void loginScreen(void) // function for login screen
{
    // list of variables
    int chance = 3;
    char Username[15];
    char Password[15];
    char original_Username[25] = "HappyCoding";
    char original_Password[15] = "HappyCoding";

    do
    {
        printf("\n\n\n");
        txtColor(fgRed);
        printf("\n\t\t\t\tEnter Your Username and Password Please :- ");
        txtColor(Reset);
        txtColor(fgMagenta);
        printf("\n\n\n\t\t\t\t\tUSERNAME : ");
        txtColor(Reset);
        scanf("%s", &Username);
        txtColor(fgMagenta);
        printf("\n\t\t\t\t\tPASSWORD : ");
        txtColor(Reset);
        scanf("%s", &Password);

        if (strcmp(Username, original_Username) == 0 && strcmp(Password, original_Password) == 0)
        {
            printf("\n\n\n");
            bgColor(bgWhite);
            txtColor(fgGreen);
            printf("\t\t\t\t\t>>> LOGIN SUCCESSFUL <<<");
            getch();
            txtColor(Reset);
            bgColor(Reset);
            mainMenu(); // call MainMenu function
            break;
        }
        else
        {
            system("color 4");
            chance--;
            bgColor(bgYellow);
            printf("\n\t\t\t\t  Password Is Incorrect (Try Again Please)");
            printf("\n\t\t\t\t\t>>> %d TRY(S) REMAINING <<<", chance);
            getch();
            bgColor(Reset);
            system("cls");
        }

    } while (chance);
    if (!chance)
    {
        system("color 4");
        printf("\n\t\t\t You have crossed the limit. You cannot login, sorry~");
        getch();
        exitFunc(); // function to exit
    }
    system("cls");
}

void exitFunc(void) // function to exit
{
    system("cls");
    titleShow(); // call Title function
    printf("\n\n\n\n\n\n\n");
    bgColor(bgYellow);
    txtColor(fgMagenta);
    printf("                                    >>> THANK YOU FOR VISITING. STAY SAFE <<<                                  ");
    getch(); // holds screen
    txtColor(Reset);
    bgColor(Reset);
    system("cls");
    exit(0);
}

/* **************************************ADD RECORD*******************************************/

void addRecord(void)
{
    system("cls");
    titleShow(); // call Title function
    // list of variables
    char ans;
    FILE *fp;                       // file pointer
    fp = fopen("Record2.txt", "a"); // open file in write mode
    bgColor(bgYellow);
    txtColor(fgMagenta);
    printf("\n\n\t\t\t<<<*^*^*^*^*^*>>>       Add Patients Record       <<<*^*^*^*^*^*>>>\n");
    txtColor(Reset);
    bgColor(Reset);

    /******************************************First Name************************************************/
    do
    {
        txtColor(fgGreen);
        printf("\n\t\t\tFirst Name\t: ");
        txtColor(Reset);
        scanf("%s", p.firstName);
        p.firstName[0] = toupper(p.firstName[0]);
        if (strlen(p.firstName) > 20 || strlen(p.firstName) < 2)
        {
            valid = 0;
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\tThe Max Range For First Name is 20 and Min Range is 2 !!!\n");
            getch();
            txtColor(Reset);
        }
        else
        {
            for (b = 0; b < strlen(p.firstName); b++)
            {
                if (isalpha(p.firstName[b]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (valid == 0)
            {
                txtColor(fgRed);
                printf("\n\n\t\t\t\tFirst Name Contains Invalid Character. Enter Again Please-\n");
                getch();
                txtColor(Reset);
            }
        }
    } while (valid == 0);

    /* ******************************************** Last name ********************************************* */
    do
    {
        txtColor(fgGreen);
        printf("\n\t\t\tLast Name\t: ");
        txtColor(Reset);
        scanf("%s", p.lastName);
        p.lastName[0] = toupper(p.lastName[0]);
        if (strlen(p.lastName) > 20 || strlen(p.lastName) < 2)
        {
            valid = 0;
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\tThe Max Range For Last Name is 20 and Min Range is 2 !!!\n");
            getch();
            txtColor(Reset);
        }
        else
        {
            for (b = 0; b < strlen(p.lastName); b++)
            {
                if (isalpha(p.lastName[b]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (valid == 0)
            {
                txtColor(fgRed);
                printf("\n\n\t\t\t\tLast Name Contains Invalid Character. Enter Again Please-\n");
                getch();
                txtColor(Reset);
            }
        }
    } while (!valid);
    /* ***************************************** Gender ************************************************ */
    do
    {
        txtColor(fgGreen);
        printf("\n\t\t\tGender[F/M]\t: ");
        txtColor(Reset);
        scanf(" %c", &p.Gender);
        p.Gender = toupper(p.Gender);
        if (p.Gender == 'M' || p.Gender == 'F')
            ok = 1;
        else
            ok = 0;
        if (!ok)
        {
            txtColor(fgRed);
            printf("\n\t\t\t\tGender Contains Invalid character. Enter Either F or M !!!\n");
            txtColor(Reset);
        }
    } while (!ok);
    /* ***************************************** Age ********************************************************************** */
    do
    {
        txtColor(fgGreen);
        printf("\n\t\t\tAge\t\t: ");
        txtColor(Reset);
        scanf(" %d", &p.Age);
        if (p.Age < 1 || p.Age > 130)
        {
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\t\t    Please Enter Your Age Agian-\n");
            txtColor(Reset);
        }
    } while (p.Age < 1 || p.Age > 130);
    /* **************************************** Address ******************************************************************* */
    do
    {
        valid = 1;
        txtColor(fgGreen);
        printf("\n\t\t\tAddress\t\t: ");
        txtColor(Reset);
        scanf("%s", p.Address);
        p.Address[0] = toupper(p.Address[0]);
        if (strlen(p.Address) > 20 || strlen(p.Address) < 3)
        {
            valid = 0;
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\tThe Max Range For Address is 20 and Min Range is 3 !!!\n");
            txtColor(Reset);
        }
    } while (!valid);
    /* ******************************************* Contact no. ***************************************** */
    do
    {
        valid = 1;
        txtColor(fgGreen);
        printf("\n\t\t\tContact no\t: ");
        txtColor(Reset);
        scanf("%s", p.contactNo);
        if (strlen(p.contactNo) != 11)
        {
            valid = 0;
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\t    The Contact No. Must Contain 11 Numbers !!!\n");
            txtColor(Reset);
        }
        else
        {
            for (b = 0; b < strlen(p.contactNo); b++)
            {
                if (p.contactNo[b] == '0' || p.contactNo[b] == '1' || p.contactNo[b] == '2' || p.contactNo[b] == '3' || p.contactNo[b] == '4' || p.contactNo[b] == '5' || p.contactNo[b] == '6' || p.contactNo[b] == '7' || p.contactNo[b] == '8' || p.contactNo[b] == '9')
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                txtColor(fgRed);
                printf("\n\t\t\t\tContact No. Contains Invalid Character. Please Enter again-\n");
                txtColor(Reset);
            }
        }
    } while (!valid);

    /* ******************************************* Blood Group ***************************************** */
    do
    {
        valid = 1;
        txtColor(fgGreen);
        printf("\n\t\t\tBlood Group\t: ");
        txtColor(Reset);
        scanf("%s", p.Bgroup);
        p.Bgroup[0] = toupper(p.Bgroup[0]);
        if (strlen(p.Bgroup) > 3 || strlen(p.Bgroup) < 1)
        {
            valid = 0;
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\tThe Max Range For Blood Group is 5 and Min Range is 3 !!!\n");
            txtColor(Reset);
        }
    } while (!valid);
    /* ************************************************** Date of Admission ******************************************** */
    do
    {
        valid = 1;
        txtColor(fgGreen);
        printf("\n\t\t\tAdmission date (DD/MM/YYYY): ");
        txtColor(Reset);
        scanf("%s", p.Date);
        if (strlen(p.Date) > 10 || strlen(p.Date) < 6)
        {
            valid = 0;
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\t    Please Enter Date Again- !!!\n");
            txtColor(Reset);
        }
        else
        {
            for (b = 0; b < strlen(p.Date); b++)
            {
                if (p.Date[b] == '-' || p.Date[b] == '/' || p.Date[b] == '0' || p.Date[b] == '1' || p.Date[b] == '2' || p.Date[b] == '3' || p.Date[b] == '4' || p.Date[b] == '5' || p.Date[b] == '6' || p.Date[b] == '7' || p.Date[b] == '8' || p.Date[b] == '9')
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                txtColor(fgRed);
                printf("\n\t\t\t\tPlease Enter Date Again-\n");
                txtColor(Reset);
            }
        }
    } while (!valid);
    /* *******************************************************bed no****************************************************/
    char yesNo[4];
    do
    {
        txtColor(fgGreen);
        printf("\n\t\t\tBed Taken(YES/NO)?\t: ");
        txtColor(Reset);
        scanf("%s", yesNo);
        strupr(yesNo);
        p.bedNo = 0;
        if (strcmp(yesNo, "YES") != 0 && strcmp(yesNo, "NO") != 0)
        {
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\t\t\tPlease Enter Agian !!!\n");
            txtColor(Reset);
        }
        if (strcmp(yesNo, "YES") == 0)
        {
            txtColor(fgGreen);
            printf("\n\t\t\tBed No.\t\t: ");
            txtColor(Reset);
            scanf(" %d", &p.bedNo);
        }
    } while (strcmp(yesNo, "YES") != 0 && strcmp(yesNo, "NO") != 0);
    /* ********************************************************* Problem *********************************************** */
    valid = 1;
    do
    {
        txtColor(fgGreen);
        printf("\n\t\t\tProblem\t\t: ");
        txtColor(Reset);
        scanf("%s", p.Problem);
        p.Problem[0] = toupper(p.Problem[0]);
        if (strlen(p.Problem) > 15 || strlen(p.Problem) < 3)
        {
            valid = 0;
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\tThe Max Range For Problem is 15 and Min Range is 3 !!!\n");
            txtColor(Reset);
        }
        else
        {
            for (b = 0; b < strlen(p.Problem); b++)
            {
                if (isalpha(p.Problem[b]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                txtColor(fgRed);
                printf("\n\t\t\t\tProblem Contains Invalid Characters. Enter Again Please-\n");
                txtColor(Reset);
            }
        }
    } while (!valid);
    /* ********************************************** Prescribed Doctor **************************************** */
    valid = 1;
    do
    {
        txtColor(fgGreen);
        printf("\n\t\t\tPrescribed Doctor : ");
        txtColor(Reset);
        scanf("%s", p.Doctor);
        p.Doctor[0] = toupper(p.Doctor[0]);
        if (strlen(p.Doctor) > 30 || strlen(p.Doctor) < 3)
        {
            valid = 0;
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\tThe Max Range For Problem is 30 and Min Range is 3 !!!\n");
            txtColor(Reset);
        }
        else
        {
            for (b = 0; b < strlen(p.Doctor); b++)
            {
                if (isalpha(p.Doctor[b]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                txtColor(fgRed);
                printf("\n\t\t\t\t Doctor Name Contain Invalid Character. Please Enter Again-\n");
                txtColor(Reset);
            }
        }
    } while (!valid);
    /*************************************************************covid**************************************************************/
    do
    {
        txtColor(fgGreen);
        printf("\n\t\t\tCOVID Positive(YES/NO)?\t: ");
        txtColor(Reset);
        scanf("%s", p.Covid);
        strupr(p.Covid);
        if (strcmp(p.Covid, "YES") != 0 && strcmp(p.Covid, "NO") != 0)
        {
            txtColor(fgRed);
            printf("\n\t\t\t\t\t\t>>> Invalid Input <<<\n\n\t\t\t\t\t\tPlease Enter Agian !!!\n");
            txtColor(Reset);
        }

    } while (strcmp(p.Covid, "YES") != 0 && strcmp(p.Covid, "NO") != 0);

    fprintf(fp, "%s %s %c %d %s %s %s %d %s %s %s %s\n", p.firstName, p.lastName, p.Gender, p.Age, p.Address, p.contactNo, p.Date, p.bedNo,p.Bgroup, p.Problem, p.Doctor, p.Covid);
    txtColor(fgGreen);
    printf("\n\n\t\t\t\t>>>>>>.... Information Record Successful ....<<<<<<\n");
    txtColor(Reset);
    fclose(fp); // fp file is closed
    do
    {
        valid = 1;
        getch();
        txtColor(fgMagenta);
        printf("\n\n\t\t\tDo you want to add more[Y/N]?? : ");
        txtColor(Reset);
        scanf(" %c", &ans);
        if (toupper(ans) == 'Y')
        {
            addRecord();
        }
        else if (toupper(ans) == 'N')
        {
            system("cls");
            txtColor(fgCyan);
            printf("\n\n\n\n\n\n\t\t\tThank You. Press Any Key to Move TO MAINMENU\n");
            txtColor(Reset);
            getch();
            mainMenu();
        }
        else
        {
            valid = 0;
            txtColor(fgRed);
            printf("\n\t\t\t\t>>> Invalid Input <<<\n");
            txtColor(Reset);
        }
    } while (!valid);
}