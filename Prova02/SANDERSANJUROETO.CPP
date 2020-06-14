#include<locale.h>
#include<iostream>
#include<queue>
#include<conio.h>
#include<stdlib.h>
#include<stack>
#include<string.h>
#include<list>
#include<tr1/functional>
#include <time.h>
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

//Declaração da função para cálculo de hash
float calcula_hash_inteiro(int valor);

//Declaração da função para fechar o arquivo
void FecharArquivo(FILE *arquivo);

//Declaração função para abrir o arquivo
FILE* AbreArquivo(char modo, char caminho[30]);

//Declaração de funções de Menu e SubMenu
void menu(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void subMenuProduzir(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void subMenuRetirar (list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void subMenuEntrega(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);

//Declaração de funções de Produção de cada Laboratório
void produzVacinaLabRitmo(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void produzVacinaLabEd(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void produzVacinaLabRaja(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void produzVacinaLabComp(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);

//Declaração de funções de retirada das vacinas dos laborat´roios
void retiraVacinaLabRitmo(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void retiraVacinaLabEd(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void retiraVacinaLabRaja(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void retiraVacinaLabComp(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);

//Declaração de funções de entrega para os continentes
void entregaVacinaAmericaSul(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaAmericaCentral(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaAmericaNorte(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaAsia(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaAfrica(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaEuropa(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaOceania(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaAntartida(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);

//Função que produz vacinas para o LabRitmo
void produzVacinaLabRitmo(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    vacina vacinas_Struct; //Struct do tipo vacina
    int sobra; //Variável para armazer quantidade sobrando na fila
    int i; //Variável para laços de repetição
    char laboratorio[40] = "LAB-ritmo"; //Variável com o nome do laboratório

    printf("########## Lab-ritmo Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
    
  
    if(filaLabRitmo.size()<30000){
        sobra = 30000 - filaLabRitmo.size();
        for(i=0;i<sobra;i++){
           	srand( (unsigned)time(NULL) ); //Definindo a função rand() para gerar um número baseado no tempo atual
            vacinas_Struct.numero_vacina = rand();
            srand(1); //Definindo função rand() para gerar um número começando do 1
            vacinas_Struct.dia_fabricacao = rand() % 30;
            vacinas_Struct.mes_fabricacao = rand() % 12;
            vacinas_Struct.ano_fabricacao = 2020;
            vacinas_Struct.dia_validade = rand() % 30;
            vacinas_Struct.mes_validade = rand() % 12;
            vacinas_Struct.ano_validade = 2021;
            strcpy(vacinas_Struct.nome_laboratorio,laboratorio);
            listLabRitmo.push_front(vacinas_Struct);
            filaLabRitmo.push(vacinas_Struct);
          
        }
        printf("Vacinas Produzidas com sucesso !!!");
        printf("\nVacinas produzidas pelo laboratório %s.\nTotal de vacinas produzidas foi de %d\n",laboratorio,sobra);
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 30000 vacinas !");
    }
    getch();
    subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;
  
}

//Função que produz vacinas para o LabEd
void produzVacinaLabEd(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    vacina vacinas_Struct; //Struct do tipo vacina !
    int sobra; //Variável para armazer quantidade sobrando na fila
    int i; //Variável para laços de repetição
    char nomeLaboratorio[40] = "LABed"; //Variável com o nome do Laboratório

    printf("########## LABed Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
  
    if(filaLabEd.size()<20000){
        sobra = 20000 - filaLabEd.size();
        for(i=0;i<sobra;i++){
           srand( (unsigned)time(NULL) ); //Definindo a função rand() para gerar um número baseado no tempo atual
            vacinas_Struct.numero_vacina = rand();
            srand(1); //Definindo função rand() para gerar um número começando do 1
            vacinas_Struct.dia_fabricacao = rand() % 30;
            vacinas_Struct.mes_fabricacao = rand() % 12;
            vacinas_Struct.ano_fabricacao = 2020;
            vacinas_Struct.dia_validade = rand() % 30;
            vacinas_Struct.mes_validade = rand() % 12;
            vacinas_Struct.ano_validade = 2021;
            strcpy(vacinas_Struct.nome_laboratorio ,nomeLaboratorio);
            listLabEd.push_front(vacinas_Struct);
            filaLabEd.push(vacinas_Struct);
          
        }
        printf("Vacinas Produzidas com sucesso !!!");
        printf("\nVacinas produzidas pelo laboratório %s.\nTotal de vacinas produzidas foi de %d\n",nomeLaboratorio,sobra);
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 20000 vacinas !");
    }
    getch();
    subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;
}

//Função que produz vacinas para o LabRaja
void produzVacinaLabRaja(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    vacina vacinas_Struct;//Struct do tipo vacina
    int sobra; //Variável para armazer quantidade sobrando na fila
    int i; //Variável para laços de repetição
    char nomeLaboratorio[40] = "LABraja"; //Variável com o nome do laboratório

    printf("########## LABraja Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
  
    if(filaLabRaja.size()<18000){
        sobra = 18000 - filaLabRaja.size();
        for(i=0;i<sobra;i++){
           srand( (unsigned)time(NULL) ); //Definindo a função rand() para gerar um número baseado no tempo atual
            vacinas_Struct.numero_vacina = rand();
            srand(1); //Definindo função rand() para gerar um número começando do 1
            vacinas_Struct.dia_fabricacao = rand() % 30;
            vacinas_Struct.mes_fabricacao = rand() % 12;
            vacinas_Struct.ano_fabricacao = 2020;
            vacinas_Struct.dia_validade = rand() % 30;
            vacinas_Struct.mes_validade = rand() % 12;
            vacinas_Struct.ano_validade = 2021;
            strcpy(vacinas_Struct.nome_laboratorio ,nomeLaboratorio);
            listLabRaja.push_front(vacinas_Struct);
            filaLabRaja.push(vacinas_Struct);
          
        }
        printf("Vacinas Produzidas com sucesso !!!");
        printf("\nVacinas produzidas pelo laboratório %s.\nTotal de vacinas produzidas foi de %d",nomeLaboratorio,sobra);
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 18000 vacinas !");
    }
 	getch();
    subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
 	exit;

}
//Função que produz vacinas para o LabComp
void produzVacinaLabComp(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
  	vacina vacinas_Struct; //Struct do tipo vacina
    int sobra; //Variável para armazer quantidade sobrando na fila
    int i; //Variável para laços de repetição
  	char nomeLaboratorio[40] = "LABcomp"; //Variável com o nome do laboratório

    printf("########## LABcomp Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
  
    if(filaLabComp.size()<15000){
        sobra = 15000 - filaLabComp.size();
        for(i=0;i<15000;i++){
        	srand( (unsigned)time(NULL) ); //Definindo a função rand() para gerar um número baseado no tempo atual
            vacinas_Struct.numero_vacina = rand();
            srand(1); //Definindo função rand() para gerar um número começando do 1
            vacinas_Struct.dia_fabricacao = rand() % 30;
            vacinas_Struct.mes_fabricacao = rand() % 12;
            vacinas_Struct.ano_fabricacao = 2020;
            vacinas_Struct.dia_validade = rand() % 30;
            vacinas_Struct.mes_validade = rand() % 12;
            vacinas_Struct.ano_validade = 2021;
            strcpy(vacinas_Struct.nome_laboratorio ,nomeLaboratorio);
            listLabComp.push_front(vacinas_Struct);
            filaLabComp.push(vacinas_Struct);
          
        }
        printf("Vacinas Produzidas com sucesso !!!");
        printf("\nVacinas produzidas pelo laboratório %s.\nTotal de vacinas produzidas foi de %d",nomeLaboratorio,sobra);
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 15000 vacinas !");
    }
    getch();
    subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
 	exit;
}

//Função que retira vacina do labRitmo
void retiraVacinaLabRitmo(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
	
	int sobra; //Variável para contar quantas posições ainda há disponível na pilhaLogis
	
	if(!filaLabRitmo.empty()){
		if(pilhaLogisLabRitmo.size()<100000){
			sobra = 100000 - pilhaLogisLabRitmo.size();
			for(int i=0;i<sobra;i++){
				if(!filaLabRitmo.empty()){
					pilhaLogisLabRitmo.push(filaLabRitmo.front());
					filaLabRitmo.pop();
				}else{
					break;
					printf("A fila do LabRitmo está vazia !");
				}
			}
			printf("Vacinas retiradas com sucesso !");
		
		}else{
			printf("A pilha está com a capacidade no máximo !");
		}		
	}else{
		printf("Impossível retirar vacinas, pois a fila do LabRitmo está vazia !");
	}	
	getch();
    subMenuRetirar(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
 	exit;
}

//Função que retira vacina do labEd
void retiraVacinaLabEd(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
	
	int sobra; //Variável para contar quantas posições ainda há disponível na pilhaLogis
	
	if(!filaLabEd.empty()){
		if(pilhaLogisLabEd.size()<100000){
			sobra = 100000 - pilhaLogisLabEd.size();
			for(int i=0;i<sobra;i++){
				if(!filaLabEd.empty()){
					pilhaLogisLabEd.push(filaLabEd.front());
					filaLabEd.pop();
				}else{
					break;
					printf("A fila do LabEd está vazia !");
				}
			}
			printf("Vacinas retiradas com sucesso !");
		
		}else{
			printf("A pilha está com a capacidade no máximo !");
		}		
	}else{
		printf("Impossível retirar vacinas, pois a fila do LabEd está vazia !");
	}	
	getch();
    subMenuRetirar(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
 	exit;
}

//Função que retira vacina do labRaja
void retiraVacinaLabRaja(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
	
	int sobra; //Variável para contar quantas posições ainda há disponível na pilhaLogis
	
	if(!filaLabRaja.empty()){
		if(pilhaLogisLabRaja.size()<100000){
			sobra = 100000 - pilhaLogisLabRaja.size();
			for(int i=0;i<sobra;i++){
				if(!filaLabRaja.empty()){
					pilhaLogisLabRaja.push(filaLabRaja.front());
					filaLabRaja.pop();
				}else{
					break;
					printf("A fila do LabRaja está vazia !");
				}
			}
			printf("Vacinas retiradas com sucesso !");
		
		}else{
			printf("A pilha está com a capacidade no máximo !");
		}		
	}else{
		printf("Impossível retirar vacinas, pois a fila do LabRaja está vazia !");
	}
	getch();
    subMenuRetirar(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
 	exit;	
}

//Função que retira vacina do labComp
void retiraVacinaLabComp(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
	
	int sobra; //Variável para contar quantas posições ainda há disponível na pilhaLogis
	
	if(!filaLabComp.empty()){
		if(pilhaLogisLabComp.size()<100000){
			sobra = 100000 - pilhaLogisLabComp.size();
			for(int i=0;i<sobra;i++){
				if(!filaLabComp.empty()){
					pilhaLogisLabComp.push(filaLabComp.front());
					filaLabComp.pop();
				}else{
					break;
					printf("A fila do LabComp está vazia !");
				}
			}
			printf("Vacinas retiradas com sucesso !");
		
		}else{
			printf("A pilha está com a capacidade no máximo !");
		}		
	}else{
		printf("Impossível retirar vacinas, pois a fila do LabComp está vazia !");
	}
	getch();
    subMenuRetirar(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
 	exit;	
}

//Função para entregar vacinas na América do Sul
void entregaVacinaAmericaSul(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    
    int sobra; //Variável para armazenar a quantidade restante no espaço da pilha
    int i; //Variável para estrutura de repetição
    
    if(pilhaCDAmericaSul.size()<30000){
        sobra = 30000 - pilhaCDAmericaSul.size();
        if(!pilhaLogisLabRitmo.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaSul.push(pilhaLogisLabRitmo.top());
                pilhaLogisLabRitmo.pop();

            }
            printf("Entrega das Vacinas na América do Sul foi realizada com sucesso");
            

        }else if(!pilhaLogisLabEd.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaSul.push(pilhaLogisLabEd.top());
                pilhaLogisLabEd.pop();

            }
            printf("Entrega das Vacinas na América do Sul foi realizada com sucesso");

        }else if(!pilhaLogisLabRaja.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaSul.push(pilhaLogisLabRaja.top());
                pilhaLogisLabRaja.pop();

            }
            printf("Entrega das Vacinas na América do Sul foi realizada com sucesso");

        }else if(!pilhaLogisLabComp.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaSul.push(pilhaLogisLabComp.top());
                pilhaLogisLabComp.pop();

            }
            printf("Entrega das Vacinas na América do Sul foi realizada com sucesso");

        }

    }else{
        printf("Impossível realizar entrega, pois a pilha da América do Sul está cheia !");
    }
    getch();
    subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;	
    
}

//Função para entregar vacinas na América do Norte
void entregaVacinaAmericaNorte(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    
    int sobra; //Variável para armazenar a quantidade restante no espaço da pilha
    int i; //Variável para estrutura de repetição
    
    if(pilhaCDAmericaNorte.size()<30000){
        sobra = 30000 - pilhaCDAmericaNorte.size();
        if(!pilhaLogisLabRitmo.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaNorte.push(pilhaLogisLabRitmo.top());
                pilhaLogisLabRitmo.pop();

            }
            printf("Entrega das Vacinas na América do Norte foi realizada com sucesso");
            

        }else if(!pilhaLogisLabEd.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaNorte.push(pilhaLogisLabEd.top());
                pilhaLogisLabEd.pop();

            }
            printf("Entrega das Vacinas na América do Norte foi realizada com sucesso");

        }else if(!pilhaLogisLabRaja.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaNorte.push(pilhaLogisLabRaja.top());
                pilhaLogisLabRaja.pop();

            }
            printf("Entrega das Vacinas na América do Norte foi realizada com sucesso");

        }else if(!pilhaLogisLabComp.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaNorte.push(pilhaLogisLabComp.top());
                pilhaLogisLabComp.pop();

            }
            printf("Entrega das Vacinas na América do Norte foi realizada com sucesso");

        }

    }else{
        printf("Impossível realizar entrega, pois a pilha da América do Norte está cheia !");
    }
    getch();
    subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;	
    
}

//Função para entregar vacinas na América Central
void entregaVacinaAmericaCentral(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    
    int sobra; //Variável para armazenar a quantidade restante no espaço da pilha
    int i; //Variável para estrutura de repetição
    
    if(pilhaCDAmericaCentral.size()<30000){
        sobra = 30000 - pilhaCDAmericaCentral.size();
        if(!pilhaLogisLabRitmo.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaCentral.push(pilhaLogisLabRitmo.top());
                pilhaLogisLabRitmo.pop();

            }
            printf("Entrega das Vacinas na América do Central foi realizada com sucesso");
            

        }else if(!pilhaLogisLabEd.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaCentral.push(pilhaLogisLabEd.top());
                pilhaLogisLabEd.pop();

            }
            printf("Entrega das Vacinas na América do Central foi realizada com sucesso");

        }else if(!pilhaLogisLabRaja.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaCentral.push(pilhaLogisLabRaja.top());
                pilhaLogisLabRaja.pop();

            }
            printf("Entrega das Vacinas na América do Central foi realizada com sucesso");

        }else if(!pilhaLogisLabComp.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAmericaCentral.push(pilhaLogisLabComp.top());
                pilhaLogisLabComp.pop();

            }
            printf("Entrega das Vacinas na América do Central foi realizada com sucesso");

        }

    }else{
        printf("Impossível realizar entrega, pois a pilha da América do Central está cheia !");
    }
    getch();
    subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;	
    
}

//Função para entregar vacinas na Europa
void entregaVacinaEuropa(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    
    int sobra; //Variável para armazenar a quantidade restante no espaço da pilha
    int i; //Variável para estrutura de repetição
    
    if(pilhaCDEuropa.size()<30000){
        sobra = 30000 - pilhaCDEuropa.size();
        if(!pilhaLogisLabRitmo.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDEuropa.push(pilhaLogisLabRitmo.top());
                pilhaLogisLabRitmo.pop();

            }
            printf("Entrega das Vacinas na Europa foi realizada com sucesso");
            

        }else if(!pilhaLogisLabEd.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDEuropa.push(pilhaLogisLabEd.top());
                pilhaLogisLabEd.pop();

            }
            printf("Entrega das Vacinas na Europa foi realizada com sucesso");

        }else if(!pilhaLogisLabRaja.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDEuropa.push(pilhaLogisLabRaja.top());
                pilhaLogisLabRaja.pop();

            }
            printf("Entrega das Vacinas na Europa foi realizada com sucesso");

        }else if(!pilhaLogisLabComp.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDEuropa.push(pilhaLogisLabComp.top());
                pilhaLogisLabComp.pop();

            }
            printf("Entrega das Vacinas na Europa foi realizada com sucesso");

        }

    }else{
        printf("Impossível realizar entrega, pois a pilha da Europa está cheia !");
    }
    getch();
    subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;	
    
}

//Função para entregar vacinas na Oceania
void entregaVacinaOceania(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    
    int sobra; //Variável para armazenar a quantidade restante no espaço da pilha
    int i; //Variável para estrutura de repetição
    
    if(pilhaCDOceania.size()<30000){
        sobra = 30000 - pilhaCDOceania.size();
        if(!pilhaLogisLabRitmo.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDOceania.push(pilhaLogisLabRitmo.top());
                pilhaLogisLabRitmo.pop();

            }
            printf("Entrega das Vacinas na Oceania foi realizada com sucesso");
            

        }else if(!pilhaLogisLabEd.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDOceania.push(pilhaLogisLabEd.top());
                pilhaLogisLabEd.pop();

            }
            printf("Entrega das Vacinas na Oceania foi realizada com sucesso");

        }else if(!pilhaLogisLabRaja.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDOceania.push(pilhaLogisLabRaja.top());
                pilhaLogisLabRaja.pop();

            }
            printf("Entrega das Vacinas na Oceania foi realizada com sucesso");

        }else if(!pilhaLogisLabComp.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDOceania.push(pilhaLogisLabComp.top());
                pilhaLogisLabComp.pop();

            }
            printf("Entrega das Vacinas na Oceania foi realizada com sucesso");

        }

    }else{
        printf("Impossível realizar entrega, pois a pilha da Oceania está cheia !");
    }
    getch();
    subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;	
    
}

//Função para entregar vacinas na Ásia
void entregaVacinaAsia(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    
    int sobra; //Variável para armazenar a quantidade restante no espaço da pilha
    int i; //Variável para estrutura de repetição
    
    if(pilhaCDAsia.size()<30000){
        sobra = 30000 - pilhaCDAsia.size();
        if(!pilhaLogisLabRitmo.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAsia.push(pilhaLogisLabRitmo.top());
                pilhaLogisLabRitmo.pop();

            }
            printf("Entrega das Vacinas na Asia foi realizada com sucesso");
            

        }else if(!pilhaLogisLabEd.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAsia.push(pilhaLogisLabEd.top());
                pilhaLogisLabEd.pop();

            }
            printf("Entrega das Vacinas na Asia foi realizada com sucesso");

        }else if(!pilhaLogisLabRaja.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAsia.push(pilhaLogisLabRaja.top());
                pilhaLogisLabRaja.pop();

            }
            printf("Entrega das Vacinas na Asia foi realizada com sucesso");

        }else if(!pilhaLogisLabComp.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAsia.push(pilhaLogisLabComp.top());
                pilhaLogisLabComp.pop();

            }
            printf("Entrega das Vacinas na Asia foi realizada com sucesso");

        }

    }else{
        printf("Impossível realizar entrega, pois a pilha da Asia está cheia !");
    }
    getch();
    subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;	
    
}

