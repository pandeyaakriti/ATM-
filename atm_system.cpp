#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> 
#include <conio.h> 
#include <ctype.h>
char ans=0;
int ok;
int b, valid=0;

void welcomescreen(void);
void title(void);
void mainmenu(void);
void loginscreen(void);
void view(void);
void viewdisp(void);
void deposit(void);
void withdraw(void);
void withdrawlogin(void);
void ex_it(void);
void gotoxy(short x, short y)
{
	COORD pos= {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
struct user {
	char phone[50];
	char acc[40];
	char pin[90];
	float balance;
	char firstname[40];
	char lastname[40];
	float amountd;
	float amountw;
	float sum;
	
};
struct user u, temp;
int main()
{
	welcomescreen();
	title();
	loginscreen();
}
void welcomescreen(void)
{
	gotoxy(5,2);
	printf ("\t #####################################################");
	gotoxy(10,4);
	printf ("\t\t  WELCOME TO ");
	gotoxy(8,5);
	printf ("\t PAISA INVESTMENT BANK LIMITED");
	gotoxy(5,6);
	printf ("\t #####################################################");
	printf ("\n\n \t press any key to continue: ");
	getch();
	system("cls");
}
void title(void)
{
	gotoxy(5,2);
	printf ("\t ****************************************************** ");
	gotoxy(8,4);
	printf ("\t\t PAISA INVESTMENT BANK LIMITED");
	gotoxy(5,5);
	printf ("\t ******************************************************");
}
void mainmenu()
{
	system ("cls");
	int choose;
	title();
	printf ("\n\n\t\t\t 1. view account");
	printf ("\n\n\t\t\t 2. deposit money ");
	printf ("\n\n\t\t\t 3. withdraw money");
	printf ("\n\n\t\t\t 4. exit");
	printf ("\n\n\t\t choose your action corresponding number:");
	scanf ("%d", &choose);
	switch(choose)
	{
		case 1:
			viewdisp();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withdrawlogin();
			break;
		case 4:
			ex_it();
			break;
		default:
			printf ("\n\n\t\t !! INVALID ENTRY !!");
			getch();
			break;	
	}
}
void ex_it(void)
{
	int w;
	system("cls");
	title();
	printf("\n\n\t\t\t THANKYOU FOR VISITING ");
	printf ("\n\n\t\t enter 0 to return to main menu");
	scanf ("%d", &w);
	if (w==0)
	{
		mainmenu();
	}
	getch();
	
}
void loginscreen(void)
{
	int e=0;
	char username[20];
	char password[30];
	char ori_username[20]="pandey";
	char ori_password[30]= "0000";
	do
	{
		printf("\n\n\n\t\t\t USERNAME:");
		scanf("%s", &username);
		printf ("\n\n\n\t\t\t PASSWORD: ");
		scanf ("%s", &password);
		if (strcmp(username, ori_username)==0 && strcmp(password, ori_password)==0)
		{
			printf ("\n\n\t\t\t .....Login Successful.....");
			getch();
			mainmenu();
			break;
		}
		else
		{
			printf("\n\n\t\t\t username or password incorrect. Try again!");
			e++;
			getch();
		}
	}
	while(e<=1);
	if (e>1)
	{
		printf("\n\n you have cross limit. you cannot login.");
		getch();
	
	}
	system ("cls");
}

void deposit(void)
{
	system("cls");
	title();
	char ans;
	int v=0;
	char d[20];
	
	printf ("\n\n\t\t\t !!!!!!!!!!!!!!! DEPOSITING MONEY !!!!!!!!!!!!!!");
	
		printf ("\n\n\t\t\t 1. First Name: ");
		scanf ("%s", u.firstname);
		printf ("\n\n\t\t\t 2. Last Name: ");
		scanf ("%s", u.lastname);
		
	do
	{
		A:
		printf ("\n\n\t\t\t 3. Contact no: ");
		scanf ("%s", u.phone);
		if (strlen(u.phone)>10 || strlen(u.phone)!=10)
		{
			printf ("\n\n\t\t phone number must contain 10 numeric digits");
			printf ("\n \n\t\t\ttry again");
			goto A;
		}
		else
		{
			for (b=0; b<strlen(u.phone); b++)
			{
				if (!isalpha(u.phone[b]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n\n\t\t enter numeric values");
				goto A;
			}
		}
}
	while (!valid);
	
	
	
	printf ("\n\n\t\t\t 4. Deposit amount: ");
	scanf ("%f", &u.amountd);
	u.sum += u.amountd;	
	title();
	system("cls");
    printf ("\n\n\n \t\t\t .........AMOUNT DEPOSITED SUCCESSFULLY........ ");
	
	printf("\n\n\t\t\t THANKYOU FOR VISITING ");
	printf ("\n\n\t\t enter 0 to return to main menu: ");
	scanf ("%d", &v);
	if (v==0)
	{
		mainmenu();
	}
	
	getch();	

	


	
	
}



void viewdisp()
{
	int x;
	system("cls");
	title();
	printf ("\n\n\n \t\t Here, your recent transaction is shown, for detailed transaction history, \n\t\t contact your bank to mail you a copy.\n");
	printf ("\n\n\t\t\t enter 0 to view account: ");
	scanf ("%d", &x);
	if (x==0)
	{
		view();
	}
	getch();
}

void view()
{
    int row;
	system ("cls");
	title();
	printf ("\n\n\n..........................................YOUR ACCOUNT.......................................");
	printf("\n\n TOTAL BALANCE: %f ", u.sum);
	
	gotoxy(2,15);
	printf ("FIRST NAME\t\t");
	gotoxy(15,15);
	printf ("LAST NAME\t\t" );
	gotoxy(30,15);
	printf ("PHONE NO\t\t");
	gotoxy(50,15);
	printf ("DEPOSIT ");
	row=19;
	
	{
	
		gotoxy(2,row);
		printf("%s", u.firstname);
		gotoxy(15,row);
		printf("%s", u.lastname);
		gotoxy(30,row);
		printf("%s", u.phone);
		gotoxy(50,row);
		printf("%f", u.amountd);
		row++;
	}
    getch();
	mainmenu();
}


 void withdrawlogin(void)
 {
 	system("cls");
 	int f=0;
	char pin[30];
	char ori_pin[30]= "1111";
	do
	{

		printf ("\n\n\n\t\t\t PIN: ");
		scanf ("%s", &pin);
		if (strcmp(pin, ori_pin)==0)
		{
			printf ("\n\n\t\t\t .....Login Successful.....");
			getch();
			withdraw();
			break;
		}
		else
		{
			printf("\n\n\t\t\t pin incorrect.\n\n\t\t\t Try again!");
			f++;
			getch();
		}
	}
	while(f<=1);
	if (f>1)
	{
		printf("\n\n\t\t\t you have crossed the limit. you cannot login.");
		getch();
		ex_it();
	}
	system ("cls");
 }
 
 void withdraw(void)
 {
 	int w;
 	system("cls");
 	title();
 	printf("\n\n\t\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!! WITHDRAWING CASH !!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
 	printf("\n\n\n\t\t\t Enter amount you want to withdraw: ");
 	scanf("%f", &u.amountw);
	u.sum= u.sum- u.amountw;
	system ("cls");
	title();
 	printf ("\n\n\n \t\t\t.......AMOUNT WITHDRAWED SUCCESSFULLY......");
 	printf("\n\n\n \t\t\t COLLECT CASH FROM COUNTER NO 2");
 	printf ("\n\n\n\t\t\t please remember!! \n\t\t\t the '-' in your balance indicates your loan to bank, \n\t\t\t delay in paying the amount within 5 days of withdraw results in \n\t\t\t addition of ten percent of loan amount per day");
 	getch();
	system ("cls");
 	title ();
	printf("\n\n\t\t\t THANKYOU FOR VISITING ");
	printf ("\n\n\n\n\n \t\t\t enter 0 to return to main menu: ");
	scanf ("%d", &w);
	if (w==0)
	{
		mainmenu();
	}
	
	
	 getch();
	 
	 
 }

