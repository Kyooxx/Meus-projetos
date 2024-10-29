#include<stdio.h>
#include<string.h>
#include<math.h> 
#include<stdlib.h> 
#include<stdbool.h>
#include<ctype.h>

int Search(char Area[], float SumG, float SumT, float SumL, float SumTra, float SumS, float MonthSum, float TotalSum, int Z){
    if(strcmp(Area, "Grocery") == 0 || strcmp(Area, "grocery") == 0){
        printf("You spent $%.2f on Grocery.\n", SumG);
    } 
    else if(strcmp(Area, "Transport") == 0 || strcmp(Area, "transport") == 0){
        printf("You spent $%.2f on Transport.\n", SumT);
    } 
    else if(strcmp(Area, "Leisure") == 0 || strcmp(Area, "leisure") == 0){
        printf("You spent $%.2f on Leisure.\n", SumL);
    } 
    else if(strcmp(Area, "Travelling") == 0 || strcmp(Area, "travelling") == 0){
        printf("You spent $%.2f on Travelling.\n", SumTra);
    } 
    else if(strcmp(Area, "Shopping") == 0 || strcmp(Area, "shopping") == 0){
        printf("You spent $%.2f on Shopping.\n", SumS);
    } 
    else if(strcmp(Area, "Monthly Expenses") == 0 || strcmp(Area, "monthly expenses") == 0){
        printf("You spent $%.2f on Monthly Expenses.\n", MonthSum);
    } 
    else if(strcmp(Area, "Total") == 0 || strcmp(Area, "total") == 0){
        printf("Your total spending is $%.2f.\n", TotalSum);
    } 
    else {
        Z = 0;
        printf("Returning...");
        sleep(3);
        system("cls");
        return Z;
    }
}

 


