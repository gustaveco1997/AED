#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
FILE *AbreArquivo(char modo, char caminho[30])
{
    FILE *arquivo;
    switch (modo)
    {
    case 'g':
        arquivo = fopen(caminho, "wt");
        break;
    case 'l':
        arquivo = fopen(caminho, "rt");
        break;
    case 'a':
        arquivo = fopen(caminho, "a");
        break;
    }
    if (arquivo == NULL)
    { //Se houver algum erro, o ponteiro apontará para NULL
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}
void FecharArquivo(FILE *arquivo)
{
    fclose(arquivo);
}
void Cadastra(char nome[30], int telefone)
{
    FILE *arquivo;
    arquivo = AbreArquivo('a', "agenda.txt");
    fprintf(arquivo, "%s %d\n", nome, telefone);
    FecharArquivo(arquivo);
}
void Listar()
{
    FILE *arquivo;
    char nome[30];
    int telefone;
    arquivo = AbreArquivo('l', "agenda.txt");

    //feof -> Verifica se é o fim do arquivo
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%s %d ", &nome, &telefone); // Le do arquivo
        printf("Nome: %s  -  Telefone: %d\n", nome, telefone);
    }
    FecharArquivo(arquivo);
}
void pesquisa(char *nomePesquisa)
{

    FILE *arquivo;
    char nome[30];
    char nomeTeste[30];
    int telefone;
    int verify;

    arquivo = AbreArquivo('l', "agenda.txt");

    //feof -> Verifica se é o fim do arquivo
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%s %d ", &nome, &telefone); // Le do arquivo

        if (strcmp(nomePesquisa, nome) == 1)
        {
            verify = 1;
            printf("Contato encontrado com sucesso!\nNome: %s  -  Telefone: %d\n", nome, telefone);

            break;
        }
        else
        {
            verify = 0;
        }
    }
    if (verify == 0)
    {
        printf("Contato não encontrado");
    }

    FecharArquivo(arquivo);
}
void pesquisaTelefone(int telefonePesquisa)
{
    FILE *arquivo;
    char nome[30];
    int telefone;
    int verify;
    arquivo = AbreArquivo('l', "agenda.txt");

    while (!feof(arquivo))
    {
        fscanf(arquivo, "%s %d ", &nome, &telefone); // Le do arquivo

        if (telefone == telefonePesquisa)
        {
            verify = 1;
            printf("Contato encontrado com sucesso!\nNome: %s  -  Telefone: %d", nome, telefone);
            break;
        }
        else
        {
            verify = 0;
        }
    }
    if (verify == 0)
    {
        printf("Contato não encontrado");
    }

    FecharArquivo(arquivo);
}
void subMenu()
{
    int opcao;
    char nomePesquisa[30];
    int telefonePesquisa;

    printf("1 - Pesquisar por Nome\n2 - Pesquisar por Telefone");

    printf("\nDigite uma opcao: ");
    scanf("%d", &opcao);
    system("cls");

    switch (opcao)
    {
    case 1:
        printf("Digite o nome : ");
        fflush(stdin);
        fgets(nomePesquisa, 30, stdin);
        pesquisa(nomePesquisa);
        system("pause");
        break;
    case 2:
        printf("\nDigite o telefone: ");
        scanf("%d", &telefonePesquisa);
        pesquisaTelefone(telefonePesquisa);
        system("pause");
        break;
    default:
        printf("\n\nOpcao invalida! Tente Novamente!\n\n");
        system("pause");
    }
}

int main()
{
    int opcao;
    char nome[30];
    int telefone;
    do
    {
        system("cls");
        printf("\n\n\t\tBem Vindo ao programa AGENDA\n");
        printf("\nMENU");
        printf("\n 1 - Cadastrar Nome e telefone");
        printf("\n 2 - Listar todos os Nomes e telefones");
        printf("\n 3 - Pesquisar Nome");
        printf("\n 4 - Sair");
        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);
        system("cls");
        switch (opcao)
        {
        case 1:
            printf("\nDigite o nome: ");
            setbuf(stdin, NULL); //buffer está limpo para receber uma nova entrada de dados
            gets(nome);
            printf("\nDigite o telefone: ");
            scanf("%d", &telefone);
            Cadastra(nome, telefone);
            system("pause");
            break;
        case 2:
            Listar();
            system("pause");
            break;
        case 3:

            subMenu();
            system("pause");
            break;
        case 4:
            printf("\n\nFinalizando...\n\n");
            system("pause");
            exit(0);
            break;

        default:
            printf("\n\nOpcao invalida! Tente Novamente!\n\n");
            system("pause");
        }
    } while (opcao != 3);
    return 0;
}
