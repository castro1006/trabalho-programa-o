#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define TAMANHO 200

typedef struct
{
    int nif;
    char codigo[50];
    int tempo;
    int distancia;
    int nrOrdem;
}Utilizador;

typedef struct
{
    float precoTot;
    char tipo[50];
    int disponivel;
    int autonomia;
    char codigo[50];
}Mobilidade;

int menu(); // onde vou criar o menu para o Utilizador
int inserirMobilidade(Mobilidade M[TAMANHO], int qt, char cod[50], char tp[50], int autonom, float pr); // inserir a Mobilidade
int entregarMobilidade(Utilizador U[TAMANHO], Mobilidade M[TAMANHO], int contNOrdem, int nOrd, int qt);
void listarMobilidade(Mobilidade M[TAMANHO], int qt);
int removerMobilidade(Mobilidade M[TAMANHO], int qt, char cod[50]);
int pedidoutilizador(Mobilidade M[TAMANHO], Utilizador U[TAMANHO], int nOrdem, int num, char cod[50], int temp, int dist, int qt);
int removerpedidos(Mobilidade M[TAMANHO],Utilizador U[TAMANHO], int qt, int contNOrdem, int nOrdem);
void listarpedidos(Utilizador U[TAMANHO], int nOrdem);
int calcularpreco(Utilizador U[TAMANHO], Mobilidade M[TAMANHO], int qt, int contNOrdem, int nOrd);
int verMovimentos (Utilizador U[TAMANHO], Mobilidade M[TAMANHO], char cod[50], int contNOrdem, int qt);
int verificardisponivel(Mobilidade M[TAMANHO], char cod[50], int qt);
int verificarcod(Mobilidade M[TAMANHO], char cod[50], int qt);
int verificardistancia(Mobilidade M[TAMANHO], char cod[50], int qt, int dist);
void guardarFichMobilidade(Mobilidade M[TAMANHO], int qt);
int lerFichMobilidade(Mobilidade M[TAMANHO]);
void guardarFichUtilizador(Utilizador U[TAMANHO], int nOrdem);
int lerFichUtilizador(Utilizador U[TAMANHO]);


int menu()
{
    int opcao;

    do
    {
        printf(" M E N U \n");
        printf("1- Inserir Mobilidade\n");
        printf("2- Entregar Mobilidade\n"); 
        printf("3- Listar Mobilidade\n");
        printf("4- Remover Mobilidade\n");
        printf("5- Pedido de Utilizador\n");
        printf("6- Remover pedido de Utilizador\n");
        printf("7- Listar pedidos do Utilizador\n");
        printf("8- Calcular preco total do pedido\n");
        printf("9- Ver Movimentos\n");
        printf("10-Guardar\n");
        printf("11-Ler\n");
        printf("0- Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
    }
    while ((opcao>12)||(opcao<0));  

    return (opcao);
}
