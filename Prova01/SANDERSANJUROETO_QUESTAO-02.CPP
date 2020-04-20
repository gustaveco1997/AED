/*
	02 - O Cine Algorítmico está oferendo entradas grátis para qualquer uma de suas 5 salas,
	que estão passando 5 filmes diferentes. Diversas pessoas estão formando uma fila para
	conseguir os ingressos gratuitos. O único porém é que não é possível escolher qual filme
	se vai assistir: a moça da bilheteria, que se chama Paloma, tem uma pilha de ingressos
	embaralhados e ela simplesmente entrega o ingresso do topo da pilha para quem está
	na frente da fila.
	Em troca do ingresso, Paloma obtém dados pessoais dos agraciados. Ela insere em um
	vetor de struct: o nome de quem ganhou o ingresso, qual filme vai assistir, o número do
	telefone celular, o e-mail do agraciado.
	Escreva um programa que implementa o sistema acima, inclusive a fila e pilha. Todas as
	operações vistas em aula devem estar presentes.
	Execute testes exaustivos, mostrando que seu programa funciona nas mais diversas
	situações (ex. pilha vazia, fila cheia, etc etc). Para testar, encha a fila com pessoas. Para
	preencher a pilha, escolha 5 dos teus filmes favoritos. Lembre-se que ordem que eles
	aparecem na pilha é aleatória, e a pilha pode ter mais de 5 ingressos. O programa deve
	ter uma opção para imprimir a lista de agraciados, mostrando os dados de quem ganhou
	qual ingresso. Para as três estruturas você deve implementar procedimentos que
	permitam ao usuário listar a estrutura na tela a qualquer momento.
*/

#include<iostream>
#include<queue>
#include<conio.h>
#include<stdlib.h>
#include<stack>
#include<string.h>


using namespace std;

//Estrutura Filmes
typedef struct{
	char nomeFilme[40];
	int salaFilme;
}filmes;

//Estrutura Ingressos
typedef struct{
	int codigoIngresso;
	int numeroSala;
	char nomeFilme[40];
}ingressos;

//Estrutura Agraciados
typedef struct{
	char nome[40];
	char celular[40] ;
	char email[40];
}agraciados;

//Estrutura Ganhadores
typedef struct{
	char nome[40];
	char celular[40];
	char email[40];
	char nomeFilme[40];
}ganhadores;

//Vetor de Struct pessoas da estrutura ganhadores !
ganhadores pessoas[40];

//Contador para armazenar quantidade de Clientes com ingresso !
int contador=0;

//Fila do tipo Agraciados
queue<agraciados> fila;

// Pilha do tipo ingressos
stack<ingressos> pilhaIngressos;

//Pilha do tipo Filmes
stack<filmes> pilhaFilmes;



void insertFilmes();
void menu();
void insertPessoas();
void imprimePessoas();
void removePessoas();
void insertIngressos();
void imprimeIngressos();
void insertFilmes();
void imprimeVetor();