int main(){
    int Sel1; //Variável para seleção do menu principal.
    int Sel2; // Variável para a seleção do segundo menu.
    char Area[20]; //String para a seleção do menu de relatório de despesas.
    char Name[100]; 
    char String[] = ", please, be welcome!";
    float Salary;
    float Expenses[8]; //Vetor para que o usuário coloque as despesas consideradas fixas a cada mês.
    float Grocery[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float SumG = 0;//
    float Transport[]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float SumT = 0;
    float Leisure[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float SumL = 0;
    float Travelling[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float SumTra = 0;
    float Shopping[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float SumS = 0;
    float MonthSum = 0; // Soma das despesas que são consideradas mensais.
    float TotalSum = 0; // Soma de todas as despesas que a pessoa durante o mês inteiro.
    bool X = 1, Y = 1, Z = 1; // Variável para controlar o do while principal.

    printf("Hi, I am Karek, the one who will help you with your spendings\n");
    printf("Please, tell me your name:\n");
        fgets(Name, 50, stdin);
        Name[strcspn(Name, "\n")] = '\0';
            strcat(Name, String);
            printf("%s\n", Name);
           
    do{
    printf("Now, how much money do you make per month? Enter a positive number different to zero.\n");
    scanf("%f", &Salary); 
      }while(Salary <= 0);

    do{
        printf("\t----------MENU----------\n");
        printf("Which one of these areas did you spend your money today?\n");
        printf("\t 1 => Grocery\n");
        printf("\t 2 => Transport\n");
        printf("\t 3 => Leisure\n");
        printf("\t 4 => Travelling\n");
        printf("\t 5 => Shopping\n");
        printf("\t 6 => Monthly Expenses\n");
        printf("\t 7 => know how much you have spent\n");
        printf("\t 0 => Exit\n");
            scanf("%d", &Sel1);
             while (getchar() != '\n');//limpeza 

                switch(Sel1){
                    case 1: 
                    printf("You can put a maximum of 20 values.\n");
                    for(int I = 0; I < 20; I++){
                    printf("How much did you spend in grocery? Enter 0 to finish.\n");
                    scanf("%f", &Grocery[I]);

                    SumG += Grocery[I];
                   
                    if((Grocery[I] <= 0)){
                        printf("Returning...");
                        sleep(3);
                        system("cls");
                        break;
                    }
                    TotalSum += Grocery[I];
                    
                    if(TotalSum >= Salary){
                        printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);
                    }
                     }
                    break;
                        case 2: 
                        printf("You can put a maximum of 20 values.\n");
                    for(int I = 0; I < 20; I++){
                    printf("How much did you spend in transport? Enter 0 to finish.\n");
                    scanf("%f", &Transport[I]);

                    SumT += Transport[I];
                    
                   
                    if((Transport[I] <= 0)){
                        printf("Returning...");
                        sleep(3);
                        system("cls");
                        break;
                    }
                    TotalSum += Transport[I]; // Colocar depois do if para garantir o valor correto
                    if(TotalSum >= Salary){
                        printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);
                    }

                     }
                        break;
                            case 3: 
                                printf("You can put a maximum of 20 values.\n");

                    for(int I = 0; I < 20; I++){
                    printf("How much did you spend in leisure? Enter 0 to finish.\n");
                    scanf("%f", &Leisure[I]);

                    SumL += Leisure[I];
                    
                    
                    if((Leisure[I] <= 0)){
                        printf("Returning...");
                        sleep(3);
                        system("cls");
                        break;
                    }
                        
                    TotalSum += Leisure[I];
                    if(TotalSum >= Salary){
                        printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);
                    }

                     }
                            break;
                                case 4: 
                                printf("You can put a maximum of 20 values.\n");

                    for(int I = 0; I < 20; I++){
                    printf("How much did you spend in travelling? Enter 0 to finish.\n");
                    scanf("%f", &Travelling[I]);

                    SumTra += Travelling[I];
                    
                    
                    if((Travelling[I] <= 0)){
                        printf("Returning...");
                        sleep(3);
                        system("cls");
                        break;
                    }
                        
                    TotalSum += Travelling[I];
                    if(TotalSum >= Salary){
                        printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);
                    }

                     }
                                break;
                                    case 5: 
                                    printf("You can put a maximum of 20 values.\n");

                                    for(int I = 0; I < 20; I++){
                                    printf("How much did you spend in shopping? Enter 0 to finish.\n");
                                    scanf("%f", &Shopping[I]);

                                    SumS += Shopping[I];
                                   
                                    
                                    if((Shopping[I] <= 0)){
                                        printf("Returning...");
                                        sleep(3);
                                        system("cls");
                                        break;
                                    }
                                        
                                    TotalSum += Shopping[I];
                                    if(TotalSum >= Salary){
                                        printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);
                                    }

                                    }
                                    break;
                    case 6:
                    while(Y == 1){
                    printf("\t----------SUBMENU----------\n");
                    printf("\t 1 => Electricity Bill\n");
                    printf("\t 2 => Water Bill\n");
                    printf("\t 3 => IPVA\n");
                    printf("\t 4 => IPTU\n");
                    printf("\t 5 => Income tax\n");
                    printf("\t 6 => Wifi\n");
                    printf("\t 7 => School\n");
                    printf("\t 8 => Health\n");
                    printf("\t 0 => Exit\n");
                        scanf("%d", &Sel2);

                        switch(Sel2){
                            case 1: 
                            printf("How much did you spend on the electricity bill?\n");
                            scanf("%f", &Expenses[0]);
                            MonthSum += Expenses[0];
                            TotalSum += Expenses[0];

                            if(TotalSum >= Salary){
                            printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);}
                            break;
                                case 2: 
                                printf("How much did you spend on the water bill?\n");
                                scanf("%f", &Expenses[1]);
                                MonthSum += Expenses[1];
                                TotalSum += Expenses[1];

                                if(TotalSum >= Salary){
                                printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);}
                                break;
                                    case 3: 
                                    printf("How much did you spend on the IPVA?\n");
                                    scanf("%f", &Expenses[2]);
                                    MonthSum += Expenses[2];
                                    TotalSum += Expenses[2];

                                    if(TotalSum >= Salary){
                                    printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);}
                                    break;
                                        case 4: 
                                        printf("How much did you spend on the IPTU?\n");
                                        scanf("%f", &Expenses[3]);
                                        MonthSum += Expenses[3];
                                        TotalSum += Expenses[3];

                                        if(TotalSum >= Salary){
                                        printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);}
                                        break;
                                                case 5: 
                                                printf("How much did you spend on the income tax?\n");
                                                scanf("%f", &Expenses[4]);
                                                MonthSum += Expenses[4];
                                                TotalSum += Expenses[4];

                                                 if(TotalSum >= Salary){
                                                 printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);}
                                                 break; 
                                                    case 6: 
                                                    printf("How much did you spend on the wifi bill?\n");
                                                    scanf("%f", &Expenses[5]);
                                                    MonthSum += Expenses[5];
                                                    TotalSum += Expenses[5];

                                                    if(TotalSum >= Salary){
                                                    printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);}
                                                    break;
                                                    
                                                        case 7: 
                                                        printf("How much did you spend on the school bill?\n");
                                                        scanf("%f", &Expenses[6]);
                                                        MonthSum += Expenses[6];
                                                        TotalSum += Expenses[6];

                                                        if(TotalSum >= Salary){
                                                        printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);}
                                                        break;
                                                            case 8: 
                                                            printf("How much did you spend on the health care bill?\n");
                                                            scanf("%f", &Expenses[7]);
                                                            MonthSum += Expenses[7];
                                                            TotalSum += Expenses[7];

                                                            if(TotalSum >= Salary){
                                                            printf("You have achieved the maxumum of expenses, now you account is negative. (%f)", Salary - TotalSum);}
                                                            break;                                    
                                    case 0:
                                    printf("Returning...");
                                    sleep(3);
                                    Y = 0;
                                    system("cls");
                                    break;

                                    default:
                                    printf("Returning...");
                                    sleep(3);
                                    Y = 0;
                                    system("cls");
                                    break;
                        
                        }
                    }
                                      break;
                         case 7:
                         while(Z == 1){
                         printf("Write the option you want to see:\n");
                         printf("\tGrocery\n");
                         printf("\tTransport\n");
                         printf("\tLeisure\n");
                         printf("\tTravelling\n");
                         printf("\tShopping\n");
                         printf("\tMonthly Expenses\n");
                         printf("\tTotal\n");
                         printf("\tExit\n");
                         fgets(Area, 20, stdin);
                         Area[strcspn(Area, "\n")] = '\0';

                          Z = Search(Area, SumG, SumT, SumL, SumTra, SumS, MonthSum, TotalSum, Z);
                         }



                         
                        
                        break;
                            case 0:
                            printf("Finishing...");
                            sleep(3);
                            system("cls");
                            X = 0; 
                            break; 

                            default: 
                            printf("Finishing...Thank you for trusting me!");
                            sleep(3);
                            system("cls");
                            X = 0;
                            break;       

                }
    }while(X);   
}

