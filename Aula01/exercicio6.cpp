#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

 struct numeros {
        float numero1;
    };

float calcula(){
    struct numeros  n[4] ;
    float resultado =0;
    for(int i=0;i<4;i++){
        printf("Digite um número : ");
        scanf("%f",&n[i].numero1);

        resultado = n[i].numero1 + resultado;
    }
    return resultado;
}


int main(){

    printf("Resultado....: %1.2f", calcula());

    return 0;
}

