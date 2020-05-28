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
    int dia_fabricacao;
    int mes_fabricacao;
    int ano_fabricacao;
    int dia_validade;
    int mes_validade;
    int ano_validade;
    char nome_laboratorio[40];
}vacina;



void menu(list <vacina> vacinas);
void subMenuProduzir(list <vacina> vacinas);
void produzVacinaLabRitmo(list <vacina> vacinas,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp);
void produzVacinaLabEd(list <vacina> vacinas,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp);
void produzVacinaLabRaja(list <vacina> vacinas,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp);
void produzVacinaLabComp(list <vacina> vacinas,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp);



void produzVacinaLabRitmo(list <vacina> vacinas,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){
    vacina vacinas_Struct;
    srand(1);

    printf("########## Lab-ritmo Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
    
    if(filaLabRitmo.size()<30000){
        for(int i=0;i<30000;i++){
            vacinas_Struct[i].numero_vacina = i;
            vacinas_Struct[i].dia_fabricacao = 23;
            vacinas_Struct[i].mes_fabricacao = 05;
            vacinas_Struct[i].ano_fabricacao = 2020;
            vacinas_Struct[i].dia_validade = 23;
            vacinas_Struct[i].mes_validade = 05;
            vacinas_Struct[i].ano_validade = 2021;
            strcpy(vacinas_Struct.nome_laboratorio ,'LAB-ritmo,');
            vacinas.push_front(vacinas_Struct);
            filaLabRitmo.push(vacinas_Struct);
            
        }
        printf("Vacinas Produzidas com sucesso !!!");
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 3000 vacinas !");

    }
    subMenuProduzir(vacinas,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
	exit;
    

}

void produzVacinaLabEd(list <vacina> vacinas,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){
    vacina vacinas_Struct;
    srand(1);

    printf("########## LABed Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
    
    if(filaLabEd.size()<20000){
        for(int i=0;i<20000;i++){
            vacinas_Struct[i].numero_vacina = i;
            vacinas_Struct[i].dia_fabricacao = 23;
            vacinas_Struct[i].mes_fabricacao = 05;
            vacinas_Struct[i].ano_fabricacao = 2020;
            vacinas_Struct[i].dia_validade = 23;
            vacinas_Struct[i].mes_validade = 05;
            vacinas_Struct[i].ano_validade = 2021;
            strcpy(vacinas_Struct.nome_laboratorio ,'LABed');
            vacinas.push_front(vacinas_Struct);
            filaLabEd.push(vacinas_Struct);
            
        }
        printf("Vacinas Produzidas com sucesso !!!");
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 20000 vacinas !");

    }
    subMenuProduzir(vacinas,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
	exit;

}

void produzVacinaLabRaja(list <vacina> vacinas,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){
    vacina vacinas_Struct;
    srand(1);

    printf("########## LABraja Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
    
    if(filaLabRaja.size()<18000){
        for(int i=0;i<18000;i++){
            vacinas_Struct[i].numero_vacina = i;
            vacinas_Struct[i].dia_fabricacao = 23;
            vacinas_Struct[i].mes_fabricacao = 05;
            vacinas_Struct[i].ano_fabricacao = 2020;
            vacinas_Struct[i].dia_validade = 23;
            vacinas_Struct[i].mes_validade = 05;
            vacinas_Struct[i].ano_validade = 2021;
            strcpy(vacinas_Struct.nome_laboratorio ,'LABraja');
            vacinas.push_front(vacinas_Struct);
            filaLabRaja.push(vacinas_Struct);
            
        }
        printf("Vacinas Produzidas com sucesso !!!");
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 18000 vacinas !");

    }
    subMenuProduzir(vacinas,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
	exit;


}

void produzVacinaLabComp(list <vacina> vacinas,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){
      vacina vacinas_Struct;
    srand(1);

    printf("########## LABcomp Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
    
    if(filaLabRaja.size()<15000){
        for(int i=0;i<15000;i++){
            vacinas_Struct[i].numero_vacina = i;
            vacinas_Struct[i].dia_fabricacao = 23;
            vacinas_Struct[i].mes_fabricacao = 05;
            vacinas_Struct[i].ano_fabricacao = 2020;
            vacinas_Struct[i].dia_validade = 23;
            vacinas_Struct[i].mes_validade = 05;
            vacinas_Struct[i].ano_validade = 2021;
            strcpy(vacinas_Struct.nome_laboratorio ,'LABraja');
            vacinas.push_front(vacinas_Struct);
            filaLabComp.push(vacinas_Struct);
            
        }
        printf("Vacinas Produzidas com sucesso !!!");
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 15000 vacinas !");

    }
    subMenuProduzir(vacinas,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
	exit;
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