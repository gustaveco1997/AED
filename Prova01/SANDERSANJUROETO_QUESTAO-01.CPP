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


using namespace std;

//Estrutura Chocolates
typedef struct{
	char nome[40];
}chocolates;

//Estrutura de Clientes
typedef struct{
	int numeroComanda;
	char nome[40] ;
	float total ;
}clientes;

//Fila do tipo clientes
queue<clientes> fila;

//Pilha do tipo chocolates
stack<chocolates> pilha;


void menu();
void insertClientes();
void buscaCliente();
void imprimeSize();
void removeCliente();
void imprimirFila();

//Função de inserir Clientes
void insertClientes(){
	char op = 's';
	
	while(op == 's' || op == 'S'){
		clientes pessoas;
		printf("Digite o número da comanda do cliente : ");
		scanf("%d",&pessoas.numeroComanda);
	
		printf("Digite o nome do cliente:");
		fflush(stdin);
		fgets(pessoas.nome, 40, stdin);
	
		printf("Digite o valor total da comanda : R$ ");
		scanf("%f",&pessoas.total);
		
		fila.push(pessoas);
	
		getchar();
		printf("Deseja adicionar um cliente ? (s/n)");
		scanf("%c",&op);
		system("cls");
	}
	
	menu();
	exit;

	
		
}

//Função de inserir chocolates
void insertChocolates(){
	char op = 's';
	
	
	while(op == 's' || op == 'S'){
		chocolates chocolate;
	
		printf("Digite o nome do chocolate : ");
		fflush(stdin);
		fgets(chocolate.nome, 40, stdin);
	
		pilha.push(chocolate);
	
	
		printf("Deseja adicionar um chocolates ? (s/n)");
		scanf("%c",&op);
		system("cls");
	}
	
	menu();
	exit;

	
		
}

//Função para buscar cliente na fila
void buscaCliente(){
	queue <clientes> fila2;
	int valor;
	fila2 = fila;
	
	
	if(fila2.empty()){
		printf("Não é possivel buscar cliente, pois a fila está vazia !");
		getch();
		menu();
		exit;
	}
	
	
	printf("Digite o número da comanda do cliente à ser buscado na fila: \n");
	scanf("%d",&valor);
	
	while(!fila2.empty()){
		if(fila2.front().numeroComanda==valor){
			printf("Comanda de número %d encontrado na fila !\n",valor);
			printf("Nome do cliente é : %s\n",fila2.front().nome);
			getch();
			menu();
			exit;
		}else{
			fila2.pop();
		}
		
	}
	printf("A comanda número %d não foi encontrado na fila ! \n",valor);
	getch();
	menu();
	exit;
}

//Função para imprimir informações da fila !
void imprimeSize(){
	
	if(fila.empty()){
		printf("A fila está vaiza !");
		getch();
		menu();
		exit;
	}
	printf("O tamanho da fila é %d :\n",fila.size());
	printf("O primeiro cliente da fila da fila é : Nome - %s, Comanda - %d\n",fila.front().nome,fila.front().numeroComanda);
	printf("\nO último cliente da fila é :  Nome - %s, Comanda - %d\n",fila.back().nome,fila.back().numeroComanda);
	getch();
	menu();
	exit;
}

//Função para remover clientes da fila
void removeCliente(){
	char op = 's';
	char resp;

	while(op=='s' || op =='S'){
		
		if(pilha.empty() && !fila.empty()){
			printf("A pilha de chocolates está vazia ! Deseja remover o cliente mesmo assim ? (s/n) : ");
			getchar();
			scanf("%c",&resp);
			if(resp == 's'){
				if(!fila.empty()){
					printf("A pilha de chocolates está vazia, cliente saindo sem ganhar chocolate.\nPreencha a pilha de chocolates.\n");
					printf("Cliente %s saindo da fila ... Número da Comanda : %d\n  Valor Total da Comanda: R$%.2f\n",fila.front().nome,fila.front().numeroComanda,fila.front().total);
					printf("Cliente %s removido com sucesso !\n",fila.front().nome);
					fila.pop();
					pilha.pop();  
			}
				
		}
		
			
		}else if(!fila.empty()){
			printf("Cliente %s saindo da fila ... Número da Comanda : %d\n  Valor Total da Comanda: R$%.2f\n",fila.front().nome,fila.front().numeroComanda,fila.front().total);
			printf("Cliente %s removido com sucesso ! Seu chocolate foi o %s \n",fila.front().nome,pilha.top().nome);
			fila.pop();
			pilha.pop();
			
			
		}else{
			printf("Impossível remover um cliente , pois  a fila está vazia !\n");
			getch();
			menu();
			exit;     
		}
		getchar();
		printf("Deseja tirar cliente da fila ? (s/n) ");
		scanf("%c",&op);
		system("cls");
		
	}
	
	menu();
	exit;
}

//Função para Imprimir a Fila
void imprimirFila(){
	queue<clientes> fila2;
	fila2 = fila;
	
	
	if(fila2.empty()){
		printf("\nA fila está vazia !");
	}else{
		printf("\nInício: -->");
		while(!fila2.empty()){
			printf("%s -",fila2.front().nome);
			fila2.pop();
		}
		printf("<-- FIM\n");
	}
	getch();
	menu();
}

//Função para imprimir a Pilha
void imprimirPilha(){
	stack<chocolates> pilha2;
	pilha2 = pilha;
	
	if(pilha2.empty()){
		printf("\nA pilha está vazia !");
	}else{
		printf("\nInício: -->");
		while(!pilha2.empty()){
			printf("%s -",pilha2.top().nome);
			pilha2.pop();
		}
		printf("<-- FIM\n");
	}
	getch();
	menu();
}

//Função que gera o Menu
void menu(){
	int opcao;
	system("cls");
	
	printf("1 - Inserir cliente na fila \n2 - Buscar cliente na fila \n3 - Verificar informações da fila\n4 - Remover um cliente da fila\n5 - Imprimir toda a fila\n6 - Inserir chocolates na pilha\n7 - Imprimir Pilha de Chocolates\n");
	scanf("%d",&opcao);
	
	switch(opcao){
		case 1:
			system("cls");
			insertClientes();
			break;
		case 2:
			system("cls");
			buscaCliente();
			break;
		case 3:
			system("cls");
			imprimeSize();
			break;
		case 4:
			system("cls");
			removeCliente();
			break;
		case 5:
			system("cls");
			imprimirFila();
			break;
			
		case 6:
			system("cls");
			insertChocolates();
			break;
			
		case 7:
			system("cls");
			imprimirPilha();
			break;
			
		default:
			printf("Escolha uma opção válida \n");
			system("pause");
			system("cls");
			menu();
			
	}
}
int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	
	menu();
	
	
	system("pause");

}