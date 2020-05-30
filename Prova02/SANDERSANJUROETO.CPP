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
#include<list>
#include<tr1/functional>
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

float calcula_hash_inteiro(int valor);
void FecharArquivo(FILE *arquivo);
FILE* AbreArquivo(char modo, char caminho[30]);
void menu(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp);
void subMenuProduzir(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp);
void produzVacinaLabRitmo(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp);
void produzVacinaLabEd(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp);
void produzVacinaLabRaja(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp);
void produzVacinaLabComp(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp);

//Função que produz vacinas para o LabRitmo
void produzVacinaLabRitmo(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){
    vacina vacinas_Struct;
    char laboratorio[40] = "LAB-ritmo";
    srand(1);
    printf("########## Lab-ritmo Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
  
    if(filaLabRitmo.size()<30000){
        for(int i=0;i<30000;i++){
            vacinas_Struct.numero_vacina = i;
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
        printf("\nVacinas produzidas pelo laboratório %s.\nTotal de vacinas produzidas foi de %d\n",laboratorio,filaLabRitmo.size());
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 3000 vacinas !");
    }
    getch();
    subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
    exit;
  
}
//Função que produz vacinas para o LabEd
void produzVacinaLabEd(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){
    vacina vacinas_Struct; //Struct do tipo vacina !
    char nomeLaboratorio[40] = "LABed"; //Variável com o nome do Laboratório
    srand(1);
    printf("########## LABed Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
  
    if(filaLabEd.size()<20000){
        for(int i=0;i<20000;i++){
            vacinas_Struct.numero_vacina = i;
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
        printf("\nVacinas produzidas pelo laboratório %s.\nTotal de vacinas produzidas foi de %d\n",nomeLaboratorio,filaLabEd.size());
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 20000 vacinas !");
    }
    getch();
    subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
    exit;
}
//Função que produz vacinas para o LabRaja
void produzVacinaLabRaja(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){
    vacina vacinas_Struct;
    char nomeLaboratorio[40] = "LABraja";
    srand(1);
    printf("########## LABraja Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
  
    if(filaLabRaja.size()<18000){
        for(int i=0;i<18000;i++){
            vacinas_Struct.numero_vacina = i;
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
        printf("\nVacinas produzidas pelo laboratório %s.\nTotal de vacinas produzidas foi de %d",nomeLaboratorio,filaLabRaja.size());
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 18000 vacinas !");
    }
 getch();
    subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
 exit;

}
//Função que produz vacinas para o LabComp
void produzVacinaLabComp(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){
      vacina vacinas_Struct;
      char nomeLaboratorio[40] = "LABcomp";
    srand(1);
    printf("########## LABcomp Laboratório ##########\n");
    printf("Produzindo Vacinas ...\n");
  
    if(filaLabComp.size()<15000){
        for(int i=0;i<15000;i++){
            vacinas_Struct.numero_vacina = i;
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
        printf("\nVacinas produzidas pelo laboratório %s.\nTotal de vacinas produzidas foi de %d",nomeLaboratorio,filaLabComp.size());
    }else{
        printf("Não é possível produzir mais vacinas, pois atingiu a capacidade maxima diária de 15000 vacinas !");
    }
    getch();
    subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
 exit;
}

//Função que gera o submenu para produção de vacinas
void subMenuProduzir(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){
    int opcao; //Variável para armazenar opção escolhida
  
    system("cls");
    printf("1 - LAB-ritmo\n2 - LABed\n3 - LABraja\n4 - LABcomp\n5 - Voltar ao Menu anterior");
    printf("\nEscolha uma opção : ");
    scanf("%d",&opcao);
    switch(opcao){
        case 1:
            system("cls");
            produzVacinaLabRitmo(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
            break;
        case 2:
            system("cls");
            produzVacinaLabEd(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
            break;
        case 3:
            system("cls");
            produzVacinaLabRaja(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
            break;
        case 4:
            system("cls");
            produzVacinaLabComp(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
            break;
      
        case 5:
            system("cls");
            menu(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
            break;
        default:
    printf("Escolha uma opção válida \n");
    system("pause");
    system("cls");
    subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
    }

}
//Função que gera o Menu
void menu(list <vacina> listLabRitmo,list <vacina> listLabEd,list <vacina> listLabRaja,list <vacina> listLabComp,queue <vacina> filaLabRitmo,queue <vacina> filaLabEd,queue <vacina> filaLabRaja,queue <vacina> filaLabComp){
    int opcao; //Variável para armazenar a opção escolhida
    system("cls");
    printf("1 - Produzir Vacinas\n2 - Listar Vacinas\n6 - Sair");
    printf("\nEscolha uma opção: ");
    scanf("%d",&opcao);
    switch(opcao){
        case 1:
            system("cls");
            subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
            break;
        case 2:
            system("cls");
            subMenuProduzir(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
            break;
       
        default:
        printf("Escolha uma opção válida \n");
        system("pause");
        system("cls");
        menu(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
   
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

float calcula_hash_inteiro(int valor){
    std::tr1::hash<float> hash_fn;
    size_t str_hash = hash_fn(valor);
    return(str_hash);
}

int main(){
    float HashDaSenha;
    int senha;
    FILE *arquivo;
    list <vacina> listLabRitmo;
    list <vacina> listLabEd;
    list <vacina> listLabRaja;
    list <vacina> listLabComp;
    queue <vacina> filaLabRitmo;
    queue <vacina> filaLabEd;
    queue <vacina> filaLabRaja;
    queue <vacina> filaLabComp;
  
 
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
   
    menu(listLabRitmo,listLabEd,listLabRaja,listLabComp,filaLabRitmo,filaLabEd,filaLabRaja,filaLabComp);
   
   
    system("pause");
}