#include<iostream>
#include<tr1/functional>
#include<string.h>
#include<locale.h>
#include<conio.h>


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


    setlocale (LC_ALL, "Portuguese");
    float hash;

    arquivo = AbreArquivo('l', "password.txt");
    fscanf(arquivo, "%f ", &HashDaSenha); // Ler hash do arquivo e guardar na variável

    do{
        system("cls");
        printf("\nDigite a senha : ");
        scanf("%d",&senha);
        hash = calcula_hash_inteiro(senha);
    }while(hash != HashDaSenha);

    printf("!!Usuário Autenticado!!");
    FecharArquivo(arquivo);
}