/*
    01 - Assumindo que os elementos de uma lista L1 são inteiros positivos, 
    fornecer os elementos que aparecem o maior e o menor número de vezes 
    (forneça os elementos e o número de vezes correspondente).
    - Exemplo: Temos uma lista de: 
    12 - 23 -34 - 34 - 45 - 56 - 12 - 2 - 3 - 4 - 5- 6 - 7 - 1 - 3 - 4 - 5 --> 
    Dessa lista preenchida, o seu algoritmo tem de o número com maior incidência e o com menor.
*/

#include <iostream>
#include <list>
#include <locale.h>

using namespace std;
void insere(list <int> lista);
void imprime(list <int> lista);
void menu(list <int> lista);


void insere(list <int> lista){
	for(int i=0;i<10;i++){
        lista.push_front(rand());
    }
}

void imprime(list <int> lista){
	list<int>::iterator it;
    printf("Imprimindo a Lista\n");
	printf("\t");
	
	for(it = lista.begin(); it!=lista.end();it++){
		printf("%d - ",*it);		
	}
	printf("\n");
	it--;
}

//Função que gera o Menu
void menu(list <int> lista){
	int opcao;
	system("cls");

	printf("1 - Preencher Lista\n2 - Imprimir Lista\n3 - Números que mais se repetem\n4 - Numeros que menos se repetem\n6 - Sair");
	printf("\nEscolha uma opção: ");
	scanf("%d",&opcao);

	switch(opcao){
		case 1:
			system("cls");
			insere(lista);
			break;

		case 2:
			system("cls");
			imprime(lista);
			break;

	
		default:
			printf("Escolha uma opção válida \n");
			system("pause");
			system("cls");
			menu(lista);
		
	}
}



int main(){
	
	list<int> lista;
	
	list<int>::iterator it;
	
    setlocale (LC_ALL, "Portuguese");
    menu(lista);
	
	
}