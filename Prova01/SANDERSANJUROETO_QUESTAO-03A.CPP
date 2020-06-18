/*
a. REESCREVA a função converteTemperatura para que ela utilize a
passagem do parâmetro temperatura

como referência (200 pontos)
*/
#include <stdio.h>
#include <stdlib.h>
#define ZEROABSC -273.15
#define ZEROABSF -459.67

float leTemperatura(int opcao);
float converteTemperatura(int opcao, float *temperatura);

int main(void) {
    float temp, conv;
    int op;

    do{
        printf("1 - Celsius para Fahreinheit\n");
        printf("2 - Fahreinheit para Celsius\n");
        printf("3 - Sair.\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1: temp = leTemperatura(op);
            //Chamando função converteTemperatura passando a referência (Questão 03-B)
            conv = converteTemperatura(op, &temp);
            printf("%.2f C sao %.2f F.\n", temp, conv);
            break;
            
            case 2: temp = leTemperatura(op);
            //Chamando função converteTemperatura passando a referência (Questão 03-B)
            conv = converteTemperatura(op, &temp);
            printf("%.2f F sao %.2f C.\n", temp, conv);
            break;
            
            case 3: printf("Saindo...\n");
            break;
            default: printf("Valor inválido.\n");
        }
    }while(op != 3);

    system("PAUSE");
    return 0;
}
float leTemperatura(int opcao){
    float temperatura;
    bool teste;
    do{
        printf("Digite a temperatura: ");
        scanf("%f", &temperatura);
        if( ((opcao == 1) && (temperatura < ZEROABSC)) || ((opcao == 2) && (temperatura < ZEROABSF)) ){
            printf("Temperatura invalida. Digite novamente.\n");
            teste = false;
        }else
            teste = true;
    }while(!teste);

    return temperatura;
}

//Função converte temperatura recebendo o parâmetro temperatura como referencia ! (Questão 03 -A)
float converteTemperatura(int opcao, float *temperatura) {
    float conversao;
    if(opcao == 1)
        conversao = *temperatura * 1.8 + 32;
    else
        conversao = (*temperatura - 32) / 1.8;
    return conversao;
}