#include <stdio.h>
#include <stdlib.h>

#define LIN 5
#define COL 3

void menu();
void lerDados(float matriz[][COL]);
void totalArmazenado(float matriz[][COL]);
void maiorEstoqProd2(float matriz[][COL]);
void menorEstoq(float matriz[][COL]);
void custoTotalProduto(float matriz[][COL]);
void custoTotalArmazem(float matriz[][COL]);

int i, j, check = 0;

int main(){
    float matriz[LIN][COL];
    int choice;

    do{
        menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                lerDados(matriz);
                check++;
                break;
            case 2:
                totalArmazenado(matriz);
                break;
            case 3:
                 maiorEstoqProd2(matriz);
                break;
            case 4:
                menorEstoq(matriz);
                break;
            case 5:
                custoTotalProduto(matriz);
                break;
            case 6:
                custoTotalArmazem(matriz);
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
    printf("1 - Informar dados de estoque e venda\n");
    printf("2 - Total de produtos armazenados em cada armazem\n");
    printf("3 - Armazem com maior estoque do produto 2\n");
    printf("4 - Armazem com o menor estoque\n");
    printf("5 - Custo total de cada produto\n");
    printf("6 - Gasto total de cada armazem\n");
    printf("0 - Encerrar programa\n");
    printf("Insira sua escolha: ");
}

//Input usuario
void lerDados(float matriz[][COL]){
    i = 0, j = 0;
    printf("\n");
    for(j = 0; j < COL; j++){
        for(i = 0; i < LIN; i++){
            if(i != LIN - 1){
                printf("Produto %d, armazem %d - Estoque disponivel: ", j + 1, i + 1);
                scanf("%f", &matriz[i][j]);
            }
            if(i == LIN - 1){
                printf("Preco do produto %d: ", j + 1);
                scanf("%f", &matriz[i][j]);
                printf("\n");
            }
        }
    }
    printf("Informacoes de estoque e venda atualizadas.\n\n");
}

//Total de produtos armazenados em cada armazem
void totalArmazenado(float matriz[][COL]){
    i = 0, j = 0;
    printf("\nINFO DE ESTOQUE EM CADA ARMAZEM\n\n");
    if(check == 0){
        printf("\nERRO: informe sobre estoque e venda antes de acessar os resultados.\n\n");
    }
    else{
        int somatoria;
        for(i = 0; i < LIN - 1; i++){
            somatoria = 0;
            printf("Armazem %d:\n", i + 1);
            for(j = 0; j < COL; j++){
                somatoria += matriz[i][j];
                printf("- Produto %d: %.1f estocados\n", j + 1,  matriz[i][j]);
            }
            printf("Total armazenado: %d\n\n", somatoria);
        }
    }
}

//Armazem com maior estoque do produto 2
void maiorEstoqProd2(float matriz[][COL]){
    i = 0, j = 0;
    printf("\n");
    if(check == 0){
        printf("\nERRO: informe sobre estoque e venda antes de acessar os resultados.\n\n");
    }
    else{
        int maiorEstoque = matriz[0][1], armazem = 1;
        for(i = 0; i < LIN - 1; i++){
            j = 1;
            if(matriz[i][j] > maiorEstoque){
                maiorEstoque = matriz[i][j];
                armazem = i + 1;
            }
        }
        printf("O maior estoque do produto 2 se encontra no armazem %d, com %d unidades.\n\n", armazem, maiorEstoque);
    }
}

//Armazem com o menor estoque
void menorEstoq(float matriz[][COL]){
    i = 0, j = 0;
    printf("\n");
    if(check == 0){
        printf("\nERRO: informe sobre estoque e venda antes de acessar os resultados.\n\n");
    }
    else{
        int menorEstoque = 9999, somatoria = 0, armazem = 0;
        for(i = 0; i < LIN - 1; i++){
            somatoria = 0;
            for(j = 0; j < COL; j++){
                somatoria += matriz[i][j];
                if(somatoria < menorEstoque){
                    menorEstoque = matriz[i][j];
                    armazem = i + 1;
                }
            }
        }
        printf("O armazem %d possui o menor estoque.\n\n", armazem);
    }
}

//Custo total de cada produto
void custoTotalProduto(float matriz[][COL]){
    i = 0, j = 0;
    printf("\n");
    if(check == 0){
        printf("\nERRO: informe sobre estoque e venda antes de acessar os resultados.\n\n");
    }
    else{
        float somatoria, custo;
        for(j = 0; j < COL; j++){
            somatoria = 0;
            for(i = 0; i < LIN - 1; i++){
                somatoria += matriz[i][j];
            }
            custo = somatoria * matriz[4][j];
            printf("Custo total do produto %d: R$%.2f\n", j + 1, custo);
        }
        printf("\n");
    }
}

//Gasto total de cada armazem
void custoTotalArmazem(float matriz[][COL]){
    i = 0, j = 0;
    printf("\n");
    if(check == 0){
        printf("\nERRO: informe sobre estoque e venda antes de acessar os resultados.\n\n");
    }
    else{
        float custo, somatoria;
        for(i = 0; i < LIN - 1; i++){
            somatoria = 0;
            for(j = 0; j < COL; j++){
                custo = matriz[i][j] * matriz[4][j];
                somatoria += custo;
            }
            printf("Custo total do armazem %d: R$%.2f\n", i + 1, somatoria);
        }
    }
    printf("\n");
}
