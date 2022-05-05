char ans1 = 0;

/* ******************************************** Set Cursor Pointer ********************************************* */

void gotoxy(short x, short y)
{
    COORD pos = {x, y}; // sets co-ordinates in (x,y).
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/* ******************************************** Deserilization ********************************************* */

void listFunc()
{
    system("cls");
    titleShow();

    FILE *fp = fopen("Record2.txt", "r");

    gotoxy(40, 12);
    txtColor(fgGreen);

    printf("############### List Patients Record ###############\n");
    txtColor(Reset);
    gotoxy(2, 15);

    txtColor(fgYellow);
    printf("| Full Name      |");

    txtColor(Reset);
    gotoxy(20, 15);

    txtColor(fgYellow);
    printf("|  Gender  |");

    txtColor(Reset);
    gotoxy(32, 15);

    txtColor(fgYellow);
    printf("|  Age |");

    txtColor(Reset);
    gotoxy(40, 15);

    txtColor(fgYellow);
    printf("|      Address       |");

    txtColor(Reset);
    gotoxy(62, 15);

    txtColor(fgYellow);
    printf("|    Contact No.    |");

    txtColor(Reset);
    gotoxy(84, 15);

    txtColor(fgYellow);
    printf("|  Blood Group |");

    txtColor(Reset);
    gotoxy(100, 15);

    txtColor(fgYellow);
    printf("|    Problem    |");

    txtColor(Reset);
    gotoxy(117, 15);

    txtColor(fgYellow);
    printf("|  Prescribed Doctor  |\n");

    txtColor(Reset);
    
    txtColor(fgYellow);
    gotoxy(1,16);
    printf("===========================================================================================================================================");

    txtColor(Reset);
    bgColor(Reset);

    int row = 18;

    while (fscanf(fp, "%s %s %c %d %s %s %s %d %s %s %s %s", p.firstName, p.lastName, &p.Gender, &p.Age, p.Address, p.contactNo,p.Date,&p.bedNo, p.Bgroup, p.Problem, p.Doctor,p.Covid) != EOF)
    {
        gotoxy(3, row);

        printf("%s %s", p.firstName, p.lastName);

        gotoxy(23, row);

        printf("%c", p.Gender);

        gotoxy(33, row);

        printf("%i", p.Age);

        gotoxy(41, row);

        printf("%s", p.Address);

        gotoxy(64, row);

        printf("%s", p.contactNo);

        gotoxy(87, row);

        printf("%s", p.Bgroup);

        gotoxy(101, row);

        printf("%s", p.Problem);

        gotoxy(118, row);

        printf("%s", p.Doctor);
        row++;
    }
    fclose(fp);

    getch();

    mainMenu();
}

/* ******************************************** Find Record ********************************************* */

void recordFind(void)
{
    char name[20];
    system("cls");

    titleShow();

    FILE *fp = fopen("Record2.txt", "r");

    gotoxy(40, 12);
    txtColor(fgGreen);

    printf("############### Find Patients Record ###############\n");
    txtColor(Reset);

    gotoxy(12, 8);
    printf("\n Enter Patient's (First) Name to be viewed: ");

    scanf("%s", name);
    fflush(stdin);

    name[0] = toupper(name[0]);

    while (fscanf(fp, "%s %s %c %d %s %s %s %d %s %s %s %s", p.firstName, p.lastName, &p.Gender, &p.Age, p.Address, p.contactNo,p.Date,&p.bedNo,p.Bgroup, p.Problem, p.Doctor,p.Covid) != EOF)
    {

        if (strcmp(p.firstName, name) == 0)
        {
            gotoxy(1, 15);
            txtColor(fgYellow);

            printf("| Full Name       |");
            txtColor(Reset);

            gotoxy(20, 15);
            txtColor(fgYellow);

            printf("|  Gender  |");
            txtColor(Reset);

            gotoxy(32, 15);
            txtColor(fgYellow);

            printf("|  Age |");
            txtColor(Reset);

            gotoxy(40, 15);
            txtColor(fgYellow);

            printf("|      Address       |");
            txtColor(Reset);

            gotoxy(62, 15);
            txtColor(fgYellow);

            printf("|   Contact No.  |");
            txtColor(Reset);

            gotoxy(80, 15);
            txtColor(fgYellow);

            printf("|      Blood Group     |");
            txtColor(Reset);

            gotoxy(88, 15);
            txtColor(fgYellow);

            printf("|       Problem      |");
            txtColor(Reset);

            gotoxy(105, 15);
            txtColor(fgYellow);

            printf("|  Prescribed Doctor  |\n");
            txtColor(Reset);

            txtColor(fgRed);

            printf("========================================================================================================================================");
            txtColor(Reset);
            bgColor(Reset);

            gotoxy(1, 18);
            printf("%s %s", p.firstName, p.lastName);

            gotoxy(20, 18);
            printf("%c", p.Gender);

            gotoxy(32, 18);
            printf("%d", p.Age);

            gotoxy(40, 18);
            printf("%s", p.Address);

            gotoxy(62, 18);
            printf("%s", p.contactNo);

            gotoxy(80, 18);
            printf("%s", p.Bgroup);

            gotoxy(88, 18);
            printf("%s", p.Problem);

            gotoxy(105, 18);
            printf("%s", p.Doctor);
            printf("\n");
            break;
        }
    }

    if (strcmp(p.firstName, name) != 0)

    {
        gotoxy(5, 10);

        txtColor(fgRed);
        printf("Record not found!");

        txtColor(Reset);
        getch();
    }
    getchar();
    fclose(fp);

    system("cls");
    int bool = 1;

    do
    {
        txtColor(fgBlue);
        printf("\n\n\t\t\tDo you want to view more[Y/N]??");

        txtColor(Reset);
        scanf("%c", &ans1);

        if (toupper(ans1) == 'Y')

        {
            recordFind();
            bool = 0;
        }

        else if (toupper(ans1) == 'N')
        {
            txtColor(fgYellow);
            printf("\n\n\t\t\t\t>>>>>>....Record Match Successful ....<<<<<<\n");

            txtColor(Reset);
            bool = 0;

            getch();
            mainMenu();
        }

        else
        {
            txtColor(fgRed);
            printf("\n\t\t\t\tInvalid Input.\n");

            txtColor(Reset);
            txtColor(fgBlue);

            printf("\n\n\t\t\tDo you want to view more[Y/N]??");
            txtColor(Reset);

            scanf("%c", &ans1);
        }

    } while (bool);
}

/* ******************************************** Edit Record ********************************************* */

void recordEdit(void)
{
    FILE *fp, *new;

    int i, b, valid = 0;
    char name[20], ch;

    system("cls");
    titleShow();

    fp = fopen("Record2.txt", "r");
    new = fopen("updated2.txt", "w");

    if ((fp == NULL) || (new = NULL))
    {
        txtColor(fgRed);
        printf("\n\t\t\t\tCan not open file!!\n");

        txtColor(Reset);
        getch();

        mainMenu();
    }
    printf("\n\n\n");
    txtColor(fgYellow);
    printf("                     ############### Edit Patients Record ###############\n");

    txtColor(Reset);
    gotoxy(12, 13);

    printf("Enter the First Name of the Patient : ");
    scanf("%s", name);

    fflush(stdin);

   // name[0] = toupper(name[0]);
    gotoxy(12, 15);

    while (fscanf(fp, "%s %s %c %d %s %s %s %d %s %s %s %s", p.firstName, p.lastName, &p.Gender, &p.Age, p.Address, p.contactNo,p.Date,&p.bedNo, p.Bgroup, p.Problem, p.Doctor,p.Covid) != EOF)
    {
        if (strcmp(p.firstName, name) == 0)
        {
            valid = 1;

            printf("\n");
            txtColor(fgGreen);

            printf("**** **** Existing Record**** ****\n");
            txtColor(Reset);

          
            printf("%s \t%s \t%c \t%i \t%s \t%d\t%s \t%s \t%s \t%s\n", p.firstName, p.lastName, p.Gender, p.Age, p.Address, p.contactNo,p.bedNo, p.Bgroup, p.Problem, p.Doctor);

            //gotoxy(12, 22);
            txtColor(fgCyan);

            printf("Enter New First Name: ");
            txtColor(Reset);

            scanf("%s", p.firstName);
            gotoxy(12, 24);

            txtColor(fgCyan);
            printf("\t\tEnter Last Name: ");

            txtColor(Reset);
            scanf("%s", p.lastName);

            gotoxy(12, 26);
            txtColor(fgCyan);

            printf("Enter Gender: ");
            txtColor(Reset);

            scanf(" %c", &p.Gender);
            p.Gender = toupper(p.Gender);

            gotoxy(12, 28);
            txtColor(fgCyan);

            printf("Enter Age: ");
            txtColor(Reset);

            scanf(" %i", &p.Age);
            gotoxy(12, 30);

            txtColor(fgCyan);
            printf("Enter Address: ");

            txtColor(Reset);
            scanf("%s", p.Address);

            p.Address[0] = toupper(p.Address[0]);

            gotoxy(12, 32);
            txtColor(fgCyan);

            printf("Enter Contact no: ");
            txtColor(Reset);

            scanf("%s", p.contactNo);
            gotoxy(12, 34);
            txtColor(fgCyan);

            printf("Enter Blood Group: ");
            txtColor(Reset);

            scanf("%s", p.Bgroup);
            gotoxy(12, 36);

            txtColor(fgCyan);
            printf("Enter Problem: ");

            txtColor(Reset);
            scanf("%s", p.Problem);

            p.Problem[0] = toupper(p.Problem[0]);

            gotoxy(12, 38);
            txtColor(fgCyan);

            printf("Enter Doctor: ");
            txtColor(Reset);
            scanf("%s", p.Doctor);

            p.Doctor[0] = toupper(p.Doctor[0]);

            txtColor(fgGreen);
            printf("\nPress U charecter for the Updating operation : ");

            txtColor(Reset);
            ch = getche();

            if (ch == 'u' || ch == 'U')
            {
               
                fprintf(new, "%s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName, p.Gender, p.Age, p.Address, p.contactNo, p.Bgroup, p.Problem, p.Doctor);
                txtColor(fgYellow);
                
                printf("\n\n\t\t\tPatient record updated successfully...");
                txtColor(Reset);

            }
        }

        else
        {
            fprintf(new, "%s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName, p.Gender, p.Age, p.Address, p.contactNo, p.Bgroup, p.Problem, p.Doctor);
        }
    }

    if (!valid)
    {
        txtColor(fgRed);
        printf("\n\t\t\t\tNO RECORD FOUND...");
        txtColor(Reset);
    }

    fclose(fp);
    fclose(new);

    remove("Record2.dat");
    rename("updated2.txt", "Record2.txt");

    getch();
    mainMenu();
}

/* ******************************************** Delete Record ********************************************* */

void recordDelete(void)
{
    char name[20];
    int found = 0;

    system("cls");
    titleShow();

    FILE *fp, *new;

    fp = fopen("Record2.txt", "r");
    new = fopen("Update.txt", "w");
    txtColor(fgGreen);

    printf("############### Delete Patients Record ###############\n");
    txtColor(Reset);

    gotoxy(12, 8);
    txtColor(fgCyan);

    printf("\n Enter Patient Name to delete: ");
    txtColor(Reset);
    fflush(stdin);

    gets(name);

    name[0] = toupper(name[0]);

    while (fscanf(fp, "%s %s %c %d %s %s %s %d %s %s %s %s", p.firstName, p.lastName, &p.Gender, &p.Age, p.Address, p.contactNo,p.Date,&p.bedNo,p.Bgroup, p.Problem, p.Doctor,p.Covid) != EOF)
    {
        if (strcmp(p.firstName, name) != 0)
            fprintf(fp, "%s %s %c %i %s %s %s %s %s", p.firstName, p.lastName, p.Gender, p.Age, p.Address, p.contactNo, p.Bgroup, p.Problem, p.Doctor);
        else
        {
            printf("%s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName, p.Gender, p.Age, p.Address, p.contactNo, p.Bgroup, p.Problem, p.Doctor);
            found = 1;
        }
    }

    if (found == 0)
    {
        txtColor(fgRed);
        printf("\n\n\t\t\tRecord not found....");

        txtColor(Reset);
        getch();

        mainMenu();
    }
    else
    {
        fclose(fp);
        fclose(new);

        remove("Record2.txt");
        rename("update.txt", "Record2.txt");

        txtColor(fgMagenta);
        printf("\n\n\t\t\tRecord Deleted Successfully\n\n\t\t\t\tCongratulations!!");

        txtColor(Reset);
        getch();

        mainMenu();
    }
}

/* ******************************************** Invoice ********************************************* */

void billPrint(void)
{
    char dAdmit[10], dRealease[10];
    char Date[20];
    int nDay;

    FILE *fp = fopen("Record2.txt", "r");

    fscanf(fp, "%s %s %c %d %s %s %s %d %s %s %s %s", p.firstName, p.lastName, &p.Gender, &p.Age, p.Address, p.contactNo,p.Date,&p.bedNo,p.Bgroup, p.Problem, p.Doctor,p.Covid);

    fflush(stdin);

    printf("\nGive Bed No :");
    scanf("%d", &p.bedNo);

    printf("\nNo days stayed in Hospital :");
    scanf("%d", &nDay);

    printf("\nGive Today's Date :");
    scanf("%s", Date);

    int Total, bTest, ECG, xRay, sBill, fBill, cTest, Others;

    printf("\n\n\t\t\t\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t|\t\t\t            >>>>  Invoice  <<<<       \t\t\t\t  |");

    printf("\n\t\t\t\t\t-------------------------------------------------------------------------------------------");
    printf("\n\t\t===============================================================================================================================================");

    gotoxy(250, 400);

    printf("\n\n\t\t\t\t\t\tDate :%s", Date);
    printf("\n\n\t\t\t\t\t\tPatient's Name    :%s %s", p.firstName, p.lastName);

    printf("\n\t\t\t\t\t\tDate of Admission :%s", dAdmit);
    printf("\n\t\t\t\t\t\tDate of Realease  :%s", dRealease);

    printf("\n\t\t\t\t\t\tPatient's Room No :256");

    printf("\n\t\t\t\t\t\tPatient's Bed No  :%d", p.bedNo);
    printf("\n\t\t\t\t\t\tReffered Doctor   :%s", p.Doctor);

    printf("\n\n\t\t\t\t\t\t-----------------------------------");
    printf("\n\n\t\t\t\t\t\tMedical Services  ");

    printf("\n\t\t\t\t\t\t-----------------------------------");
    printf("\n\t\t\t\t\t\tService Days : %d", nDay);

    sBill = 200 * nDay;
    printf("\n\t\t\t\t\t\tService Bill : %d", sBill);

    bTest = 800;
    printf("\n\t\t\t\t\t\tBlood Test   : %d", bTest);

    ECG = 2200;
    printf("\n\t\t\t\t\t\tECG          : %d", ECG);

    xRay = 2000;
    printf("\n\t\t\t\t\t\tX-Ray        : %d", xRay);

    cTest = 3300;
    printf("\n\t\t\t\t\t\tCovid Test   : %d", cTest);

    p.Problem[0] = toupper(p.Problem[0]);

    if (strcmp(p.Problem, "Covid") == 0)
    {
        p.oxygen = 250 * nDay;
    }
    else
    {
        p.oxygen = 0;
    }

    printf("\n\t\t\t\t\t\tOxygen Cost  : %d", p.oxygen);
    fBill = 200 * nDay;

    printf("\n\t\t\t\t\t\tFood Bill    : %d", fBill);
    Others = 1200;

    printf("\n\t\t\t\t\t\tOthers       : %d", Others);

    Total = bTest + ECG + xRay + sBill + fBill + cTest + Others;

    int Receive;
    printf("\n\t\t\t\t\t\t-----------------------------------");

    printf("\n\t\t\t\t\t\tTotal        :%d", Total);
    printf("\n\n\t\t\t\tEnter Amount:");

    scanf("%d", &Receive);
    printf("\n\t\t\t\tRecieved Amount :%d", Receive);

    printf("\n\t\t\t\tChange :%d", abs(Receive - Total));
    printf("\n\n\t\tLoading");

    for (int i = 0; i <= 4; i++)
    {
        Sleep(300);
        printf(".");
    }

    printf("\n\n\n\n\n\t\t\t\t\t\t\t>>> THANK YOU FOR VISITING. STAY SAFE <<<\n\n\n");
}