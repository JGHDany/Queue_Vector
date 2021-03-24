/*
		FILA SEQUENCIAL
	Definição da Estrutura de Dados:
	Para permitir a reutilização das posições já ocupadas, usa-se o conceito de "Fila Circular".
	Precisamos de um novo componente para indicar quantos elementos existem na fila, no momento.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 		/* tamanho máximo da fila */

typedef int telem; 	/* tipo base dos elementos da fila */

typedef struct{
	telem v[MAX];
	int inicio; 	/* posição do primeiro elemento */
	int final; 		/* posição do último elemento */
	int tam; 		/* número de elementos da fila */
} tfila;

//1. Criar - cria uma fila vazia
void criar (tfila *F);

//2. Vazia - testa se uma fila está vazia
int vazia (tfila F);

//3. Primeiro - obtém o elemento do início da fila
int primeiro (tfila F, telem *dado);

//5. Insere - insere um elemento no fim de uma fila
int inserir (tfila *F, telem valor);

//6. Remove - remove o elemento do início de uma fila, retornando o elemento removido
int remover (tfila *F, telem *valor);

//7. Esvaziar - remove todos os elementos da fila.
int esvaziarFila(tfila *F);

//8. ImprimirFila - imprime todos os elementos da fila.
void imprimirFila(tfila F);

int main()
{
    tfila f;
	telem valor;
	criar(&f);

	int opcao;

   do{

		printf("\n\n\n\t EDITOR DE FILA SEQUENCIAL\n");
		printf("\n\t 1 - INSERIR   				   ");
		printf("\n\t 2 - REMOVER   				   ");
		printf("\n\t 3 - EXIBIR PRIMEIRO ELEMENTO  ");
		printf("\n\t 4 - EXIBIR A FILA    		   ");
		printf("\n\t 5 - ESVAZIAR A FILA   		   ");
		printf("\n\t 6 - SAIR           		   ");

		printf("\n\n\t  DIGITE SUA OPÇÃO: ");
		scanf("%d",&opcao);
		system("CLS");
		switch(opcao){

			case 1: {
				printf("\n\t EMFILA um elemento:");
				scanf("%d",&valor);
				if(inserir(&f, valor)>0){
					printf("\n\tOK <- inserir (&fila, %d)",valor);
				}
			}break;

			case 2: {
				telem valor;
				if(remover(&f, &valor)>0)
					printf("\n\tOK <- remover(&fila, %d)", valor);
			}break;

			case 3:{
				telem dado;
				if(primeiro (f, &dado)>0)
					printf("\n\t OK <- O primeiro(fila, => [%d])", dado);
			}break;
			case 4:{
					if(!vazia(f))
						printf("\n\tFILA :");
					imprimirFila(f);
			}break;
			case 5:{
				if(esvaziarFila(&f)>0){
					printf("\n\t OK <- Fila Esvaziada!");
				}
			}break;
		}
	}while(opcao!=6);

    return 0;
}
//OPERAÇÕES COM FILAS:

//1. Criar - cria uma fila vazia
void criar (tfila *F)
{
	F->inicio = 0;
	F->final = -1;
	F->tam = 0;
}

//2. Vazia - testa se uma fila está vazia
int vazia (tfila F)
{
	return (F.tam == 0);
}

//3. Primeiro - obtém o elemento do início da fila
int primeiro (tfila F, telem *dado)
{
	if (vazia(F)){
		printf("\n\tFila Vazia!");
		return 0; /* Erro: fila vazia */
	}
	*dado = F.v[F.inicio];
	return (1);
}

//5. Insere - insere um elemento no fim de uma fila
int inserir (tfila *F, telem valor)
{
	if(F->tam == MAX){
		printf("ERRO: tam == MAX");
		 return 0;
	}
	(F->tam)++;
	F->final = (F->final + 1) % MAX;
	F->v[F->final] = valor;
	return(1);
}

//6. Remove - remove o elemento do início de uma fila, retornando o elemento removido
int remover (tfila *F, telem *valor)
{
	if (vazia(*F)) { /* Erro: fila vazia */
		printf("\n\tFila Vazia");
		return 0;
	}
	primeiro(*F,valor);
	(F->tam)--;
	F->inicio = (F->inicio + 1) % MAX;
	return(1);
}

//7. Esvaziar - remove todos os elementos da fila.
int esvaziarFila(tfila *F){

	if(vazia(*F)) { /* Erro: fila vazia */
		printf("\n\tFila Vazia");
		return 0;
	}
	criar(F);//inicializa todas as variaveis
	return 1;
}

//8. ImprimirFila - imprime todos os elementos da fila sem alterar a fila
void imprimirFila(tfila F){
	int i;
	if (vazia(F)){ /* Erro: fila vazia */
		printf("\n\tFila Vazia");
		return ;
	}
	else{
		telem dado;
		printf("%d",F.v[F.inicio]); //imprime o primeiro elemento
		for(i = F.inicio+1; i <= F.final; printf(" <- %d", F.v[i++]));//printf(" <- %d", F.v[i] );
	}
}
