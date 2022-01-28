#include <stdio.h>
#include <stdlib.h>
struct No{
  int numero;
  struct No *esq;
  struct No *dir;
};
typedef struct No No;

struct Nume{
  int numero;
  struct Num* dir;
  struct Num* esq;
};
typedef struct Nume Nume;

No* criar_arvore(){
  int numero;
  Nume *num = malloc(sizeof(Nume));
  num->numero = numero;
  num->dir= NULL;
  num->esq= NULL;
};

int arvore_vazia(No* raiz){ 
  return raiz == NULL;
}

void inserir(No **pRaiz, int numero){
	if (*pRaiz == NULL){
	  *pRaiz=(No*)malloc(sizeof (No));
	  (*pRaiz)->esq=NULL;
	  (*pRaiz)->dir=NULL;
	  (*pRaiz)->numero=numero;
	}else{
		if (numero < ((*pRaiz)->numero)){
		  inserir(&((*pRaiz)->esq), numero);
		}else{
      inserir(&((*pRaiz)->dir), numero);
		}
	}
}

void remover(No **raiz, int numero){
    if(*raiz == NULL){  
       printf("*** Árvore vazia! ***\n");
    }
    if(numero < (*raiz)->numero){
    	remover(&(*raiz)->esq,numero);
	}else{
      if(numero > (*raiz)->numero){
        remover(&(*raiz)->dir,numero);
		  }else{   
        No *aux = *raiz;
			  if (((*raiz)->esq == NULL) && ((*raiz)->dir == NULL)){
          free(aux);
          (*raiz) = NULL; 
        }else{    
          if ((*raiz)->esq == NULL){ 
          (*raiz) = (*raiz)->dir;
          aux->dir = NULL;
          free(aux);
				  aux = NULL;
          }else{           
           if((*raiz)->dir == NULL){ 
             (*raiz) = (*raiz)->esq;              aux->esq = NULL;
             free(aux); 
					   aux = NULL;
             }else{   
              aux = (*raiz)->esq;  
              aux->esq = (*raiz)->esq;    
              aux->dir = (*raiz)->dir;
              (*raiz)->esq = (*raiz)->dir = NULL;
              free((*raiz));  
				      *raiz = aux;  
				      aux = NULL;   
             }
           }
         }
      }
   }
}

int contar_nos(No *pRaiz){
   if(pRaiz == NULL)
    return 0;
   else
    return 1 + contar_nos(pRaiz->esq) + contar_nos(pRaiz->dir);
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}
int altura(No *pRaiz){
  if((pRaiz == NULL) || (pRaiz->esq == NULL && pRaiz->dir == NULL))
    return 0;
  else
    return 1 + maior(altura(pRaiz->esq), altura(pRaiz->dir));
}

int main() {
  int numero,valor;
  No *num = criar_arvore();
  while( 1 ){ 
  int operacao;
  printf("\n");
  printf("=====================================\n");
  printf("               M E N U               \n");
  printf("=====================================\n");
  printf("[1] Inserir na árvore.               \n");
  printf("[2] Listar a árvore.                 \n");
  printf("[3] Remover da árvore.               \n");
  printf("[4] Contar número de nós da árvore.  \n");
  printf("[5] Calcular altura da árvore.       \n");
  printf("[6] Achar maior valor da árvore.     \n");
  printf("[0] Cancelar operação.               \n");
  printf("=====================================\n");
  printf("\n");

  printf("Qual operação você deseja realizar?\t");
  scanf("%d", &operacao);

  switch (operacao){
    case 1: 
      printf("\nDigite o número que você deseja inserir na árvore:\t");
      scanf("%d",&numero);
      inserir(&num,numero);
      break;
    case 2: 
      if(arvore_vazia(num)){
        printf("\nA árvore está vazia!!\n");
      }else{
      printf("\nA árvore não está vazia!!\n");
      }
      break;
    case 3:
      printf("\nDigite qual número você deseja remover da árvore:\t");
      scanf("%d",&valor);
      remover(&num,valor);
      break;
    case 4:
      printf("\nA quantidade de nós é: %d",contar_nos(num));
      break;
    case 5:
      printf("\nA altura da árvore é: %d",altura(num));
      break;
    case 6:
      printf("O maior valor é: %d",altura(num));
    case 0:
      free(num);
      exit(0);
    default: 
	    printf( "\n<ERR0R!!> \nOperação Inválida!!\n" );
    }
  }    
}
