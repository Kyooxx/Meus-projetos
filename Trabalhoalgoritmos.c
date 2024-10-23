#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
int Sel1;
int Sel2;
char Name[100];
char String[] = ", please, be welcome!";
float Salary;
float Expenses[13];
float SumG = 0;
float SumT = 0;
float SumL = 0;
float SumTra = 0;
float SumS = 0;
float MonthSum;
float TotalSum;
bool X = 1;

printf("Hi, I am Roboto, the one who will help you with your spendings\n");
printf("Please, tell me your name:");
fgets(Name, 50, stdin);
Name[strcspn(Name, "\n")] = '\0';
strcat(Name, String);
printf("%s", Name);

printf("Now, how much money do you make per month?\n");
scanf("%f", &Salary);

do{
printf("\t----------MENU----------\n");
printf("Which one of these areas did you spend your money today?\n");
printf("\t 1 => Grocery\n");
printf("\t 2 => Transport\n");
printf("\t 3 => Leisure\n");
printf("\t 4 => Travelling\n");
printf("\t 5 => Shopping\n");
printf("\t 6 => Monthly Expenses\n");
printf("\t 7 => Total spent this month\n");
printf("\n 0 => Exit");
scanf("%d", &Sel1);

switch(Sel1){
case 1:
printf("How much did you spend in grocery?\n");
scanf("%f", &Expenses[0]);
//CHAMAR FUNÇÃO
break;
case 2:
printf("How much did you spend in transport?\n");
scanf("%f", &Expenses[1]);
//CHAMAR FUNÇÃO
break;
case 3:
printf("How much did you spend in leisure?\n");
scanf("%f", &Expenses[2]);
//CHAMAR FUNÇÃO
break;
case 4:
printf("How much did you spend in travelling?\n");
scanf("%f", &Expenses[3]);
//CHAMAR FUNÇÃO
break;
case 5:
printf("How much did you spend in shopping?\n");
scanf("%f", &Expenses[4]);
//CHAMAR FUNÇÃO
break;
case 6:
printf("\t----------SUBMENU----------\n");
printf("\t 1 => Electricity Bill");
printf("\t 2 => Water Bill\n");
printf("\t 3 => IPVA\n");
printf("\t 4 => IPTU\n");
printf("\t 5 => Income tax\n");
printf("\t 6 => Wifi\n");
printf("\t 7 => School\n");
printf("\t 8 => Health\n");
printf("\n 0 => Exit");
scanf("%d", &Sel2);

switch(Sel2){
case 1:
printf("How much did you spend on the electricity bill?\n");
scanf("%f", &Expenses[5]);
break;
case 2:
printf("How much did you spend on the water bill?\n");
scanf("%f", &Expenses[6]);
break;
case 3:
printf("How much did you spend on the IPVA?\n");
scanf("%f", &Expenses[7]);
break;
case 4:
printf("How much did you spend on the IPTU?\n");
scanf("%f", &Expenses[8]);
break;
case 5:
printf("How much did you spend on the income tax?\n");
scanf("%f", &Expenses[9]);
break;
case 6:
printf("How much did you spend on the wifi bill?\n");
scanf("%f", &Expenses[10]);
break;
case 7:
printf("How much did you spend on the school bill?\n");
scanf("%f", &Expenses[11]);
break;
case 8:
printf("How much did you spend on the health care bill?\n");
scanf("%f", &Expenses[12]);
break;
case 0:
break;
default:
break;

}
case 7:
//CHAMAR FUNÇÃO
case 0:
X = 0;
break;
default:
X = 0;
break;
}
}while(X);

for(int I = 0; I < 13; I++){
printf("%f\n", Expenses[I]);
}
}
