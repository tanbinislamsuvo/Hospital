#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char ans=0;
int ok;
int b, valid=0;
void First_Screen(void);
void Title_Screen(void);
void Menu_option(void);
void Login_option(void);
void Add_patient(void);
void patient_list();
void Patient_Search(void);
void Patient_Edit(void);
void Patient_Delate(void);
void Closed(void);
void gotoxy(short x, short y)
{
COORD position = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
struct patient
{
int age;
char Gender;
char FirstNam[20];
char LastNam[20];
char PhoneNumber[15];
char HomeAddress[30];
char Email[30];
char Doctor[20];
char Problem[20];
};
struct patient  p,temp_c;
main(void)
{
First_Screen();
Title_Screen();
Login_option();
}
void First_Screen(void)
{
printf("\n\n\n\n\n\n\n\t\t\t\t");
printf("\n\t\t\t\t WELCOME TO\t\t");
printf("\n\t\t\tBasundhora HOSPITAL MANAGEMENT SYSTEM");
printf("\n\t\t\t\t");
printf("\n\nPress Enter any Key for Continue....\n");
getch();
system("cls");
}
void Title_Screen(void)
{
printf("\n\n\t\t");
printf("\n\t\t\t\tBasundhora HOSPITAL");
printf("\n\t\t");
}

void Menu_option(void)
{
system("cls");
int choose;
Title_Screen();
printf("\n\n\n\n\n1. Add Patients Record\n");
printf("\n2. List Of Patients Record\n");
printf("\n3. Finding Of Patients Record\n");
printf("\n4. Change Of Patients Record\n");
printf("\n5. Remove Of Patients Record\n");
printf("\n6. Exit\n");
printf("\n\n\n \nChoose Number from 1 to 6 :");
scanf("%i", &choose);
switch(choose)
{
case 1:
Add_patient();
    break;
  case 2:
    patient_list();
    break;
case 3:
Patient_Search();
  break;
case 4:
Patient_Edit();
break;
case 5:
Patient_Delate();
break;
case 6:
Closed();
    break;
default:
printf("\nPlease enter valid Key");
getch();
}
}

void Closed(void)
{
system("cls");
Title_Screen();
printf("\n\n\n\n\n\t\t\t\tTHANKS FOR VISI Of Bashundhora System");
getch();
}
void Login_option(void)
{
int e=0 ;
char Username[15];
char Password[15];
char original_Username[25]="a";
char original_Password[15]="12";
do
{
printf("\n\n\n\nEnter your User name and Password ");
printf("\n\n\n\t\tUSERNAME:");
scanf("%s",&Username);
printf("\n\t\tPASSWORD:");
scanf("%s",&Password);
if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
{
printf("\n\n\t\tYour Login is Successfull...");
getch();
Menu_option();
break;
}
else
{
printf("\nSorry your Password Incorrect Please Try Again");
e++;
getch();
}
}while(e<=2);
if(e>2)
{
printf("\nYou have Tried Many Time. So, You cannot login.");
getch();
   Closed();
}
system("cls");
}
void Add_patient(void)
{
system("cls");
Title_Screen();

char ans;
FILE*ek;
ek=fopen("Record2.dat","a");
printf("\n\n\t\t\tAdd Patients Record \n");

A:
printf("\nFirst Name: ");
scanf("%s",p.FirstNam);
p.FirstNam[0]=toupper(p.FirstNam[0]);
if(strlen(p.FirstNam)>20||strlen(p.FirstNam)<2)
{
printf("\nInvalid. The Character is too much short or long");
goto A;
}
else
{
for (b=0;b<strlen(p.FirstNam);b++)
{
if (isalpha(p.FirstNam[b]))
{
valid=1;
}
else
{
valid=0;
break;
}
}
if(!valid)
{
printf("\nFirst name contain Invalid character. Please Enter again ");
goto A;
}
}

B:
printf("\nLast Name: ");
    scanf("%s",p.LastNam);
    p.LastNam[0]=toupper(p.LastNam[0]);
    if(strlen(p.LastNam)>20||strlen(p.LastNam)<2)
{
printf("\nInvalid. The character is too much short or long");
goto B;
}
else
{
for (b=0;b<strlen(p.LastNam);b++)
{
if (isalpha(p.LastNam[b]))
{
valid=1;
}
else
{
valid=0;
break;
}
}
if(!valid)
{
printf("\nLast name contain Invalid character. Please Enter again :)");
goto B;
}
}

do
{
   printf("\nGender[F/M]: ");
scanf(" %c",&p.Gender);
if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
{
ok =1;
}
else
{
ok =0;
}
        if(!ok)
   {
    printf("\nInvalid character.Enter Female for F and Mail for M");
    }
}while(!ok);

    printf("\nAge:");
    scanf(" %i",&p.age);
    do
    {
   C:
   printf("\nHomeAddress: ");
   scanf("%s",p.HomeAddress);
   p.HomeAddress[0]=toupper(p.HomeAddress[0]);
   if(strlen(p.HomeAddress)>20||strlen(p.HomeAddress)<4)
{
printf("\n\t Invalid. The character is too much short or long");
goto C;
}
}while(!valid);
do
{
D:
   printf("\nContact no: ");
   scanf("%s",p.PhoneNumber);
   if(strlen(p.PhoneNumber)>11||strlen(p.PhoneNumber)!=11)
{
printf("\n\t Sorry Invalid Numbers. Please Enter 11 digit numbers without country code");
goto D;
}
else
{
for (b=0;b<strlen(p.PhoneNumber);b++)
{
if (!isalpha(p.PhoneNumber[b]))
{
valid=1;
}
else
{
valid=0;
break;
}
}
if(!valid)
{
printf("\nContact no. contain Invalid character.Enter again");
goto D;
}
}
}while(!valid);
do
{
   printf("\nEmail: ");
   scanf("%s",p.Email);
   if (strlen(p.Email)>30||strlen(p.Email)<8)
   {
      printf("\n\t Invalid. The max range for email is 30 character and min range is 8 ");
}
}while(strlen(p.Email)>30||strlen(p.Email)<8);
E:
printf("\nProblem: ");
scanf("%s",p.Problem);
p.Problem[0]=toupper(p.Problem[0]);
if(strlen(p.Problem)>15||strlen(p.Problem)<3)
{
printf("\n\t Invalid. The max range for first name is 15 and min range is 3 :)");
goto E;
}
else
{
for (b=0;b<strlen(p.Problem);b++)
{
if (isalpha(p.Problem[b]))
{
valid=1;
}
else
{
valid=0;
break;
}
}
if(!valid)
{
printf("\n\tSorry, Problem contain Invalid character");
goto E;
}
}
F:
    printf("\nPrescribed Doctor:");
    scanf("%s",p.Doctor);
    p.Doctor[0]=toupper(p.Doctor[0]);
    if(strlen(p.Doctor)>30||strlen(p.Doctor)<3)
{
printf("\n\t Invalid.The character is too much short or long");
goto F;
}
else
{
for (b=0;b<strlen(p.Doctor);b++)
{
if (isalpha(p.Doctor[b]))
{
valid=1;
}
else
{
valid=0;
break;
}
}
if(!valid)
{
printf("\n\t Doctor name contain Invalid character. Enter again");
goto F;
}
}
    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.FirstNam, p.LastNam, p.Gender, p.age, p.HomeAddress, p.PhoneNumber, p.Email, p.Problem, p.Doctor);
    printf("\n\n\tInformation Record Done Successful ...");
    fclose(ek);
    sd:
    getch();
    printf("\n\n\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
{
    Add_patient();
}
    else if(toupper(ans)=='N')
{
printf("\n\tThank you");
    getch();
    Menu_option();
}
   else
    {
        printf("\n\tInvalid Input\n");
        goto sd;
    }
}


void patient_list()
{
int row;
system("cls");
Title_Screen();
FILE *ek;
ek=fopen("Record2.dat","r");
printf("\n\n\t\tList Patients Record \n");
gotoxy(1,15);
printf("Full Name");
gotoxy(20,15);
printf("Gender");
gotoxy(32,15);
printf("Age");
gotoxy(37,15);
printf("HomeAddress");
gotoxy(49,15);
printf("Contact No.");
gotoxy(64,15);
printf("Email");
gotoxy(88,15);
printf("Problem");
gotoxy(98,15);
printf("Prescribed Doctor\n");
printf("=================================================================================================================");
row=17;
while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.FirstNam, p.LastNam, &p.Gender, &p.age, p.HomeAddress, p.PhoneNumber, p.Email, p.Problem, p.Doctor)!=EOF)
{
gotoxy(1,row);
printf("%s %s",p.FirstNam, p.LastNam);
gotoxy(20,row);
printf("%c",p.Gender);
gotoxy(32,row);
printf("%i",p.age);
gotoxy(37,row);
printf("%s",p.HomeAddress);
gotoxy(49,row);
printf("%s",p.PhoneNumber);
gotoxy(64,row);
printf("%s",p.Email);
gotoxy(88,row);
printf("%s",p.Problem);
gotoxy(98,row);
printf("%s",p.Doctor);
row++;
}
fclose(ek);
getch();
Menu_option();
}
void Patient_Search(void)
{
char name[20];
system("cls");
Title_Screen();
FILE *ek;
ek=fopen("Record2.dat","r");
printf("\n\n\tSearch Patients Record\n");
gotoxy(12,8);
printf("\n Enter Patient Name for view: ");
scanf("%s",name);
fflush(stdin);
name[0]=toupper(name[0]);
while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.FirstNam, p.LastNam, &p.Gender, &p.age, p.HomeAddress, p.PhoneNumber, p.Email, p.Problem, p.Doctor)!=EOF)
{
if(strcmp(p.FirstNam,name)==0)
{
gotoxy(1,15);
printf("Full Name");
gotoxy(25,15);
printf("Gender");
gotoxy(32,15);
printf("Age");
gotoxy(37,15);
printf("HomeAddress");
gotoxy(52,15);
printf("Contact No.");
gotoxy(64,15);
printf("Email");
gotoxy(80,15);
printf("Problem");
gotoxy(95,15);
printf("Prescribed Doctor\n");
printf("=================================================================================================================");
gotoxy(1,18);
printf("%s %s",p.FirstNam, p.LastNam);
gotoxy(25,18);
printf("%c",p.Gender);
gotoxy(32,18);
printf("%i",p.age);
gotoxy(37,18);
printf("%s",p.HomeAddress);
gotoxy(52,18);
printf("%s",p.PhoneNumber);
gotoxy(64,18);
printf("%s",p.Email);
gotoxy(80,18);
printf("%s",p.Problem);
gotoxy(95,18);
printf("%s",p.Doctor);
printf("\n");
break;
}
}
if(strcmp(p.FirstNam,name)!=0)
  {
gotoxy(5,10);
printf("Record not found!");
getch();
}
fclose(ek);
L:
getch();
printf("\n\n\tDo you want to view more[Y/N]?");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Patient_Search();
    }
