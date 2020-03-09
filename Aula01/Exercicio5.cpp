#include <stdlib.h>
#include<conio.h>

int main(){
    struct ficha_de_aluno{
        char nome[40];
        char disciplina[40];
        float nota_prova1;
        float nota_prova2;
    };
    struct ficha_de_aluno aluno[10];

    printf("\n--------Cadastro de Aluno-------");
    for(int i=0;i<10;i++){


        printf("Nome do aluno: ");
        fflush(stdin);
        fgets(aluno[i].nome, 40, stdin);

        printf("Disciplina....: ");
        fflush(stdin);
        fgets(aluno[i].displina, 40, stdin);

        printf("Informe a 1a. nota ..: ");
        scanf("%f", &aluno[i].nota_prova1);

        printf("informe a 2a. nota ..: ");  
        scanf("%f", &aluno[i].nota_prova2);
    }

    for(int i=0;i<10;i++){
        printf("\n\n------Lendo os dados da struct-------");
        printf("Nome.......: %s", aluno[i].nome);
        printf("Discplina....: %s", aluno[i].discplina);
        printf("Nota da prova 1....: %f", aluno[i].nota_prova1);
        printf("Nota da prova 2....: %f", aluno[i].nota_prova2);

    }



    getch();
    return(0);


}