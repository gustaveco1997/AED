#include<iostream>
#include<tr1/functional>
#include<string.h>
#include<locale.h>
#include<conio.h>

//Função para calcular hash de numeros inteiros

float calcula_hash_inteiro(int valor){
    std::tr1::hash<float> hash_fn; //Definição do tipo de dados hash chamado hash_fn
    size_t str_hash = hash_fn(valor); //Faz o cálculo do hash
    return(str_hash); //Retorna Hash
}

int main(){
    float HashDaSenha = 3804853940604895232;
    int i;

    setlocale (LC_ALL, "Portuguese");
    float hash;

    for(i=0;i<99999;i++){
        if(hash == HashDaSenha){
            printf("A senha descoberta é : %d",i);
            break;
        }
    }
}