//Função para entregar vacinas na Antártida
void entregaVacinaAntartida(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    
    int sobra; //Variável para armazenar a quantidade restante no espaço da pilha
    int i; //Variável para estrutura de repetição
    
    if(pilhaCDAntartida.size()<30000){
        sobra = 30000 - pilhaCDAntartida.size();
        if(!pilhaLogisLabRitmo.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAntartida.push(pilhaLogisLabRitmo.top());
                pilhaLogisLabRitmo.pop();

            }
            printf("Entrega das Vacinas na Antártida foi realizada com sucesso");
            

        }else if(!pilhaLogisLabEd.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAntartida.push(pilhaLogisLabEd.top());
                pilhaLogisLabEd.pop();

            }
            printf("Entrega das Vacinas na Antártida foi realizada com sucesso");

        }else if(!pilhaLogisLabRaja.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAntartida.push(pilhaLogisLabRaja.top());
                pilhaLogisLabRaja.pop();

            }
            printf("Entrega das Vacinas na Antártida foi realizada com sucesso");

        }else if(!pilhaLogisLabComp.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAntartida.push(pilhaLogisLabComp.top());
                pilhaLogisLabComp.pop();

            }
            printf("Entrega das Vacinas na Antártida foi realizada com sucesso");

        }

    }else{
        printf("Impossível realizar entrega, pois a pilha da Antártida está cheia !");
    }
    getch();
    subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;	
    
}

