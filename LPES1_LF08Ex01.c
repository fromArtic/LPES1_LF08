#include <stdio.h>
#include <stdlib.h>

#define LIN 12
#define COL 4

void menu();
void lerVendas(float vendas[][COL]);
void vendasMes(float vendas[][COL]);
void vendasSemana(float vendas[][COL]);
void vendasTotal(float vendas[][COL]);

int i = 0, j = 0, m = 0, check = 0;
char mes[13][15] =
    {"Janeiro",
    "Fevereiro",
    "Marco",
    "Maio",
    "Abril",
    "Maio",
    "Junho",
    "Julho",
    "Agosto",
    "Setembro",
    "Outubro",
    "Novembro",
    "Dezembro"};

int main(){
    float vendas[LIN][COL];
    int choice;

    do{
        menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                lerVendas(vendas);
                check++;
                break;
            case 2:
                vendasMes(vendas);
                break;
            case 3:
                vendasSemana(vendas);
                break;
            case 4:
                vendasTotal(vendas);
                break;
            default:
                printf("\nEncerrando o programa...\n");
        }
    }while(choice != 0);

    system("PAUSE");
    return 0;
}

void menu(){
    printf("MENU DE OPCOES\n");
    printf("1 - Informar valores das vendas\n");
    printf("2 - Total vendido em cada mes do ano\n");
    printf("3 - Total vendido em cada semana ao longo do ano\n");
    printf("4 - Somatoria do total arrecadado\n");
    printf("0 - Encerrar programa\n");
    printf("Insira sua escolha: ");
}

void lerVendas(float vendas[][COL]){
    i = 0, j = 0, m = 0;
    printf("\n");
    for(j = 0; j < COL; j++){
        printf("%s, semana %d - Valor das vendas: R$", mes[m], j + 1);
        scanf("%f", &vendas[i][j]);
        if(j == COL - 1 && i != LIN){
            j = -1;
            i++;
            m++;
            printf("\n");
        }
    }
    printf("\nInformacoes de vendas atualizadas.\n\n");
}

void vendasMes(float vendas[][COL]){
    i = 0, m = 0;
    if(check == 0){
        printf("\nERRO: informe os valores de suas vendas antes de acessar os resultados.\n\n");
    }
    else{
        printf("\nTOTAL DE VENDAS POR MES\n");
        for(i = 0; i < LIN + 1; i++){
            printf("- %s: R$%.2f\n", mes[m], vendas[i][0] + vendas[i][1] + vendas[i][2] + vendas[i][3]);
            m++;
        }
        printf("\n");
    }
}

void vendasSemana(float vendas[][COL]){
    i = 0, j = 0, m = 0;
    int cont = 0;
    if(check == 0){
        printf("\nERRO: informe os valores de suas vendas antes de acessar os resultados.\n\n");
    }
    else{
        printf("\nTOTAL DE VENDAS POR SEMANA\n");
        printf("%s\n", mes[m]);
        for(j = 0; j < COL; j++){
            printf("- Semana %d: R$%.2f\n", cont + 1, vendas[i][j]);
            cont++;
            if(j == COL - 1 && i != LIN){
                j = -1;
                i++;
                m++;
                printf("\n");
                printf("%s\n", mes[m]);
            }
        }
        printf("\n");
    }
}

void vendasTotal(float vendas[][COL]){
    i = 0, j = 0;
    float total = 0;
    if(check == 0){
        printf("\nERRO: informe os valores de suas vendas antes de acessar os resultados.\n");
    }
    else{
        printf("\nTOTAL ARRECADO AO LONGO DO ANO: R$");
        for(i = 0; i < LIN; i++){
            for(j = 0; j < COL; j++){
                total += vendas[i][j];
            }
        }
        printf("%.2f\n\n", total);
    }
}
