#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int Search(char Area[], float SumG, float SumT, float SumL, float SumTra, float SumS, 
           float MonthSum, float TotalSum, int Z) {
    if (strcmp(Area, "Grocery") == 0 || strcmp(Area, "grocery") == 0) {
        printf("You spent $%.2f on Grocery.\n", SumG);
    } else if (strcmp(Area, "Transport") == 0 || strcmp(Area, "transport") == 0) {
        printf("You spent $%.2f on Transport.\n", SumT);
    } else if (strcmp(Area, "Leisure") == 0 || strcmp(Area, "leisure") == 0) {
        printf("You spent $%.2f on Leisure.\n", SumL);
    } else if (strcmp(Area, "Travelling") == 0 || strcmp(Area, "travelling") == 0) {
        printf("You spent $%.2f on Travelling.\n", SumTra);
    } else if (strcmp(Area, "Shopping") == 0 || strcmp(Area, "shopping") == 0) {
        printf("You spent $%.2f on Shopping.\n", SumS);
    } else if (strcmp(Area, "Monthly Expenses") == 0 || strcmp(Area, "monthly expenses") == 0) {
        printf("You spent $%.2f on Monthly Expenses.\n", MonthSum);
    } else if (strcmp(Area, "Total") == 0 || strcmp(Area, "total") == 0) {
        printf("Your total spending is $%.2f.\n", TotalSum);
    } else {
        Z = 0;
        printf("Returning...");
        sleep(3);
        system("cls");
        return Z;
    }
    return Z;
}

int main() {
    int Sel1, Sel2; // Variáveis para seleção dos menus.
    char Area[20], Name[100]; 
    char String[] = ", please, be welcome!";
    float Salary;
    float Expenses[8];
    float Grocery[20] = {0}, Transport[20] = {0}, Leisure[20] = {0};
    float Travelling[20] = {0}, Shopping[20] = {0};
    float SumG = 0, SumT = 0, SumL = 0, SumTra = 0, SumS = 0;
    float MonthSum = 0, TotalSum = 0;
    bool X = 1, Y = 1, Z = 1;

    printf("Hi, I am Karek, the one who will help you with your spendings\n");
    printf("Please, tell me your name:\n");
    fgets(Name, 50, stdin);
    Name[strcspn(Name, "\n")] = '\0';
    strcat(Name, String);
    printf("%s\n", Name);

    do {
        printf("How much money do you make per month? Enter a positive number:\n");
        scanf("%f", &Salary);
    } while (Salary <= 0);

    do {
        printf("\t----------MENU----------\n");
        printf("Where did you spend your money today?\n");
        printf("\t1 => Grocery\n");
        printf("\t2 => Transport\n");
        printf("\t3 => Leisure\n");
        printf("\t4 => Travelling\n");
        printf("\t5 => Shopping\n");
        printf("\t6 => Monthly Expenses\n");
        printf("\t7 => Check total spending\n");
        printf("\t0 => Exit\n");
        scanf("%d", &Sel1);
        while (getchar() != '\n'); // Limpeza de buffer.

        switch (Sel1) {
            case 1:
                printf("Enter up to 20 values for Grocery. Enter 0 to stop.\n");
                for (int i = 0; i < 20; i++) {
                    printf("Amount spent: ");
                    scanf("%f", &Grocery[i]);
                    if (Grocery[i] <= 0) break;
                    SumG += Grocery[i];
                    TotalSum += Grocery[i];
                }
                break;
            case 2:
                printf("Enter up to 20 values for Transport. Enter 0 to stop.\n");
                for (int i = 0; i < 20; i++) {
                    printf("Amount spent: ");
                    scanf("%f", &Transport[i]);
                    if (Transport[i] <= 0) break;
                    SumT += Transport[i];
                    TotalSum += Transport[i];
                }
                break;
            // Casos para outras categorias (Leisure, Travelling, etc.) seguem a mesma lógica...
            case 6:
                do {
                    printf("\t----------SUBMENU----------\n");
                    printf("\t1 => Electricity Bill\n");
                    printf("\t2 => Water Bill\n");
                    printf("\t3 => IPVA\n");
                    printf("\t4 => IPTU\n");
                    printf("\t5 => Income Tax\n");
                    printf("\t6 => Wifi\n");
                    printf("\t7 => School\n");
                    printf("\t8 => Health\n");
                    printf("\t0 => Exit\n");
                    scanf("%d", &Sel2);

                    if (Sel2 >= 1 && Sel2 <= 8) {
                        printf("Enter the amount: ");
                        scanf("%f", &Expenses[Sel2 - 1]);
                        MonthSum += Expenses[Sel2 - 1];
                        TotalSum += Expenses[Sel2 - 1];
                    }
                } while (Sel2 != 0);
                break;
            case 7:
                printf("Enter the category you want to check:\n");
                fgets(Area, 20, stdin);
                Area[strcspn(Area, "\n")] = '\0';
                Search(Area, SumG, SumT, SumL, SumTra, SumS, MonthSum, TotalSum, Z);
                break;
            case 0:
                printf("Finishing...\n");
                X = 0;
                break;
        }
    } while (X);

    return 0;
}