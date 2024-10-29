#include <stdio.h>   // Biblioteca para entrada e saída (printf, scanf).
#include <string.h>  // Biblioteca para manipulação de strings (strcmp, strcat).
#include <math.h>    // Biblioteca matemática.
#include <stdlib.h>  // Biblioteca para funções gerais como system() e sleep().
#include <stdbool.h> // Biblioteca para usar booleanos (true/false).
#include <ctype.h>   // Biblioteca para manipular caracteres.

// Função 'Search' que imprime quanto foi gasto em uma categoria específica.
int Search(char Area[], float SumG, float SumT, float SumL, float SumTra, float SumS, 
           float MonthSum, float TotalSum, int Z) {
    // Verifica a categoria escolhida e imprime o valor correspondente.
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
        // Se nenhuma categoria foi encontrada, volta ao menu anterior.
        Z = 0;
        printf("Returning...");
        sleep(3);  // Aguarda 3 segundos.
        system("cls");  // Limpa a tela.
        return Z;
    }
    return Z;  // Retorna o valor de Z.
}

// Função principal do programa.
int main() {
    int Sel1, Sel2;  // Variáveis para seleção dos menus principais e secundários.
    char Area[20], Name[100];  // Strings para nome e categoria escolhida.
    char String[] = ", please, be welcome!";  // Mensagem personalizada.
    float Salary;  // Armazena o salário do usuário.
    float Expenses[8];  // Vetor para armazenar despesas fixas mensais.
    float Grocery[20] = {0}, Transport[20] = {0}, Leisure[20] = {0};
    float Travelling[20] = {0}, Shopping[20] = {0};  // Vetores para registrar despesas.
    float SumG = 0, SumT = 0, SumL = 0, SumTra = 0, SumS = 0;  // Somatórios por categoria.
    float MonthSum = 0, TotalSum = 0;  // Soma das despesas mensais e total.
    bool X = 1, Y = 1, Z = 1;  // Variáveis de controle para os laços do menu.

    // Apresentação inicial.
    printf("Hi, I am Karek, the one who will help you with your spendings\n");
    printf("Please, tell me your name:\n");
    fgets(Name, 50, stdin);  // Lê o nome do usuário.
    Name[strcspn(Name, "\n")] = '\0';  // Remove o '\n' do final da string.
    strcat(Name, String);  // Adiciona a mensagem personalizada.
    printf("%s\n", Name);  // Exibe o nome com a saudação.

    // Solicita o salário até que o valor seja positivo.
    do {
        printf("How much money do you make per month? Enter a positive number:\n");
        scanf("%f", &Salary);
    } while (Salary <= 0);

    // Loop principal do menu.
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
        scanf("%d", &Sel1);  // Lê a escolha do menu principal.
        while (getchar() != '\n');  // Limpa o buffer.

        switch (Sel1) {
            case 1:
                printf("Enter up to 20 values for Grocery. Enter 0 to stop.\n");
                for (int i = 0; i < 20; i++) {
                    printf("Amount spent: ");
                    scanf("%f", &Grocery[i]);
                    if (Grocery[i] <= 0) break;  // Interrompe se o valor for 0.
                    SumG += Grocery[i];  // Soma os valores.
                    TotalSum += Grocery[i];  // Atualiza o total.
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

            case 6:  // Submenu para despesas fixas.
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
                        MonthSum += Expenses[Sel2 - 1];  // Soma na categoria mensal.
                        TotalSum += Expenses[Sel2 - 1];  // Atualiza o total.
                    }
                } while (Sel2 != 0);  // Sai do submenu ao escolher 0.
                break;

            case 7:  // Verificar gastos em uma categoria.
                printf("Enter the category you want to check:\n");
                fgets(Area, 20, stdin);  // Lê a categoria desejada.
                Area[strcspn(Area, "\n")] = '\0';  // Remove o '\n'.
                Search(Area, SumG, SumT, SumL, SumTra, SumS, MonthSum, TotalSum, Z);  // Chama a função 'Search'.
                break;

            case 0:  // Sair do programa.
                printf("Finishing...\n");
                X = 0;  // Encerra o loop principal.
                break;
        }
    } while (X);  // Continua enquanto 'X' for verdadeiro.

    return 0;  // Encerra o programa.
}