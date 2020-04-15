#include<iostream>
#include<queue>
#include<locale.h>

using namespace std;

//Impressão da fila
void imprime(queue <int> fila){
    queue <int> fila_temp;
    fila_temp = fila;
    printf("Impressão da fila:");
    printf("\nINÍCIO: -->");
    while(!fila_temp.empty()){
        printf("%d -", fila_temp.front());
        fila_temp.pop();
    }
    printf("<-- FIM\n");
}

//Informações da fila
void informacoes(queue <int> fila){
    printf("Informações da fila:\n");
    printf("O tamanho da fila é %d \n", fila.size());
    printf("O primeiro elemento da fila é %d \n", fila.front());
    printf("O último elemento da fila é %d \n", fila.back());
    printf("\n\n");
}

//Função que busca o elemento na fila
void buscaElemento(queue <int> fila){
    queue <int> fila_temp;
    int elemento;
    fila_temp = fila;
    printf("Digite um elemnto à ser buscado na fila : ");
    scanf("%d",&elemento);

    while(!fila.empty()){
        if(fila_temp.front()==elemento){
            printf("Elemento %d encontrado ! ",elemento);
            break;

        }else{
            fila_temp.pop();

        }

    }
    printf("Elemento %d não foi encontrado ! ",elemento);
}

int main(){
    queue <int> fila;
    setlocale(LC_ALL, "Portuguese");

    for(int i=0;i<10;i++){
        fila.push(i);
    }

    informacoes(fila);
    buscaElemento(fila);
    imprime(fila);

    printf("Retirando elemento da fila. pop()\n");

    fila.pop();
    imprime(fila);


    printf("Adicionando elemento 50 na fila. push()\n");

    fila.push(50);

    imprime(fila);

    return 0;

}