//Função para entregar vacinas na Africa
void entregaVacinaAfrica(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    
    int sobra; //Variável para armazenar a quantidade restante no espaço da pilha
    int i; //Variável para estrutura de repetição
    
    if(pilhaCDAfrica.size()<30000){
        sobra = 30000 - pilhaCDAfrica.size();
        if(!pilhaLogisLabRitmo.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAfrica.push(pilhaLogisLabRitmo.top());
                pilhaLogisLabRitmo.pop();

            }
            printf("Entrega das Vacinas na África foi realizada com sucesso");
            

        }else if(!pilhaLogisLabEd.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAfrica.push(pilhaLogisLabEd.top());
                pilhaLogisLabEd.pop();

            }
            printf("Entrega das Vacinas na África foi realizada com sucesso");

        }else if(!pilhaLogisLabRaja.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAfrica.push(pilhaLogisLabRaja.top());
                pilhaLogisLabRaja.pop();

            }
            printf("Entrega das Vacinas na África foi realizada com sucesso");

        }else if(!pilhaLogisLabComp.empty()){
            for(i = 0; i < sobra; i++){
                pilhaCDAfrica.push(pilhaLogisLabComp.top());
                pilhaLogisLabComp.pop();

            }
            printf("Entrega das Vacinas na África foi realizada com sucesso");

        }

    }else{
        printf("Impossível realizar entrega, pois a pilha da África está cheia !");
    }
    getch();
    subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;	
    
}

