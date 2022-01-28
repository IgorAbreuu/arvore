#include <stdio.h>
#include <stdlib.h>

struct No{
  int numero;
  struct No *esq;
  struct No *dir;
};
typedef struct No No;

struct Time{
  int numero_jogador;
  char nome_jogador;
  struct Time* dir;
  struct Time* esq;
};
typedef struct Time Time;

No* criar_time(){
  int numero_jogador;
  Time *jogadores = malloc(sizeof(Time));
  jogadores->numero_jogador= numero_jogador;
  jogadores->dir= NULL;
  jogadores->esq= NULL;
};

int time_vazio(No* raiz){ 
  return raiz == NULL;
}

int contador = 0; 
void inserir_jogador(No **raiz, int numero){
  if(*raiz == NULL){
    *raiz = (No*)malloc(sizeof(No)); 
    (*raiz)->esq = NULL; 
    (*raiz)->dir = NULL; 
    (*raiz)->numero = numero; 

  }else{
  	if(contador<11){
      No *jogadores = malloc(sizeof(No));
      if(numero < (*raiz)->numero){ 
      inserir_jogador(&(*raiz)->esq, numero); 
      }
      if(numero > (*raiz)->numero){ 
      inserir_jogador(&(*raiz)->dir, numero); 
      }
      (*raiz)->dir=jogadores; 
      contador= contador+1;
  }
    else{
      printf("\n\nTime completo!!\n\n");
    }
  }
}

void imprimir_em_ordem(No* raiz){ 
    if(raiz != NULL){
        imprimir_em_ordem(raiz->esq);
        printf("\n%d", raiz->numero);
        imprimir_em_ordem(raiz->dir);
    }
}

void imprimir_pos_ordem(No* raiz){
    if(raiz != NULL){
        imprimir_pos_ordem(raiz->esq);
        imprimir_pos_ordem(raiz->dir);
        printf("\n%d", raiz->numero);
    }
}

int busca(No* raiz, int numero) {
  if(time_vazio(raiz)) { 
    return 0;
  }
  
  return raiz->numero==numero || busca(raiz->esq, numero) || busca(raiz->dir, numero);
}

void remover(No **raiz, int numero){
    if(*raiz == NULL){  
       printf("*** Jogador inexistente! ***\n");
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
              (*raiz) = (*raiz)->esq;
              aux->esq = NULL;
              free(aux); 
					    aux = NULL;
            }else{   
              aux = (*raiz)->esq;  
              aux->esq = (*raiz)->esq;    
              aux->dir = (*raiz)->dir;                (*raiz)->esq = (*raiz)->dir = NULL;
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

int altura(No *pRaiz){
   if(pRaiz == NULL)
       return 0;
   else{
       int esq= altura(pRaiz->esq);
       int dir= altura(pRaiz->dir);
          if(esq<dir)
            return esq+1;
          else
            return dir+1;}
}

int main() {
  int valor, numero_jogador;
  No *time = criar_time();
   
  while( 1 ){ 
  int operacao;
  printf("\n");
  printf("=====================================\n");
  printf("               M E N U               \n");
  printf("=====================================\n");
  printf("[1] Inserir jogador no time.         \n");
  printf("[2] Verificar se o time está vazio   \n");
  printf("[3] Imprimir o time em pós-ordem.    \n");
  printf("[4] Imprimir o time em ordem.        \n");
  printf("[5] Buscar número do jogador.        \n");
  printf("[6] Remover jogador do time.         \n");
  printf("[7] Verificar a quantidade de nós.   \n");
  printf("[8] Verificar a altura da árvore.    \n");
  printf("[0] Cancelar operação.               \n");
  printf("=====================================\n");
  printf("\n");
 
  printf("Qual operação você deseja realizar?\t");
  scanf("%d", &operacao);

  switch (operacao){
    case 1: 
      printf("\nDigite o número do jogador:\t");
      scanf("%d",&numero_jogador);
      inserir_jogador(&time,numero_jogador);
      break;
    case 2: 
      if(time_vazio(time)){
        printf("\nO time está vazio!!\n");
      }else{
      printf("\nO time não está vazio!!\n");
      }
      break;
    case 3:
      imprimir_pos_ordem(time);
      break;
    case 4:
      imprimir_em_ordem(time);
      break;
    case 5:
      printf("\nDigite o jogador que você quer buscar:\t");
      scanf("%d",&valor);
      if(busca(time,valor)){
        printf("\nO jogador %d pertence ao time!\n", valor);
      }else{
        printf("\nO jogador %d não pertence ao time!\n", valor);
      }
      break;
    case 6:
      printf("\nDigite qual jogador você deseja remover:\t");
      scanf("%d",&valor);
      remover(&time,valor);
      break;
    case 7:
      printf("\nA quantidade de nós é: %d",contar_nos(time));
      break;
    case 8:
      printf("\nA altura da árvore é: %d",altura(time));
      break;
    case 0:
      free(time);
      exit(0);
    default: 
	    printf( "\n<ERR0R!!> \nOperação Inválida!!\n" );
    }
  }    
 
}
