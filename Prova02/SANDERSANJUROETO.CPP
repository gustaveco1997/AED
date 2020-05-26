/*
01 – O restaurante Algorítmico não serve a quilo: os clientes escolhem itens do
cardápio. O cardápio tem todos os itens disponíveis, que são descritos em uma lista.
Cada item aparece na lista com um número de identificação, a descrição e o preço.
Suellen, a gerente do restaurante, atende no caixa, onde os clientes fazem uma fila
invariavelmente grande. Cada cliente tem em mãos, uma comanda/ficha com o valor
da refeição. Para cada cliente atendido, Suellen informa o preço total ao cliente. Além
disso, o restaurante está agraciando os clientes com um pequeno chocolate. Suellen
mantém uma pilha de chocolates diversos e entrega ao cliente atendido o chocolate
do topo da pilha.
Escreva um programa que implementa o sistema acima. Você deve preparar
cuidadosamente o cardápio do restaurante. Encha a fila de pessoas conhecidas, cada
uma com sua comanda com o valor das refeições. Você deve encher a pilha com
chocolates diversos. Ao final, mostre qual chocolate cada cliente ganhou, bem como
quanto pagou pela refeição.
O programa deve ter opções para imprimir a fila e pilha a qualquer momento.
Execute testes exaustivos, mostrando que seu programa funciona nas mais diversas
situações (ex. pilha vazia, fila cheia, etc, etc).
*/
#include<locale.h>
#include<iostream>
#include<queue>
#include<conio.h>
#include<stdlib.h>
#include<stack>
#include<string.h>
#include <list>

using namespace std;

//Estrutura Vacinas
typedef struct{
	int numero_vacina;
    int data_fabricacao;
    int data_validade;
    char nome_laboratorio[40];
}vacina;



void menu(list <vacina> vacinas);
void subMenuProduzir(list <vacina> vacinas)



void produzVacinaLabRitmo(list <vacina> vacinas,queue <vacina> filaLabRitmo){

}

void produzVacinaLabEd(list <vacina> vacinas,queue <vacina> filaLabEd){

}

void produzVacinaLabRaja(list <vacina> vacinas,queue <vacina> filaLabRaja){

}

void produzVacinaLabComp(list <vacina> vacinas,queue <vacina> filaLabComp){

}



//Função que gera o submenu para produção de vacinas
void subMenuProduzir(list <vacina> vacinas,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){

    int opcao; //Variável para armazenar opção escolhida
    
    system("cls");

    printf("1 - LAB-ritmo\n2 - LABed\n3 - LABraja\n4 - LABcomp\n5 - Voltar ao Menu anterior");
    printf("\nEscolha uma opção : ");
    scanf("%d",&opcao);

    switch(opcao){
        case 1:
            system("cls");
            produzVacinaLabRitmo(vacinas,filaLabRitmo);
            break;

        case 2:
            system("cls");
            produzVacinaLabEd(vacinas,filaLabEd);
            break;

        case 3:
            system("cls");
            produzVacinaLabRaja(vacinas,filaLabRaja);
            break;

        case 4:
            system("cls");
            produzVacinaLabComp(vacinas,filaLabComp);
            break;
        
        case 5;
            system("cls");
            menu(vacinas);
            break;

        default:
			printf("Escolha uma opção válida \n");
			system("pause");
			system("cls");
			subMenuProduzir(vacina);
    }


}

//Função que gera o Menu
void menu(list <vacina> vacinas,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){

	int opcao; //Variável para armazenar a opção escolhida

	system("cls");

	printf("1 - Produzir Vacinas\n6 - Sair");
	printf("\nEscolha uma opção: ");
	scanf("%d",&opcao);

	switch(opcao){
		case 1:
			system("cls");
			subMenuProduzir(vacinas,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
			break;
	
		default:
			printf("Escolha uma opção válida \n");
			system("pause");
			system("cls");
			menu(lista);
		
	}
}


int main(){
    list <vacina> vacinas;

    queue <vacina> filaLabRitmo;
    queue <vacina> filaLabEd;
    queue <vacina> filaLabRaja;
    queue <vacina> filaLabComp;
    
	
	setlocale(LC_ALL, "Portuguese");
	
	
	menu();
	
	
	system("pause");

}