/*
	Função que insere pessoas na fila de forma automática !

	Vetores nomes,emails e telefones  com 25 posições para preencher a fila com dados completos das pessoas !
	
*/
void insertPessoas(){
	agraciados pessoas;

	//Verifica se a Pilha de ingressos está cheia !
	if(!pilhaIngressos.empty()){
		char nomes[25][40] = {"Sander","Sauer","André","Arthur","Caio","Leila","Jussara","Leticia","Sara","Paulo","Henrique","Roberto","Gustavo","João","Jair","Vera","Lucas","Guilherme","Gabriel","Junior","Pablo","Marcos","Marcelo","Douglas","Daivid"};
		char emails[25][40]={"sander@gmail.com","andre@gmail.com","caio@gmail.com","leila@gmail.com","leticia@gmail.com","sara@gmail.com","paulo@gmail.com","henrique@gmail.com","roberto@gmail.com","gustavo@gmail.com","joao@gmail.com","jair@gmail.com","vera@gmail.com","lucas@gmail.com","guilherme@gmail.com","gabriel@gmail.com","junior@gmail.com","pablo@gmail.com","marcos@gmail.com","marcelo@gmail.com","douglas@gmail.com","davi@gmail.com"};
		char telefones[25][40]={"(31)99505-1259","(31)99005-1739","(31)99645-1239","(31)99235-1752","(31)98605-1729","(31)99604-1752","(31)99502-1159","(31)98605-1349","(31)99202-1529","(31)99604-1252","(31)99205-1459","(31)98905-1219","(31)99206-6629","(31)99234-5229","(31)99236-1259","(31)99922-7329","(31)99208-5829","(31)99125-2352","(31)99826-4732","(31)99623-7529","(31)99652-3632","(31)99632-1269","(31)99605-1260","(31)99325-0759","(31)99605-1730",};
		for(int i = 0;i<25;i++){
			strcpy(pessoas.nome,nomes[i]);
			strcpy(pessoas.email,emails[i]);
			strcpy(pessoas.celular,telefones[i]);
			fila.push(pessoas);
		}
		printf("Fila preenchida com sucesso !");	
	}else{
		printf("Não temos ingressos disponíveis !");
	}

	
	getch();
	menu();
	exit;
}

//Função que imprime as pessoas que estão na fila !
void imprimePessoas(){
	queue <agraciados> filaTemp;
	filaTemp = fila;

	if(filaTemp.empty()){
		printf("A fila está vazia !");
		getch();
		menu();
		exit;
	}

	while(!filaTemp.empty()){
		printf("%s\n",filaTemp.front().nome);
		filaTemp.pop();
	}
	
	getch();
	menu();
	exit;
}

//Função que remove pessoas da Fila !
void removePessoas(){
	stack <ingressos> pilhaTemp;
	pilhaTemp = pilhaIngressos;
	queue <agraciados> filaTemp;
	filaTemp = fila;

	if(pilhaTemp.empty() || filaTemp.empty()){
		if(filaTemp.empty()){
			printf("A fila está vazia !");
			getch();
			menu();
			exit;
		}else if(pilhaTemp.empty()){
			printf("Não existe ingressos !");
			getch();
			menu();
			exit;
		}
	}
	

	
	while(!pilhaTemp.empty()&&!fila.empty()){
		for(int i=0;i<40;i++){

			//Verifica se a Pilha de Ingressos e Fila estaõ cheias
			if(!pilhaTemp.empty()&&!filaTemp.empty()){
				strcpy(pessoas[i].nome,filaTemp.front().nome);
				strcpy(pessoas[i].email,filaTemp.front().email);
				strcpy(pessoas[i].celular,filaTemp.front().celular);
				strcpy(pessoas[i].nomeFilme,pilhaTemp.top().nomeFilme);
				pilhaTemp.pop();
				filaTemp.pop();
				contador++;	
				
			}else{
				
				break;
			}
		}
		break;	
	}
	
	fila = filaTemp;
	pilhaIngressos = pilhaTemp;

	if(fila.size()>0){
		printf("As pessoas que ficaram sem ingressos foram: \n");
	}

	while(!fila.empty()){
		printf("%s \n",fila.front().nome);
		fila.pop();	
								
	}
	if(pilhaTemp.size()>0){
		printf("Os ingressos que sobraram foram :\n");
	}
	
	while(!pilhaTemp.empty()){
		printf("%s\n",pilhaTemp.top().nomeFilme);
		pilhaTemp.pop();
			
	}	
		
	getch();
	menu();

	

	
}