//Função que gera o submenu para produção de vacinas
void subMenuProduzir(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    
    int opcao; //Variável para armazenar opção escolhida
  
    system("cls");
    printf("1 - LAB-ritmo\n2 - LABed\n3 - LABraja\n4 - LABcomp\n5 - Voltar ao Menu anterior");
    printf("\nEscolha uma opção : ");
    scanf("%d",&opcao);
    switch(opcao){
        case 1:
            system("cls");
            produzVacinaLabRitmo(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
        
        case 2:
            system("cls");
            produzVacinaLabEd(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
        
        case 3:
            system("cls");
            produzVacinaLabRaja(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
        
        case 4:
            system("cls");
            produzVacinaLabComp(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
      
        case 5:
            system("cls");
            menu(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;

        default:
            printf("Escolha uma opção válida \n");
            system("pause");
            system("cls");
            subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    }

}

//Função que gera o Sub Menu de retirada das vacinas
void subMenuRetirar (list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
	int opcao; //Variável para armazenar a opção escolhida
	system("cls");
	printf("Escolha de qual empresa deseja retirar a vacina : ");
	printf("\n1 - LabRitmo\n2 - LabEd\n3 - LabRaja\n4 - LabComp\n5 - Voltar");
	printf("\nEscolha uma opção : ");
	scanf("%d",&opcao);
    switch(opcao){
        case 1:
            system("cls");
            retiraVacinaLabRitmo(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
        
        case 2:
            system("cls");
            retiraVacinaLabEd(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
        
        case 3:
            system("cls");
            retiraVacinaLabRaja(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
        
        case 4:
            system("cls");
            retiraVacinaLabComp(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
      
        case 5:
            system("cls");
            menu(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
        
        default:
            printf("Escolha uma opção válida \n");
            system("pause");
            system("cls");
            subMenuRetirar(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
	}
}

void subMenuEntrega(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
	int opcao;
	system("cls");
	printf("Escolha em qual continente será entregue as vacinas !");
	printf("\n1 - América do Norte\n2 - América do Sul\n3 - América Central\n4 - África\n5 - Ásia\n6 - Europa\n7 - Oceania\n8 - Antártida\n9 - Voltar");
	printf("\nEscolha uma opção : ");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAmericaNorte(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }
                    
        case 2:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAmericaSul(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;        
            }
        
        case 3:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAmericaCentral(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;            
            }

        case 4:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAfrica(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;     
            }

        case 5:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAsia(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 6:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaEuropa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 7:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaOceania(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 8:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAntartida(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }
            
        case 9:
        	system("cls");
        	menu(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        	break;
            
        default:
            printf("Escolha uma opção válida \n");
            system("pause");
            system("cls");
            subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
	}
	
}

void subMenuEntregaPaises(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
	int opcao;
	system("cls");
	printf("Escolha em qual continente será entregue as vacinas !");
	printf("\n1 - América do Norte\n2 - América do Sul\n3 - América Central\n4 - África\n5 - Ásia\n6 - Europa\n7 - Oceania\n8 - Antártida\n9 - Voltar");
	printf("\nEscolha uma opção : ");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAmericaNorte(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }
                    
        case 2:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAmericaSul(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;        
            }
        
        case 3:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAmericaCentral(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;            
            }

        case 4:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAfrica(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;     
            }

        case 5:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAsia(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 6:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaEuropa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 7:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaOceania(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 8:
            system("cls");
            if(pilhaLogisLabRitmo.size() == 100000 || pilhaLogisLabEd.size() == 100000 || pilhaLogisLabRaja.size() == 100000 || pilhaLogisLabComp.size() == 100000){
                entregaVacinaAntartida(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }
            
        case 9:
        	system("cls");
        	menu(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        	break;
            
        default:
            printf("Escolha uma opção válida \n");
            system("pause");
            system("cls");
            subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
	}
	
}
//Função que gera o Menu
void menu(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    int opcao; //Variável para armazenar a opção escolhida
    system("cls");
    printf("1 - Produzir Vacinas\n2 - Listar Vacinas\n3 - Retirar Vacina da Empresa\n4 - Entregar Vacinas aos Continentes\n5 - Entregar Vacinas aos Países\n6 - Sair");
    printf("\nEscolha uma opção: ");
    scanf("%d",&opcao);
    switch(opcao){
        case 1:
            system("cls");
            subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
            
        case 2:
            system("cls");
            subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
            
        case 3:
        	system("cls");
        	subMenuRetirar(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        	break;
        
        case 4:
        	system("cls");
        	subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        	break;
     
        default:
            printf("Escolha uma opção válida \n");
            system("pause");
            system("cls");
            menu(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
   
    }
}

//Função que Abre o arquivo retornando o hash
FILE* AbreArquivo(char modo, char caminho[30]){
    FILE *arquivo;
    switch(modo){
        case 'g':
            arquivo = fopen(caminho,"wt");
            break;
        case 'l':
            arquivo = fopen(caminho,"rt");
            break;
        case 'a':
            arquivo = fopen(caminho,"a");
            break;
    }
    if(arquivo==NULL){      //Se houver algum erro, o ponteiro apontará para NULL
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}

//Função que fecha o arquivo
void FecharArquivo(FILE *arquivo)
{
    fclose(arquivo);
}

//Função que calcula o hash
float calcula_hash_inteiro(int valor){
    std::tr1::hash<float> hash_fn;
    size_t str_hash = hash_fn(valor);
    return(str_hash);
}

//Função principal
int main(){
    float HashDaSenha;
    int senha;
    FILE *arquivo;
    
    //Listas do tipo vacina referentes à cada laboratorio 
    list <vacina> listLabRitmo;
    list <vacina> listLabEd;
    list <vacina> listLabRaja;
    list <vacina> listLabComp;
    
    //Filas do tipo vacinas referentes à cada laboratório
    queue <vacina> filaLabRitmo;
    queue <vacina> filaLabEd;
    queue <vacina> filaLabRaja;
    queue <vacina> filaLabComp;
    
    //Pilhas Logis referentes à cada laboratório
    stack<vacina> pilhaLogisLabRitmo;
	stack<vacina> pilhaLogisLabEd;
	stack<vacina> pilhaLogisLabRaja;
	stack<vacina> pilhaLogisLabComp;
	
	//Pilhas dos Centros de Distribuições da Logis referentes à cada continente
	stack<vacina> pilhaCDAmericaSul;
	stack<vacina> pilhaCDAmericaNorte;
	stack<vacina> pilhaCDAmericaCentral;
	stack<vacina> pilhaCDOceania;	
	stack<vacina> pilhaCDAsia;
	stack<vacina> pilhaCDEuropa;
	stack<vacina> pilhaCDAntartida;
	stack<vacina> pilhaCDAfrica;

 
    setlocale(LC_ALL, "Portuguese");
    float hash;
    arquivo = AbreArquivo('l', "password.txt");
    fscanf(arquivo, "%f ", &HashDaSenha); // Ler hash do arquivo e guardar na variável
    
	do{
        system("cls");
        printf("\nDigite a senha : ");
        scanf("%d",&senha);
        hash = calcula_hash_inteiro(senha);
    }while(hash != HashDaSenha);
    
    printf("!!Usuário Autenticado!!\n");
    printf("Bem Vindo ao sistema de Vacinas Covid-19");
   
    menu(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
   
   
    system("pause");
}