#include<locale.h>
#include<iostream>
#include<queue>
#include<conio.h>
#include<stdlib.h>
#include<stack>
#include<string.h>
#include<list>
#include<tr1/functional>
#include<time.h>
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
void subMenuTipoPesquisa (list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica,int lab);
void subMenuPesquisa (list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
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
void entregaVacinaPaisAmericaNorte(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void subMenuEntregaPaises(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);

//Declaração de funções de entrega aos países de cada continente
void entregaVacinaPaisAmericaNorte(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaPaisAmericaSul(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaPaisAmericaCentral(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaPaisEuropa(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaPaisAfrica(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaPaisAsia(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaPaisOceania(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);
void entregaVacinaPaisAntartida(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica);

void pesquisaDataValidade(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica,int lab);
//Função que produz vacinas para o LabRitmo
void produzVacinaLabRitmo(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    vacina vacinas_Struct; //Struct do tipo vacina
    int sobra; //Variável para armazer quantidade sobrando na fila
    int i; //Variável para laços de repetição
    srand( (unsigned)time(NULL) ); //Definindo a função rand() para gerar um número baseado no tempo atual
    char laboratorio[40] = "LAB-ritmo"; //Variável com o nome do laboratório

    printf("########## Lab-ritmo Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
    
  
    if(filaLabRitmo.size()<30000){
        sobra = 30000 - filaLabRitmo.size();
        for(i=0;i<sobra;i++){
           	
            vacinas_Struct.numero_vacina = rand();
            
            vacinas_Struct.dia_fabricacao = rand() % 29 + 1; //Usa-se a função rand() de 0 à 29 , porém somando +1, para nunca dar 0
            vacinas_Struct.mes_fabricacao = rand() % 11 + 1; //Usa-se a função rand() de 0 à 11 , porém somando +1, para nunca dar 0
            vacinas_Struct.ano_fabricacao = 2020;
            vacinas_Struct.dia_validade = rand() % 29 + 1; //Usa-se a função rand() de 0 à 29 , porém somando +1, para nunca dar 0
            vacinas_Struct.mes_validade = rand() % 11 + 1; //Usa-se a função rand() de 0 à 11 , porém somando +1, para nunca dar 0
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
    srand( (unsigned)time(NULL) ); //Definindo a função rand() para gerar um número baseado no tempo atual
    int sobra; //Variável para armazer quantidade sobrando na fila
    int i; //Variável para laços de repetição
    char nomeLaboratorio[40] = "LABed"; //Variável com o nome do Laboratório

    printf("########## LABed Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
  
    if(filaLabEd.size()<20000){
        sobra = 20000 - filaLabEd.size();
        for(i=0;i<sobra;i++){           
            vacinas_Struct.numero_vacina = rand();
            vacinas_Struct.dia_fabricacao = rand() % 29 + 1; //Usa-se a função rand() de 0 à 29 , porém somando +1, para nunca dar 0
            vacinas_Struct.mes_fabricacao = rand() % 11 + 1; //Usa-se a função rand() de 0 à 11 , porém somando +1, para nunca dar 0
            vacinas_Struct.ano_fabricacao = 2020;
            vacinas_Struct.dia_validade = rand() % 29 + 1; //Usa-se a função rand() de 0 à 29 , porém somando +1, para nunca dar 0
            vacinas_Struct.mes_validade = rand() % 11 + 1; //Usa-se a função rand() de 0 à 11 , porém somando +1, para nunca dar 0
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
    srand( (unsigned)time(NULL) ); //Definindo a função rand() para gerar um número baseado no tempo atual
    int sobra; //Variável para armazer quantidade sobrando na fila
    int i; //Variável para laços de repetição
    char nomeLaboratorio[40] = "LABraja"; //Variável com o nome do laboratório

    printf("########## LABraja Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
  
    if(filaLabRaja.size()<18000){
        sobra = 18000 - filaLabRaja.size();
        for(i=0;i<sobra;i++){
            vacinas_Struct.numero_vacina = rand();
            vacinas_Struct.dia_fabricacao = rand() % 29 + 1; //Usa-se a função rand() de 0 à 29 , porém somando +1, para nunca dar 0
            vacinas_Struct.mes_fabricacao = rand() % 11 + 1; //Usa-se a função rand() de 0 à 11 , porém somando +1, para nunca dar 0
            vacinas_Struct.ano_fabricacao = 2020;
            vacinas_Struct.dia_validade = rand() % 29 + 1; //Usa-se a função rand() de 0 à 29 , porém somando +1, para nunca dar 0
            vacinas_Struct.mes_validade = rand() % 11 + 1; //Usa-se a função rand() de 0 à 11 , porém somando +1, para nunca dar 0
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
    srand( (unsigned)time(NULL) ); //Definindo a função rand() para gerar um número baseado no tempo atual
    int sobra; //Variável para armazer quantidade sobrando na fila
    int i; //Variável para laços de repetição
  	char nomeLaboratorio[40] = "LABcomp"; //Variável com o nome do laboratório

    printf("########## LABcomp Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
  
    if(filaLabComp.size()<15000){
        sobra = 15000 - filaLabComp.size();
        for(i=0;i<15000;i++){       	
            vacinas_Struct.numero_vacina = rand();
            vacinas_Struct.dia_fabricacao = rand() % 29 + 1; //Usa-se a função rand() de 0 à 29 , porém somando +1, para nunca dar 0
            vacinas_Struct.mes_fabricacao = rand() % 11 + 1; //Usa-se a função rand() de 0 à 11 , porém somando +1, para nunca dar 0
            vacinas_Struct.ano_fabricacao = 2020;
            vacinas_Struct.dia_validade = rand() % 29 + 1; //Usa-se a função rand() de 0 à 29 , porém somando +1, para nunca dar 0
            vacinas_Struct.mes_validade = rand() % 11 + 1; //Usa-se a função rand() de 0 à 11 , porém somando +1, para nunca dar 0
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

//Função que entrega vacinas aos países da América do Norte
void entregaVacinaPaisAmericaNorte(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    int i; //Variável para estrutura de repetição
    printf("Foram entregues %d vacinas no continente da América do Norte !\n", pilhaCDAmericaNorte.size());
    printf("Vacinas entregues. Segue abaixo informações das vacinas que foram entregues !\n");
    for(i=0;i<pilhaCDAmericaNorte.size();i++){
        
        printf("Codigo: %d\nData de Fabricação: %d/%d/%d\nData de Validade: %d/%d/%d\nNome do Laboratório: %s\n#######################################################\n",pilhaCDAmericaNorte.top().numero_vacina,pilhaCDAmericaNorte.top().dia_fabricacao,pilhaCDAmericaNorte.top().mes_fabricacao,pilhaCDAmericaNorte.top().ano_fabricacao,pilhaCDAmericaNorte.top().dia_validade,pilhaCDAmericaNorte.top().mes_validade,pilhaCDAmericaNorte.top().ano_validade,pilhaCDAmericaNorte.top().nome_laboratorio);
        pilhaCDAmericaNorte.pop();
    }
    getch();
    subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;
}

//Função que entrega vacinas aos países da América do Sul
void entregaVacinaPaisAmericaSul(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    int i; //Variável para estrutura de repetição
    printf("Foram entregues %d vacinas no continente da América do Sul !\n", pilhaCDAmericaSul.size());
    printf("Vacinas entregues. Segue abaixo informações das vacinas que foram entregues !\n");
    for(i=0;i<pilhaCDAmericaSul.size();i++){
        
        printf("Codigo: %d\nData de Fabricação: %d/%d/%d\nData de Validade: %d/%d/%d\nNome do Laboratório: %s\n#######################################################\n",pilhaCDAmericaSul.top().numero_vacina,pilhaCDAmericaSul.top().dia_fabricacao,pilhaCDAmericaSul.top().mes_fabricacao,pilhaCDAmericaSul.top().ano_fabricacao,pilhaCDAmericaSul.top().dia_validade,pilhaCDAmericaSul.top().mes_validade,pilhaCDAmericaSul.top().ano_validade,pilhaCDAmericaSul.top().nome_laboratorio);
        pilhaCDAmericaSul.pop();
    }
    getch();
    subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;
}

//Função que entrega vacinas aos países da América Central
void entregaVacinaPaisAmericaCentral(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    int i; //Variável para estrutura de repetição
    printf("Foram entregues %d vacinas no continente da América do Central !\n", pilhaCDAmericaCentral.size());
    printf("Vacinas entregues. Segue abaixo informações das vacinas que foram entregues !\n");
    for(i=0;i<pilhaCDAmericaCentral.size();i++){
        
        printf("Codigo: %d\nData de Fabricação: %d/%d/%d\nData de Validade: %d/%d/%d\nNome do Laboratório: %s\n#######################################################\n",pilhaCDAmericaCentral.top().numero_vacina,pilhaCDAmericaCentral.top().dia_fabricacao,pilhaCDAmericaCentral.top().mes_fabricacao,pilhaCDAmericaCentral.top().ano_fabricacao,pilhaCDAmericaCentral.top().dia_validade,pilhaCDAmericaCentral.top().mes_validade,pilhaCDAmericaCentral.top().ano_validade,pilhaCDAmericaCentral.top().nome_laboratorio);
        pilhaCDAmericaCentral.pop();
    }
    getch();
    subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;
}

//Função que entrega vacinas aos países da Europa
void entregaVacinaPaisEuropa(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    int i; //Variável para estrutura de repetição
    printf("Foram entregues %d vacinas no continente da Europa !\n", pilhaCDEuropa.size());
    printf("Vacinas entregues. Segue abaixo informações das vacinas que foram entregues !\n");
    for(i=0;i<pilhaCDEuropa.size();i++){
        
        printf("Codigo: %d\nData de Fabricação: %d/%d/%d\nData de Validade: %d/%d/%d\nNome do Laboratório: %s\n#######################################################\n",pilhaCDEuropa.top().numero_vacina,pilhaCDEuropa.top().dia_fabricacao,pilhaCDEuropa.top().mes_fabricacao,pilhaCDEuropa.top().ano_fabricacao,pilhaCDEuropa.top().dia_validade,pilhaCDEuropa.top().mes_validade,pilhaCDEuropa.top().ano_validade,pilhaCDEuropa.top().nome_laboratorio);
        pilhaCDEuropa.pop();
    }
    getch();
    subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;
}

//Função que entrega vacinas aos países da África
void entregaVacinaPaisAfrica(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    int i; //Variável para estrutura de repetição
    printf("Foram entregues %d vacinas no continente da África !\n", pilhaCDAfrica.size());
    printf("Vacinas entregues. Segue abaixo informações das vacinas que foram entregues !\n");
    for(i=0;i<pilhaCDAfrica.size();i++){
        
        printf("Codigo: %d\nData de Fabricação: %d/%d/%d\nData de Validade: %d/%d/%d\nNome do Laboratório: %s\n#######################################################\n",pilhaCDAfrica.top().numero_vacina,pilhaCDAfrica.top().dia_fabricacao,pilhaCDAfrica.top().mes_fabricacao,pilhaCDAfrica.top().ano_fabricacao,pilhaCDAfrica.top().dia_validade,pilhaCDAfrica.top().mes_validade,pilhaCDAfrica.top().ano_validade,pilhaCDAfrica.top().nome_laboratorio);
        pilhaCDAfrica.pop();
    }
    getch();
    subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;
}

//Função que entrega vacinas aos países da Ásia
void entregaVacinaPaisAsia(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    int i; //Variável para estrutura de repetição
    printf("Foram entregues %d vacinas no continente da Ásia !\n", pilhaCDAsia.size());
    printf("Vacinas entregues. Segue abaixo informações das vacinas que foram entregues !\n");
    for(i=0;i<pilhaCDAsia.size();i++){
        
        printf("Codigo: %d\nData de Fabricação: %d/%d/%d\nData de Validade: %d/%d/%d\nNome do Laboratório: %s\n#######################################################\n",pilhaCDAsia.top().numero_vacina,pilhaCDAsia.top().dia_fabricacao,pilhaCDAsia.top().mes_fabricacao,pilhaCDAsia.top().ano_fabricacao,pilhaCDAsia.top().dia_validade,pilhaCDAsia.top().mes_validade,pilhaCDAsia.top().ano_validade,pilhaCDAsia.top().nome_laboratorio);
        pilhaCDAsia.pop();
    }
    getch();
    subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;
}

//Função que entrega vacinas aos países da Oceania
void entregaVacinaPaisOceania(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    int i; //Variável para estrutura de repetição
    printf("Foram entregues %d vacinas no continente da Oceania !\n", pilhaCDOceania.size());
    printf("Vacinas entregues. Segue abaixo informações das vacinas que foram entregues !\n");
    for(i=0;i<pilhaCDOceania.size();i++){
        
        printf("Codigo: %d\nData de Fabricação: %d/%d/%d\nData de Validade: %d/%d/%d\nNome do Laboratório: %s\n#######################################################\n",pilhaCDOceania.top().numero_vacina,pilhaCDOceania.top().dia_fabricacao,pilhaCDOceania.top().mes_fabricacao,pilhaCDOceania.top().ano_fabricacao,pilhaCDOceania.top().dia_validade,pilhaCDOceania.top().mes_validade,pilhaCDOceania.top().ano_validade,pilhaCDOceania.top().nome_laboratorio);
        pilhaCDOceania.pop();
    }
    getch();
    subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;
}

//Função que entrega vacinas aos países da Antártida
void entregaVacinaPaisAntartida(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    int i; //Variável para estrutura de repetição
    printf("Foram entregues %d vacinas no continente da Antártida !\n", pilhaCDAntartida.size());
    printf("Vacinas entregues. Segue abaixo informações das vacinas que foram entregues !\n");
    for(i=0;i<pilhaCDAntartida.size();i++){
        
        printf("Codigo: %d\nData de Fabricação: %d/%d/%d\nData de Validade: %d/%d/%d\nNome do Laboratório: %s\n#######################################################\n",pilhaCDAntartida.top().numero_vacina,pilhaCDAntartida.top().dia_fabricacao,pilhaCDAntartida.top().mes_fabricacao,pilhaCDAntartida.top().ano_fabricacao,pilhaCDAntartida.top().dia_validade,pilhaCDAntartida.top().mes_validade,pilhaCDAntartida.top().ano_validade,pilhaCDAntartida.top().nome_laboratorio);
        pilhaCDAntartida.pop();
    }
    getch();
    subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
    exit;
}

void pesquisaDataValidade(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica,int lab){
    int laboratorio = lab;
    int diaValidade;
    int mesValidade;
    int anoValidade;
    

    printf("Digite o dia da validade : ");
    scanf("%d",&diaValidade);

    printf("Digite o mês da validade : ");
    scanf("%d",&mesValidade);

    printf("Digite o ano da validade : ");
    scanf("%d",&anoValidade);
    
    
    if(laboratorio == 1){     
        //int i=0;
        list<vacina>::iterator it;
        printf("Busca:\t");
        for(it = listLabRitmo.begin(); it!=listLabRitmo.end();it++){
            if (diaValidade == it->dia_validade && mesValidade == it->mes_validade && anoValidade == it->ano_validade ){
                printf ("Código: %d\nData de Validade:%d/%d/%d\nData de Fabricação:%d/%d/%d\nNome Laboratório:%s\n##############################\n\n",it->numero_vacina,it->dia_validade,it->mes_validade,it->ano_validade,it->dia_fabricacao,it->mes_fabricacao,it->ano_fabricacao,it->nome_laboratorio);
            }
            //i++;
        }
        it--;
    }else if(laboratorio == 2){

        //int i=0;
        list<vacina>::iterator it;
        printf("Busca:\t");
        for(it = listLabEd.begin(); it!=listLabEd.end();it++){
            if (diaValidade == it->dia_validade && mesValidade == it->mes_validade && anoValidade == it->ano_validade ){
                printf ("Código: %d\nData de Validade:%d/%d/%d\nData de Fabricação:%d/%d/%d\nNome Laboratório:%s\n##############################\n\n",it->numero_vacina,it->dia_validade,it->mes_validade,it->ano_validade,it->dia_fabricacao,it->mes_fabricacao,it->ano_fabricacao,it->nome_laboratorio);
            }
            //i++;
        }
        it--;

    }else if(laboratorio == 3){

        //int i=0;
        list<vacina>::iterator it;
        printf("Busca:\t");
        for(it = listLabRaja.begin(); it!=listLabRaja.end();it++){
            if (diaValidade == it->dia_validade && mesValidade == it->mes_validade && anoValidade == it->ano_validade ){
                printf ("Código: %d\nData de Validade:%d/%d/%d\nData de Fabricação:%d/%d/%d\nNome Laboratório:%s\n##############################\n\n",it->numero_vacina,it->dia_validade,it->mes_validade,it->ano_validade,it->dia_fabricacao,it->mes_fabricacao,it->ano_fabricacao,it->nome_laboratorio);
            }
            //i++;
        }
        it--;

    }else if(laboratorio == 4){

        //int i=0;
        list<vacina>::iterator it;
        printf("Busca:\t");
        for(it = listLabComp.begin(); it!=listLabComp.end();it++){
            if (diaValidade == it->dia_validade && mesValidade == it->mes_validade && anoValidade == it->ano_validade ){
                printf ("Código: %d\nData de Validade:%d/%d/%d\nData de Fabricação:%d/%d/%d\nNome Laboratório:%s\n##############################\n\n",it->numero_vacina,it->dia_validade,it->mes_validade,it->ano_validade,it->dia_fabricacao,it->mes_fabricacao,it->ano_fabricacao,it->nome_laboratorio);
            }
            //i++;
        }
        it--;
    }
    getch();
    subMenuPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
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
            if(!pilhaLogisLabRitmo.empty() || !pilhaLogisLabEd.empty() || !pilhaLogisLabRaja.empty() || !pilhaLogisLabComp.empty()){
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
            if(!pilhaLogisLabRitmo.empty() || !pilhaLogisLabEd.empty() || !pilhaLogisLabRaja.empty() || !pilhaLogisLabComp.empty()){
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
            if(!pilhaLogisLabRitmo.empty() || !pilhaLogisLabEd.empty() || !pilhaLogisLabRaja.empty() || !pilhaLogisLabComp.empty()){
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
            if(!pilhaLogisLabRitmo.empty() || !pilhaLogisLabEd.empty() || !pilhaLogisLabRaja.empty() || !pilhaLogisLabComp.empty()){
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
            if(!pilhaLogisLabRitmo.empty() || !pilhaLogisLabEd.empty() || !pilhaLogisLabRaja.empty() || !pilhaLogisLabComp.empty()){
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
            if(!pilhaLogisLabRitmo.empty() || !pilhaLogisLabEd.empty() || !pilhaLogisLabRaja.empty() || !pilhaLogisLabComp.empty()){
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
            if(!pilhaLogisLabRitmo.empty() || !pilhaLogisLabEd.empty() || !pilhaLogisLabRaja.empty() || !pilhaLogisLabComp.empty()){
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
            if(!pilhaLogisLabRitmo.empty() || !pilhaLogisLabEd.empty() || !pilhaLogisLabRaja.empty() || !pilhaLogisLabComp.empty()){
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
	printf("Escolha o Centro de Distribuição");
	printf("\n1 - CD América do Norte\n2 - CD América do Sul\n3 - CD América Central\n4 - CD África\n5 - CD Ásia\n6 - CD Europa\n7 - CD Oceania\n8 - CD Antártida\n9 - Voltar");
	printf("\nEscolha uma opção : ");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
            system("cls");
            if(!pilhaCDAmericaNorte.empty()){
                entregaVacinaPaisAmericaNorte(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 2:
            system("cls");
            if(!pilhaCDAmericaSul.empty()){
                entregaVacinaPaisAmericaSul(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 3:
            system("cls");
            if(!pilhaCDAmericaCentral.empty()){
                entregaVacinaPaisAmericaCentral(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }
        
        case 4:
            system("cls");
            if(!pilhaCDAfrica.empty()){
                entregaVacinaPaisAfrica(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 5:
            system("cls");
            if(!pilhaCDAsia.empty()){
                entregaVacinaPaisAsia(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 6:
            system("cls");
            if(!pilhaCDEuropa.empty()){
                entregaVacinaPaisEuropa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 7:
            system("cls");
            if(!pilhaCDOceania.empty()){
                entregaVacinaPaisOceania(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 8:
            system("cls");
            if(!pilhaCDAntartida.empty()){
                entregaVacinaPaisAntartida(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
                break;
            }else{
                printf("Não existem pilhas da LOGIS cheias para sair para entrega !");
                getch();
                subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
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
            subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
	}
	
}

void subMenuPesquisa (list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica){
    int opcao;
	system("cls");
	printf("Escolha de qual laboratório deseja realizar a pesquisa : ");
	printf("\n1 - Lab-Ritmo\n2 - Lab-Ed\n3 - Lab-Raja\n4 - Lab-Comp\n5 - Voltar");
	printf("\nEscolha uma opção : ");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
            system("cls");
            if(!listLabRitmo.empty()){
                subMenuTipoPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida,1);
                break;
            }else{
                printf("Não existem registros na lista do Lab Ritmo !");
                getch();
                subMenuPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }
        case 2:
            system("cls");
            if(!listLabEd.empty()){
                subMenuTipoPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida,2);
                break;
            }else{
                printf("Não existem registros na lista do Lab ED !");
                getch();
                subMenuPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }
        
        case 3:
            system("cls");
            if(!listLabRaja.empty()){
                subMenuTipoPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida,3);
                break;
            }else{
                printf("Não existem registros na lista do Lab Raja !");
                getch();
                subMenuPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }

        case 4:
            system("cls");
            if(!listLabComp.empty()){
                subMenuTipoPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida,4);
                break;
            }else{
                printf("Não existem registros na lista do Lab Comp !");
                getch();
                subMenuPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        		break;
            }
        
        case 5:
        	system("cls");
        	menu(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        	break;
                    
        
        default:
            printf("Escolha uma opção válida \n");
            system("pause");
            system("cls");
            subMenuPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
	}
}

void subMenuTipoPesquisa (list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp,stack<vacina> pilhaLogisLabRitmo,stack<vacina> pilhaLogisLabEd,stack<vacina> pilhaLogisLabRaja,stack<vacina> pilhaLogisLabComp,stack<vacina> pilhaCDAmericaSul,stack<vacina> pilhaCDAmericaNorte,stack<vacina> pilhaCDAmericaCentral,stack<vacina> pilhaCDOceania,stack<vacina> pilhaCDAsia,stack<vacina> pilhaCDEuropa,stack<vacina> pilhaCDAntartida,stack<vacina> pilhaCDAfrica,int lab){
    int opcao;
    int laboratorio = lab;
	system("cls");
	printf("Escolha o tipo da pesquisa : ");
	printf("\n1 - Data Validade\n2 - Data Fabricação\n3 - Número da Vacina\n4 - Nome do Laboratóriop\n5 - Voltar");
	printf("\nEscolha uma opção : ");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
                system("cls");     
                pesquisaDataValidade(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida,lab);
                break;
           
        
        case 5:
        	system("cls");
        	subMenuPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        	break;
                    
        
        default:
            printf("Escolha uma opção válida \n");
            system("pause");
            system("cls");
            subMenuTipoPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida,lab);
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
            subMenuPesquisa(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
            break;
            
        case 3:
        	system("cls");
        	subMenuRetirar(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        	break;
        
        case 4:
        	system("cls");
        	subMenuEntrega(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
        	break;

        case 5:
        	system("cls");
        	subMenuEntregaPaises(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp,pilhaLogisLabRitmo,pilhaLogisLabEd,pilhaLogisLabRaja,pilhaLogisLabComp,pilhaCDAmericaSul,pilhaCDAmericaNorte,pilhaCDAmericaCentral,pilhaCDEuropa,pilhaCDAfrica,pilhaCDAsia,pilhaCDOceania,pilhaCDAntartida);
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