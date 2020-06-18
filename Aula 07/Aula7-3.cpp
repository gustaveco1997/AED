/*
3 - Faça um algoritmo que:
Tenha uma estrutura que contenha:
Nome do carro;
Tempo de limpeza.
O algoritmo deve enfileirar os clientes na fila do caixa e ir consumindo, ou seja, removendo-os da fila baseado no tempo de limpeza.
Use funções e faça as consistências!
*/

#include<locale.h>
#include<iostream>
#include<queue>
#include<conio.h>
#include<stdlib.h>


using namespace std;



typedef struct{
	int placa;
	char carro[40] ;
	int tempoLimpeza ;
}clientes;
queue<clientes> fila;
void menu();
void insertClientes();
void buscaCliente();
void imprimeSize();
void removeCliente();
void imprimirFila();


void insertClientes(){
	char op = 's';
    
	while(op == 's' || op == 'S'){
		clientes carros;
		printf("Digite a placa do veículo : ");
		scanf("%d",&carros.placa);
	
		printf("Digite o nome do carro:");
		fflush(stdin);
		fgets(carros.carro, 40, stdin);
	
		printf("Digite o tempo de limpeza do veículo (Minutos) : ");
		scanf("%d",&carros.tempoLimpeza);
		
		fila.push(carros);
	
		getchar();
		printf("Deseja adicionar um cliente ? (s/n)");
		scanf("%c",&op);
		system("cls");
	}
    
	menu();
	exit;

	
		
}
void buscaCliente(){
	queue <clientes> fila2;
	int valor;
	fila2 = fila;
	
	
	printf("Digite a placa do veículo à ser procurado na fila: \n");
	scanf("%d",&valor);
	
	while(!fila2.empty()){
		if(fila2.front().placa==valor){
			printf("Código %d encontrado na fila !\n",valor);
			printf("Nome do carro é : %s\n",fila2.front().carro);
			getch();
			menu();
			exit;
		}else{
			fila2.pop();
		}
		
	}
	printf("A placa %d não foi encontrado na fila ! \n",valor);
	getch();
	menu();
	exit;
}
void imprimeSize(){
	printf("O tamanho da fila é %d :\n",fila.size());
	printf("O primeiro veiculo da fila é : Nome - %s, Placa - %d\n",fila.front().carro,fila.front().placa);
	printf("\nO último veículo da fila é :  Nome - %s, Placa - %d\n",fila.back().carro,fila.back().placa);
	getch();
	menu();
	exit;
}
void removeCliente(){
	queue <clientes> filaaux;
	queue <clientes> filadestino;
	queue <clientes> filaorigem;
	filaorigem = fila;
	int menortempo=10000;
	while(!filaorigem.empty()){
		if(filaorigem.front().tempoLimpeza<menortempo){
			menortempo = filaorigem.front().tempoLimpeza;
		
			if(filadestino.empty()&&filaaux.empty()){
				filaaux.push(filaorigem.front());
				filaorigem.pop();
			
			}else if(filadestino.empty()&&!filaaux.empty()){
				filadestino.push(filaorigem.front());
				filaorigem.pop();
			
			}else if(!filadestino.empty()){
				filaorigem.push(filadestino.front());
				filadestino.push(filaorigem.front());
				filadestino.pop();
				filaorigem.pop();
			
			}

		}else if(filaorigem.front().tempoLimpeza>menortempo){
			if(filaorigem.front().tempoLimpeza<filaaux.front().tempoLimpeza){
				filaorigem.push(filaaux.front());
				filaaux.push(filaorigem.front());
				filaorigem.pop();
				filaaux.pop();
			}else if(filaorigem.front().tempoLimpeza>filaaux.front().tempoLimpeza && filaorigem.front().tempoLimpeza>filadestino.front().tempoLimpeza){
				filaaux.push(filaorigem.front());
				filaorigem.pop();
			}
			else if(filaorigem.front().tempoLimpeza<filaaux.front().tempoLimpeza&& filaorigem.front().tempoLimpeza>filadestino.front().tempoLimpeza){
				filadestino.push(filaorigem.front());
				filaorigem.pop();
				
			}

		}
	}

	while(!filaaux.empty()){
		filadestino.push(filaaux.front());
		filaaux.pop();
		
	}
	fila = filadestino;
	if(!fila.empty()){
		printf("Carro %s saindo da fila ... Tempo de Limpeza : %d\n",fila.front().carro,fila.front().tempoLimpeza);
		printf("Carro %s removido com sucesso ! ",fila.front().carro);
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

void imprimirFila(){
	queue<clientes> fila3;
	fila3 = fila;
	
	if(fila3.empty()){
		printf("\nA fila está vazia !");
	}else{
		printf("\nInício: -->");
		while(!fila3.empty()){
			printf("%s -",fila3.front().carro);
			fila3.pop();
		}
		printf("<-- FIM\n");
	}
	getch();
	menu();
}
void menu(){
	int opcao;
	system("cls");
	
	printf("1 - Inserir veículo na fila \n2 - Buscar veículo na fila \n3 - Verificar tamanho da fila\n4 - Remover um veículo da fila\n5 - Imprimir toda a fila\n");
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