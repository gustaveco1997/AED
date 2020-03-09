#include <stdio.h>
#include <stdlib.h>

float calcula(float *x){
    float resultado = 0;
    for(int i=0;i<4;i++){
        resultado = x[i].numero1 + resultado;
    }
    return resultado;
}

int main(){
    struct numeros {
        float numero1;
    };
    struct numeros n[4];
    

    for(int i=0;i<4;i++){
        printf("Digite um número : ");
        scanf("%f",&n[i].numero1);

    }
    printf("Resultado....: %1.2f", calcula(n));

    return 0;
}

