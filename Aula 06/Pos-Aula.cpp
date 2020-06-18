
/*Fazer um algoritmo que implemente uma estrutura de dados do tipo PILHA.
Essa estrutura deverá armazenar valores do tipo inteiro.

O programa deverá:

01 - Armazenar na pilha 100 valores inteiros, sendo preenchidos automaticamente
utilizando a função rand(); O exemplo abaixo demonstra como utilizar o rand().
--------
numero = rand() % 100 + 1; // variável numero recebera valor entre 1 e 100.
--------

02 - Fazer uma função que imprima a pilha;

03 - Fazer uma função que percorra a pilha a procura de um determinado valor
. Esse valor procurado deverá ser informado pelo usuário.
Quando encontrado, remover / pop() os itens acima até que esse valor esteja
no topo da pilha.

04 - Fazer uma função que some os valores armazenados em toda a pilha.
*/
#include<stack>
#include<iostream>

using namespace std;
void pesquisa(stack<int> pilha){
    int numero_pesquisa;

    printf("Digite o nmero a ser pesquisado : ");
    scanf("%d",&numero_pesquisa);
    while(!pilha.empty()){
        if(pilha.top() != numero_pesquisa){
            pilha.pop();
        }else{
            printf("Número %d encontrado\n",numero_pesquisa);
            printf("O novo tamanho da pilha é de : %d",pilha.size());
            break;
        }
    }
}
void soma (stack<int> pilha){
    int soma = 0;
    while(!pilha.empty()){
        soma = soma+pilha.top();
        pilha.pop();
    }
    printf("A soma da pilha é : %d", soma);
}
void imprime_pilha(stack<int> pilha){
    printf("\nPilha:\n");
    while(!pilha.empty()){
        printf("%d \n",pilha.top());

        pilha.pop();
    }
    printf("\n");
}
int main(){
     stack<int> pilha;
     int numero;
     for(int i=0;i<100;i++){
        numero = rand() % 100 + 1;
        pilha.push(numero);
     }
     imprime_pilha(pilha);
     pesquisa(pilha);
     soma(pilha);

}