else if(toupper(ans)=='N')
{
printf("\n\t Thank you");
    getch();
Menu_option();
    }
else
    {
    printf("\n\tInvalid Input.\n");
    goto L;
    }
}
void Patient_Edit(void)
{
FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];
system("cls");
  Title_Screen();
  ft=fopen("temp2.dat","w+");
ek=fopen("Record2.dat","r");
if(ek==NULL)
{
printf("\n\t Can not open file!! ");
getch();
Menu_option();
}
    printf("\n\n\t\t Edit Patients Record\n");
gotoxy(12,13);
printf("Enter the First Name of the Patient:");
scanf(" %s",name);
fflush(stdin);
name[0]=toupper(name[0]);
gotoxy(12,15);
if(ft==NULL)
{
printf("\n Can not open file");
getch();
Menu_option();
}
while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.FirstNam, p.LastNam, &p.Gender, &p.age, p.HomeAddress, p.PhoneNumber, p.Email, p.Problem, p.Doctor)!=EOF)
{
if(strcmp(p.FirstNam, name)==0)
{
valid=1;
gotoxy(25,17);
printf("Existing Record");
gotoxy(10,19);
printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.FirstNam,p.LastNam,p.Gender, p.age,p.HomeAddress,p.PhoneNumber,p.Email,p.Problem,p.Doctor);
gotoxy(12,22);
printf("Enter New First Name: ");
scanf("%s",p.FirstNam);
gotoxy(12,24);
printf("Enter Last Name: ");
scanf("%s",p.LastNam);
gotoxy(12,26);
printf("Enter Gender: ");
scanf(" %c",&p.Gender);
p.Gender=toupper(p.Gender);
gotoxy(12,28);
printf("Enter age: ");
scanf(" %i",&p.age);
gotoxy(12,30);
printf("Enter HomeAddress: ");
scanf("%s",p.HomeAddress);
p.HomeAddress[0]=toupper(p.HomeAddress[0]);
gotoxy(12,32);
printf("Enter Contact no: ");
scanf("%s",p.PhoneNumber);
gotoxy(12,34);
printf("Enter New email: ");
scanf("%s",p.Email);
gotoxy(12,36);
printf("Enter Problem: ");
scanf("%s",p.Problem);
p.Problem[0]=toupper(p.Problem[0]);
gotoxy(12,38);
printf("Enter Doctor: ");
scanf("%s",p.Doctor);
p.Doctor[0]=toupper(p.Doctor[0]);
printf("\nPress U charecter for the Updating operation : ");
ch=getche();
if(ch=='u' || ch=='U')
{
fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.FirstNam,p.LastNam,p.Gender, p.age,p.HomeAddress,p.PhoneNumber,p.Email,p.Problem,p.Doctor);
printf("\n\tPatient record updated successfully...");
}
}
else
{
fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.FirstNam,p.LastNam,p.Gender, p.age,p.HomeAddress,p.PhoneNumber,p.Email,p.Problem,p.Doctor);
}
}
if(!valid)
{
printf("\n\t\tNO RECORD FOUND...");
}
fclose(ft);
fclose(ek);
remove("Record2.dat");
    rename("temp2.dat","Record2.dat");
