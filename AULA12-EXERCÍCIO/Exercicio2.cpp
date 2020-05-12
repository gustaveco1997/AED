/*
    03 - Implemente um algoritmo que:
    a - Crie um vetor de 10.000 posições. Isso mesmo, 10.000!
    b - Preencha esse vetor com números inteiros aleatórios;
    c - Imprima o vetor preenchido;
    d - Ordene de forma crescente esse vetor;
    e - Ordene de forma decrescente esse vetor;
    f - Imprima o vetor ordenado em ordem crescente;
    g - Imprima o vetor ordenado em ordem decrescente;
    h - Calcule o número de números repetidos existem neste vetor;
    i - Faça um menu com as opções desse programa.
    Obs: Sempre tente ao máximo implementar o uso de funções.
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

//Declaração de funções
void criaVetor(int vetor[]);
void funcao_ordena(int vetor[]);
void imprimi(int vetor[]);
void funcao_ordenaDecrescente(int vetor[]);
void funcao_calculaRepetidos(int vetor[]);

//Função que gera Menu
void menu(int vetor[]){
    int opcao;
    
    printf("\n1 - Preencher Vetor\n2 - Imprimir Vetor\n3 - Ordenar Vetor Crescente\n4 - Odernar Vetor Decrescente\n5 - Quantidade de Repetidos\n");
    printf("Digite a opção : ");
    scanf("%d",&opcao);
    
    switch (opcao){
        case 1:
            criaVetor(vetor);
            break;
    
        case 2:
            imprimi(vetor);
            break;
        case 3:
            funcao_ordena(vetor);
            break;
        
        case 4:
            funcao_ordenaDecrescente(vetor);
            break;
        
        case 5:
            funcao_calculaRepetidos(vetor);
            break;
    
        default:
            printf("Escolha uma opção válida \n");
            system("pause");
            system("cls");
            menu(vetor);
    }
}

//Função para criar vetor usando a função rand()
void criaVetor(int vetor[]){
    int i;
    
    for(i=0;i<10000;i++){
        vetor[i] = rand();
    }

    printf("\n\nVetor preenchido com sucesso!\n\n");
    
    system("pause");
    system("cls");
    menu(vetor);
    exit;
}

//Função que ordena vetor de forma crescente
void funcao_ordena(int vetor[]){
    int i, j, aux;
 
    for( i=0; i<10000; i++ ){
        for( j=i+1; j<10000; j++ ){
            if( vetor[i] > vetor[j] ){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    printf("\n Ordenado com sucesso!\n");
    
    system("pause");
    system("cls");
    menu(vetor);
    exit;
}

//Função que ordena vetor de forma decrescente
void funcao_ordenaDecrescente(int vetor[]){ 
    int i, j, aux;

    for( i=0; i<10000; i++ ){
        for( j=i+1; j<10000; j++ ){
            if( vetor[i] < vetor[j] ){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    printf("\n Ordenado com sucesso!\n");
    
    system("pause");
    system("cls");
    menu(vetor);
    exit;
}

//Função que mostra a quantidade de numeros repetidos
void funcao_calculaRepetidos(int vetor[]){ 
    int i, j, aux=0;

    for( i=0; i<10000; i++ ){
    
        for( j=i+1; j<10000; j++ ){
            if( vetor[i] == vetor[j]&&i!=j){
                aux++;
            }
        }
    }
    printf("\n A quantidade de números repetidos é %d\n",aux);
    
    system("pause");
    system("cls");
    menu(vetor);
    exit;
}

//Função que imprimi o vetor
void imprimi(int vetor[]){
    int i;
    
    printf("Os números do vetor são:\n");
    for(i=0;i<10000;i++){
        printf("\n%d",vetor[i]);
    }
    system("pause");
    system("cls");
    menu(vetor);
    exit;
}

//Função principal
int main(){
    int vetor[10000];
    
    setlocale(LC_ALL, "Portuguese");
    menu(vetor);
    system("pause");
}