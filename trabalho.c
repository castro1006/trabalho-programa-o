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

int menu(); 
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



int inserirMobilidade(Mobilidade M[TAMANHO], int qt, char cod[50], char tp[50], int autonom, float pr)
{
    if(qt<TAMANHO){
        strcpy(M[qt].codigo,cod);
        strcpy(M[qt].tipo,tp);
        M[qt].autonomia = autonom;
        M[qt].precoTot = pr;
        M[qt].disponivel = 1;
        return(1);
    }

    return (0);
}

int entregarMobilidade(Utilizador U[TAMANHO], Mobilidade M[TAMANHO], int contNOrdem, int nOrd, int qt)
{
    int i,a;

    for(i = 0; i < contNOrdem; i++){
        if(nOrd == U[i].nrOrdem && strcmp(M[i].codigo,U[i].codigo)==0){

            if(M[i].disponivel == 1){
                printf("Esta Mobilidade nao esta em uso\n");
              return(0);            
            }

            else{
            for (a = 0; a < qt; a++){
                if (strcmp(M[a].codigo,U[i].codigo)==0){
                    M[a].disponivel=1;
                    M[a].autonomia = M[a].autonomia - U[i].distancia;
                    printf("disponivel: %d\n", M[a].disponivel);
                    return(1);
                    }
                }
            }
        
    }
    }
    printf("Esse Mobilidade nao foi pedida\n");

   return(0);
}

void listarMobilidade(Mobilidade M[TAMANHO], int qt)
{
    int i;

    for( i = 0; i < qt; i++)
    {
        printf("----------------\n");
        printf("Codigo: %s\n",M[i].codigo);
        printf("Tipo: %s\n",M[i].tipo);
        printf("Autonomia: %d\n",M[i].autonomia);
        printf("precoTot: %.2f\n",M[i].precoTot);
        printf("disponivel: %d\n", M[i].disponivel);
        printf("----------------\n");
    }
}

int removerMobilidade(Mobilidade M[TAMANHO], int qt, char cod[50]) 
{
    int i;

    for( i = 0; i < qt; i++){
    if(strcmp(M[i].codigo,cod)==0){

            if(i == qt-1) 
                return (1);
            else{ 
                strcpy(M[i].codigo,M[qt-1].codigo);
                strcpy(M[i].tipo,M[qt-1].tipo);
                M[i].autonomia = M[qt-1].autonomia;
                M[i].precoTot = M[qt-1].precoTot;
                M[i].disponivel = M[qt-1].disponivel;
                return(1);
            }
        }
    }

    return (0);
}

int pedidoutilizador(Mobilidade M[TAMANHO], Utilizador U[TAMANHO], int contNOrdem, int num, char cod[50], int temp, int dist, int qt)
{
    int i;

    for(i = 0; i < qt; i++){
    if(contNOrdem<TAMANHO && strcmp(M[i].codigo,cod)==0)
        {
            strcpy(U[contNOrdem].codigo,cod);
            U[contNOrdem].nif = num;
            U[contNOrdem].tempo = temp;
            U[contNOrdem].distancia = dist;
            U[contNOrdem].nrOrdem=contNOrdem+1;
            M[i].disponivel = 0;
            M[i].autonomia=M[i].autonomia - dist;
            return (1);
        }
    }

    return (0);
}

int removerpedidos(Mobilidade M[TAMANHO],Utilizador U[TAMANHO], int qt, int contNOrdem, int nOrdem)
{
  int i, a;

  for( i = 0; i < contNOrdem; i++){

  if(nOrdem == U[i].nrOrdem){

      for(a = 0; a < qt; a++){
      if(strcmp(M[a].codigo, U[i].codigo) == 0) {
            M[a].disponivel = 1;
            break;
        }
      }

      if(i == contNOrdem-1)
        return (1);
      else{
        strcpy(U[i].codigo,U[contNOrdem-1].codigo);
        U[i].nif = U[contNOrdem-1].nif;
        U[i].tempo = U[contNOrdem-1].tempo;
        U[i].distancia = U[contNOrdem-1].distancia;

        return(1);
      }
    }
  }
  return (0);
}

void listarpedidos(Utilizador U[TAMANHO], int nOrdem)
{
  int i;
  for( i = 0; i < nOrdem; i++)
  {
      printf("//////////////\n");
      printf("Numero de Pedido: %d\n", U[i].nrOrdem);
      printf("NIF: %d\n", U[i].nif);
      printf("Codigo: %s\n", U[i].codigo);
      printf("Tempo: %d\n", U[i].tempo);
      printf("Distancia: %d\n", U[i].distancia);
      printf("//////////////\n");
  }
}

