/*
1 – Crie uma struct para controlar ações de uma bolsa de valores com as seuigntes informações:
• Nome da compania;
• Áre de atuação da compania;
• Valor atual da ação (em reais);
• Valor anterior;
• Variação da ação em porcentagem (double), ou seja, quanto a ação cresceu ou caiu desde a abertura da bolsa no dia.

2- Faça um programa que:
a) Preencha os campos da struct;
b) Imprima os campos da struct;
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
struct acoes acoes;

int main(){
        printf("Área de Atuação: ");
        fflush(stdin);
        fgets(acoes.Area_de_atuacao, 40, stdin);

        printf("Valor Atual : ");
        scanf("%f",&acoes.Valor_Atual);

        printf("Valor Anterior : ");
        scanf("%f",&acoes.Valor_Anterior);

        printf("Variação : ");
        scanf("%lf",&acoes.Variacao);

        printf("Área de Atuação: %c\nValor Atual: %.2f\nValor Anterior: %.2f \nVariação: %.2lf\n",acoes.Area_de_atuacao,acoes.Valor_Atual,acoes.Valor_Anterior,acoes.Variacao);
   /*for(int i=0;i<5;i++){
        printf("Área de Atuação: ");
        fflush(stdin);
        fgets(acoes[i].Area_de_atuacao, 40, stdin);

        printf("Valor Atual : ");
        scanf("%f",&acoes[i].Valor_Atual);

        printf("Valor Anterior : ");
        scanf("%f",&acoes[i].Valor_Anterior);

        printf("Variação : ");
        scanf("%f",&acoes[i].Variacao);


    }
*/

return 0;
}