getch();
Menu_option();
}
void Patient_Delate()
{
char name[20];
int found=0;
system("cls");
Title_Screen();
FILE *ek, *ft;
ft=fopen("temp_file2.dat","w+");
ek=fopen("Record2.dat","r");
printf("\n\n\tDelete Patients Record \n");
gotoxy(12,8);
printf("\n Enter Patient Name to delete: ");
scanf("%s",name);
fflush(stdin);
name[0]=toupper(name[0]);
while (fscanf(ek,"%s %s %c %i %s %s %s %s %s", p.FirstNam, p.LastNam, &p.Gender,&p.age, p.HomeAddress, p.PhoneNumber, p.Email, p.Problem, p.Doctor)!=EOF)
{
if (strcmp(p.FirstNam,name)!=0)
fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.FirstNam, p.LastNam, p.Gender, p.age, p.HomeAddress, p.PhoneNumber, p.Email, p.Problem, p.Doctor);
else
{
printf("%s %s %c %i %s %s %s %s %s\n", p.FirstNam, p.LastNam, p.Gender, p.age, p.HomeAddress, p.PhoneNumber, p.Email, p.Problem, p.Doctor);
found=1;
}
}
if(found==0)
{
printf("\n\n\tRecord not found..");
getch();
Menu_option();
}
else
{
fclose(ek);
fclose(ft);
remove("Record2.dat");
rename("temp_file2.dat","Record2.dat");
printf("\n\n\tRecord deleted successfully ");
getch();
Menu_option();
}
}