int calcularpreco(Utilizador U[TAMANHO], Mobilidade M[TAMANHO], int qt, int contNOrdem, int nOrd)
{
    int i, a;
    float preco;

    for(i = 0; i < contNOrdem; i++){
    if(nOrd == U[i].nrOrdem){

            for(a = 0; a < qt; i++){
            if(strcmp(M[i].codigo,U[i].codigo)==0){
                    preco= U[i].tempo * M[a].precoTot;

                    printf("Total a pagar : %d * %.2f = %.2f euros\n", U[i].tempo, M[a].precoTot, preco);
                    return(1);
                }
            }
        }
    }

    return 0;
}

int verMovimentos (Utilizador U[TAMANHO], Mobilidade M[TAMANHO], char cod[50], int contNOrdem, int qt)
{

    int i,a;

    for(i = 0; i < contNOrdem; i++){
    if(strcmp(U[i].codigo,cod)==0){

           
            for(a = 0; a < qt; i++){
            if(strcmp(M[a].codigo,cod)==0){
                      printf("//////////////\n");
                      printf("Numero de Ordem: %d\n", U[i].nrOrdem);
                      printf("NIF: %d\n", U[i].nif);
                      printf("Codigo: %s\n", U[i].codigo);
                      printf("Tempo Previsto: %d\n", U[i].tempo);
                      printf("Distancia: %d\n", U[i].distancia);
                      printf("Autonomia que resta: %d\n", M[a].autonomia);
                      printf("//////////////\n");
                      break;
                }
            }
        }
    }

    return 0;
}


int verificarcod(Mobilidade M[TAMANHO], char cod[50], int qt)
{
  int i;
  for( i = 0; i < qt; i++){
    if(strcmp(M[i].codigo,cod)==0)
      return(1);
  }
if (strcmp(M[i].codigo,cod)==0 && M[i].autonomia==0)
{
    printf("A mobilidade nao tem mais energia\n");
    return(-1);
}
  printf("nao existe esse codigo\n");
  return (0);
}

int verificardisponivel(Mobilidade M[TAMANHO], char cod[50], int qt)
{
  
  int a;

  for(a = 0; a < qt; a++){
    if(strcmp(M[a].codigo,cod)==0 && M[a].disponivel==1)
        return (1);
  }

  printf("No momento nao pode ser usada\n");

  return(0);
}

int verificardistancia(Mobilidade M[TAMANHO], char cod[50], int qt, int dist)
{
  int i;
  for( i = 0; i < qt; i++){
    if(strcmp(M[i].codigo,cod)==0 && M[i].autonomia>=dist)
      return(1);

  }
  printf("Escolha uma distancia mais pequena\n");

  return(0);
}


void guardarFichMobilidade(Mobilidade M[TAMANHO], int qt)
{FILE * fp;
 int i=0;
 fp = fopen("dadosMobilidade.txt", "wt");  // "wt" write text
                                 // "rt" read text
				 // "at" append
 while(i<qt)
 {fprintf(fp, "%s;%s;%d;%f;%d\n", M[i].codigo, M[i].tipo, M[i].autonomia, M[i].precoTot, M[i].disponivel);
  i++;
 }
 fclose(fp);
}

int lerFichMobilidade(Mobilidade M[TAMANHO])
{FILE  * fp;
 int qt = 0;
 fp = fopen("dadosMobilidade.txt","rt");
 while(!feof(fp)) // negação do resultado devolvido pela função feof
 {fscanf(fp,"%s\n;%s\n;%d\n;%.2f\n;%d\n",M[qt].codigo,
	                    M[qt].tipo,
			    &M[qt].autonomia,
			    &M[qt].precoTot,
              &M[qt].disponivel
        );
  qt++;
 }
 fclose(fp);
 return(qt);
}



void guardarFichUtilizador(Utilizador U[TAMANHO], int nOrdem)
{FILE * fp;
 int i=0;
 fp = fopen("dadosMobilidade.txt", "wt");  // "wt" write text
                                 // "rt" read text
				 // "at" append
 while(i<nOrdem)
 {fprintf(fp, "%s;%d;%d;%d;%d\n", U[i].codigo, U[i].tempo, U[i].distancia, U[i].nrOrdem, U[i].nif);
  i++;
 }
 fclose(fp);
}

int lerFichUtilizador(Utilizador U[TAMANHO])
{FILE  * fp;
 int no = 0;
 fp = fopen("dadosMobilidade.txt","rt");
 while(!feof(fp)) // negação do resultado devolvido pela função feof
 {fscanf(fp,"%s\n;%d\n;%d\n;%.d\n;%d\n",U[no].codigo,
	                    &U[no].tempo,
			    &U[no].distancia,
			    &U[no].nrOrdem,
              &U[no].nif
        );
  no++;
 }
 fclose(fp);
 return(no);
}