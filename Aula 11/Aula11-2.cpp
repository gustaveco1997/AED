#include<iostream>
#include<tr1/functional>
#include<string.h>
#include<locale.h>
#include<conio.h>

float calcula_hash_inteiro(int valor){
    std::tr1::hash<float> hash_fn;
    size_t str_hash = hash_fn(valor);
    return(str_hash);
}

int main(){
    float HashDaSenha = 10608169548643303424;
    int senha;

    setlocale (LC_ALL, "Portuguese");
    float hash;

    do{
        system("cls");
        printf("\nDigite a senha : ");
        scanf("%d",&senha);
        hash = calcula_hash_inteiro(senha);
    }while(hash != HashDaSenha);

    printf("!!Usuário Autenticado!!");
}