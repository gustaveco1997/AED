/*
2 - Faça um algoritmo que:
Tenha uma estrutura que contenha:
Nome cliente;
Quantidade comprada;
Valor unitário;
Total.

O algoritmo deve enfileirar os clientes na fila do caixa e ir consumindo, ou seja, removendo-os da fila.
Use funções e faça as consistências!
*/
#include<locale.h>
#include<iostream>
#include<queue>
#include<conio.h>
#include<stdlib.h>


using namespace std;



typedef struct{
	int codigo;
	char nome[40] ;
	int qtd ;
	float valor ;
	float total ;
}clientes;

//Criei a fila de acesso global para manipula-la através de todas as funções
queue<clientes> fila;


//Declarações de funções
void menu();
void insertClientes();
void buscaCliente();
void imprimeSize();
void removeCliente();
void imprimirFila();

//Função que insere cliente na fila
void insertClientes(){
	char op = 's';
    
    while(op == 's' || op == 'S'){
		clientes pessoas;

		printf("Digite o código do cliente : ");
		scanf("%d",&pessoas.codigo);
	
		printf("Digite o nome do cliente:");
		fflush(stdin);
		fgets(pessoas.nome, 40, stdin);
	
		printf("Digite a quantidade comprada : ");
		scanf("%d",&pessoas.qtd);
	
		printf("Digite o valor unitário: ");
		scanf("%f",&pessoas.valor);
	
		pessoas.total = pessoas.qtd * pessoas.valor;
		fila.push(pessoas);
		
		getchar();
		printf("Deseja adicionar um cliente ? (s/n)");
		scanf("%c",&op);
		system("cls");
	}
    
	menu();
	exit;

	
		
}

//Função que busca um cliente na fila
void buscaCliente(){
	queue <clientes> fila2;
	int valor;
	fila2 = fila;
	
	
	printf("Digite o código do cliente à ser procurado na fila: \n");
	scanf("%d",&valor);
	
	while(!fila2.empty()){
		if(fila2.front().codigo==valor){
			printf("Código %d encontrado na fila !\n",valor);
			printf("Nome do Cliente é : %s\n",fila2.front().nome);
			getch();
			menu();
			exit;
		}else{
			fila2.pop();
		}
		
	}
	printf("O cliente de código %d não foi encontrado na fila ! \n",valor);
	getch();
	menu();
	exit;
}
void imprimeSize(){
    printf("O tamanho da fila é %d : \n",fila.size());
    printf("O primeiro cliente da fila é : Nome - %s, código - %d  \n",fila.front().nome,fila.front().codigo);
    printf("O último elemento da fila é :  Nome - %s, código - %d  \n",fila.back().nome,fila.back().codigo);
    getch();
    menu();
    exit;
}


//Função que remove um cliente da fila
void removeCliente(){
	if(!fila.empty()){
		printf("Cliente %s saindo da fila ... \n",fila.front().nome);
		printf("Cliente %s removido com sucesso ! ",fila.front().nome);
		fila.pop();
		getch();
		menu();
		exit;
	}else{
		printf("Impossível remover um cliente , pois  a fila está vazia !");
		getch();
		menu();
		exit;
	}
}

//Função que imprime os clientes que estão na fila
void imprimirFila(){
	queue<clientes> fila3;
	fila3 = fila;
	
	if(fila3.empty()){
		printf("\nA fila está vazia !");
	}else{
		printf("\nInício: -->");
		while(!fila3.empty()){
			printf("%s -",fila3.front().nome);
			fila3.pop();
		}
		printf("<-- FIM\n");
	}
	getch();
	menu();
}

//Função que cria o Menu
void menu(){
	int opcao;
	system("cls");
    
	printf("1 - Inserir cliente na fila \n2 - Buscar cliente na fila \n3 - Verificar tamanho da fila\n4 - Remover um cliente da fila\n5 - Imprimir toda a fila\n");
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