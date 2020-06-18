/*
    02 - Escreva um programa que simule o controle de uma pista de decolagem
    de aviões em um aeroporto. Neste programa, o usuário deve ser capaz de
    realizar as seguintes tarefas:
    a) Listar o número de aviões aguardando na fila de decolagem;
    - Para listar, deverá preencher a lista de aviões a decolar.
    b) Autorizar a decolagem do primeiro avião da fila;
    - Para autorização de voo, deverá existir ao menos um avião na fila.
    - Uma vez autorizado, o avião deverá ser removido da pista de decolagem
    (retirado da fila).
    c) Adicionar um avião à fila de espera;
    d) Listar todos os aviões na fila de espera;
    e) Listar as características do primeiro avião da fila.
    - Características: - Implemente com structs.
    - Numero Avião.
    - Modelo;
    - Ano fabricação;
    f) Confeccionar um menu de opções para esse programa.
    Obs: Sempre tente ao máximo implementar o uso de funções.
*/
#include<iostream>
#include<queue>
#include<conio.h>
#include<stdlib.h>
#include<stack>
#include<string.h>

using namespace std;


//Estrutura Características
typedef struct{
    int NumeroAviao;
    char modelo[40];
    int AnoFabricacao;
}caracteristicas;

//Declaração das Funções
void insertAvioes(queue<caracteristicas> avioes);
void imprimirPrimeiroFila(queue<caracteristicas> avioes);
void sizeFila(queue<caracteristicas> avioes);
void autorizaDecolagem(queue<caracteristicas> avioes);
void listaAvioes(queue<caracteristicas> avioes);


//Função que gera o Menu
void menu(queue<caracteristicas> avioes){
	int opcao;
	system("cls");

	printf("1 - Inserir avião na fila\n2 - Informações do Primeiro da Fila\n3 - Quantidade de aviioes na fila\n4 - Autorizar Decolagem\n5 - Listar Aviões na Fila\n6 - Sair");
	printf("\nEscolha uma opção: ");
	scanf("%d",&opcao);

	switch(opcao){
		case 1:
			system("cls");
			insertAvioes(avioes);
			break;

		case 2:
			system("cls");
			imprimirPrimeiroFila(avioes);
			break;

		case 3:
			system("cls");
			sizeFila(avioes);
			break;

		case 4:
			system("cls");
			autorizaDecolagem(avioes);
			break;
		
		case 5:
			system("cls");
			listaAvioes(avioes);
			break;
		
		case 6:
			printf("\n\nFinalizando...\n\n");
			system("pause");
			exit(0);
			break;
	
		default:
			printf("Escolha uma opção válida \n");
			system("pause");
			system("cls");
			menu(avioes);
		
	}
}

//Função para inserir aviões na fila
void insertAvioes(queue<caracteristicas> avioes){
   
	char op = 's'; 

	while(op == 's' || op == 'S'){
		caracteristicas avioesStruct;
		printf("Digite o número do avião : ");
		scanf("%d",&avioesStruct.NumeroAviao);

		printf("Digite o modelo do avião: ");
		fflush(stdin);
		fgets(avioesStruct.modelo, 40, stdin);

		printf("Digite o ano de fabricação : ");
		scanf("%d",&avioesStruct.AnoFabricacao);
	
		avioes.push(avioesStruct);

		getchar();
		printf("Deseja adicionar mais aviões ? (s/n)");
		scanf("%c",&op);
		system("cls");
	}

	menu(avioes);
	exit;
}

//Função para imprimir informações do primeiro avião da fila
void imprimirPrimeiroFila(queue<caracteristicas> avioes){
	queue<caracteristicas> filaTemp;
	filaTemp = avioes;


	if(filaTemp.empty()){
		printf("\nA fila está vazia !");
	}else{
		printf("Segue abaixo informações do primeiro avião da fila !!\nNúmero do Avião: %d\nModelo do Avião : %s\nAno de Fabricação : %d",filaTemp.front().NumeroAviao,filaTemp.front().modelo,filaTemp.front().AnoFabricacao);
		filaTemp.pop();
	}
	getch();
	menu(avioes);
}

//Função que mostra a quantidade de aviões na fila
void sizeFila(queue<caracteristicas> avioes){
	if(avioes.empty()){
		printf("A fila está vaiza !");
		getch();
		menu(avioes);
		exit;
	}
	printf("A quantidade de aviões na fila é : %d",avioes.size());
	getch();
	menu(avioes);
	exit;
}

//Função que autoriza decolagem do avião e o retira da fila
void autorizaDecolagem(queue<caracteristicas> avioes){ 
	if(!avioes.empty()){  
		printf("!! Avião liberado para decolar !!\n");
		printf("--> Informaçoes do Avião <--\n");
		printf("Número do Avião: %d\nModelo: %s\nAno de Fabricação : %d",avioes.front().NumeroAviao,avioes.front().modelo,avioes.front().AnoFabricacao);
		avioes.pop();	
	}else{
		printf("A fila está vazia !");
	}  
	getch();
	menu(avioes);
	exit;
}

//Função que lista todos os aviões que estão na fila
void listaAvioes(queue<caracteristicas> avioes){
	queue<caracteristicas> avioesTemp;
	avioesTemp = avioes;

	if(avioesTemp.empty()){
		printf("A fila está vazia");
	}

	printf("!! SEGUE ABAIXO A FILA DOS AVIÕES !!\n");
	printf("Início: --> \n\n");
	while(!avioesTemp.empty()){
		printf("Número do avião: %d\n",avioesTemp.front().NumeroAviao);
		printf("Modelo do avião: %s\n",avioesTemp.front().modelo);
		printf("Ano de Fabricação: %d\n",avioesTemp.front().AnoFabricacao);
		avioesTemp.pop();  
	}
	printf("<-- FIM");

	getch();
	menu(avioes);
	exit;
}


int main(){
	queue<caracteristicas> avioes;

	setlocale(LC_ALL, "Portuguese");
	menu(avioes);
	system("pause");
}