//Função que insere Ingressos
void insertIngressos(){

	ingressos ingresso;
	stack<filmes> pilhaTemp;
	pilhaTemp = pilhaFilmes;

	//Definir o rand para começar no 1;
	srand(1);

	//Verifica se a pilha está cheia
	if(!pilhaTemp.empty()){
		for(int i=1;i<6;i++){
			pilhaTemp = pilhaFilmes;
			ingresso.codigoIngresso = i;
			ingresso.numeroSala = rand() % 6;
			while(!pilhaTemp.empty()){
				if(pilhaTemp.top().salaFilme == ingresso.numeroSala){
					strcpy(ingresso.nomeFilme ,pilhaTemp.top().nomeFilme);
					pilhaTemp.pop();
					
				}else{
					pilhaTemp.pop();
				}
			}
			pilhaIngressos.push(ingresso);
		}
		printf("Ingressos Inseridos com sucesso !");
	}else{
		printf("A pilha de filme está vazia. Preencha por favor !");
	}
	
	getch();	
	menu();
	exit;
	
}

//Função que imprime a pilha de ingressos
void imprimeIngressos(){
	stack <ingressos> pilhaIngressosTemp;
	pilhaIngressosTemp = pilhaIngressos;

	if(pilhaIngressosTemp.empty()){
		printf("A pilha de ingressos está vazia !");
		getch();
		menu();
		exit;
	}
	
	while(!pilhaIngressosTemp.empty()){
		printf("%s\n",pilhaIngressosTemp.top().nomeFilme);
		pilhaIngressosTemp.pop();
	}
	getch();
	menu();
	
}

//Função que preenche a pilha de Filmes
void insertFilmes(){

	filmes listaFilme;

	//Vetor com os filmes à ser inseridos na pilha !
	char filmes[5][40]={"Velozes e Furiosos","A Cabana","Missão Impossível","O Justiceiro","Exterminador do Futuro"};
	
	for(int i=0;i<5;i++){
		strcpy(listaFilme.nomeFilme,filmes[i]);
		listaFilme.salaFilme = i+1;
		pilhaFilmes.push(listaFilme);
	}
		
	printf("Filmes inseridos com sucesso !");
	getch();
	menu();
	exit;
}

//Função que imprime a pilha de Filmes;
void imprimePilhaFilme(){
	stack <filmes> pilhaTemp;
	pilhaTemp = pilhaFilmes;


	if(pilhaTemp.empty()){
		printf("A pilha de filmes está vazia !");
		getch();
		menu();
		exit;
	}
	
	while(!pilhaTemp.empty()){
		printf("%s\n",pilhaTemp.top().nomeFilme);
		pilhaTemp.pop();
	}
	getch();
	menu();
}

//Função que imprime o vetor de struct com os dados dos ganhadores dos ingressos!
void imprimeVetor(){

	if(contador == 0){
		printf("Não foram gerados ganhadores, verifique as inserções de ingressos, filmes e pessoas por favor !");
		getch();
		menu();
		exit;
	}

	printf("Os dados das pessoas ganhadores de ingressos são : \n");
	for(int i=0;i<contador;i++){
		printf("Nome - %s\n",pessoas[i].nome);
		printf("Email - %s\n",pessoas[i].email);
		printf("Celular - %s\n",pessoas[i].celular);
		printf("Filme à assistir - %s\n\n",pessoas[i].nomeFilme);
		
	}
	getch();
	menu();
}

//Função que gera o Menu
void menu(){
	int opcao;
	system("cls");
	
	printf("1 - Inserir Filme na pilha \n2 - Imprimir pilha de filmes \n3 - Gerar Ingressos\n4 - Imprimir Ingressos\n5 - Preencher Fila\n6 - Imprimir Fila\n7 - Remover toda a fila\n8 - Imprimir informações dos ganhadores\n");
	scanf("%d",&opcao);
	
	switch(opcao){
		case 1:
			system("cls");
			insertFilmes();
			break;
		case 2:
			system("cls");
			imprimePilhaFilme();
			break;
			
		case 3:
			system("cls");
			insertIngressos();
			break;
			
		case 4:
			system("cls");
			imprimeIngressos();
			break;
		case 5:
			system("cls");
			insertPessoas();
			break;
		case 6:
			system("cls");
			imprimePessoas();
			break;
		case 7:
			system("cls");
			removePessoas();
			break;	
			
		case 8:
			system("cls");
			imprimeVetor();
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
