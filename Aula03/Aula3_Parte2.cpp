/*

2- Faça um programa que:
c) Com um laço, preencha 5 dados na structs (usar vetor de structs).

3 - Faça uma funçao que, dado um valor de ação pelo usuário, imprima as informações das ações que estão abaixo do valor informado. Necessário usar função.
4 – Faça um programa que exibe a média dos valores de todas as ações. Necessário usar função.
5 – Implemente uma função que, dado um novo valor atual como argumento/parâmetro, calcule e altere os valores de todas as ações. Essa função deve também calcular e alterar o campo de variação das ações baseado no valor anterior.
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct acoes{
    char Area_de_atuacao[40];
    float Valor_Atual;
    float Valor_Anterior;
    double Variacao;
};
struct acoes acoes[5];


void verificaAcoes(float valor){
    for(int i=0;i<5;i++){
        if(acoes[i].Valor_Atual<valor){
            printf("Área de Atuação: %c\nValor Atual: %.2f\nValor Anterior: %.2f\n Variação: %.2lf\n\n",acoes[i].Area_de_atuacao,acoes[i].Valor_Atual,acoes[i].Valor_Anterior,acoes[i].Variacao);
        }
    }
    return;
}
float mediaAcoes(){
    float total = 0,media;
    for(int i=0;i<5;i++){
        total = acoes[i].Valor_Atual+total;
    }
    media = total/5;
    return media;
}
void atualizaAcoes(float valor){
    for(int i=0;i<5;i++){
        acoes[i].Valor_Anterior=acoes[i].Valor_Atual;
        acoes[i].Valor_Atual=valor;
        acoes[i].Variacao=((acoes[i].Valor_Atual*100)/acoes[i].Valor_Anterior)-100;
    }
    return;

}

int main(){
    float valor,valorNew;

   for(int i=0;i<5;i++){
        printf("Área de Atuação: ");
        fflush(stdin);
        fgets(acoes[i].Area_de_atuacao, 40, stdin);

        printf("Valor Atual : ");
        scanf("%f",&acoes[i].Valor_Atual);

        printf("Valor Anterior : ");
        scanf("%f",&acoes[i].Valor_Anterior);

        printf("Variação : ");
        scanf("%lf",&acoes[i].Variacao);


    }
    printf("Digite um valor para pesquisa de ação : ");
    scanf("%f",&valor);

    printf("As informações das ações abaixo do valor digitado são :\n ");
    verificaAcoes(valor);

    printf("A média de valores das ações é : %.2f\n\n",mediaAcoes());

    printf("Digite um novo valor para as ações : ");
    scanf("%f",&valorNew);
    atualizaAcoes(valorNew);

    printf("O valor atualizado das ações são : ");
    for(int i=0;i<5;i++){
        printf("Área de Atuação: %c\nValor Atual: %.2f\nValor Anterior: %.2f \nVariação: %.2lf %%\n",acoes[i].Area_de_atuacao,acoes[i].Valor_Atual,acoes[i].Valor_Anterior,acoes[i].Variacao);
    }






return 0;
}

