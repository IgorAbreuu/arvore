#include <stdio.h>
#include <stdlib.h>

struct arvore {
	int valor;
	struct arvore *dir;
	struct arvore *esq;
};
typedef struct arvore Arvore;

void mostrar_arvore(Arvore *sub_arvores) {
	if(sub_arvores == NULL) {
		return;
	}
	printf("%d\t", sub_arvores->valor);
	mostrar_arvore(sub_arvores->esq);
	mostrar_arvore(sub_arvores->dir);
}
Arvore *criar(int valor) {
	Arvore *sub_arvores = malloc(sizeof(Arvore));
	sub_arvores->valor = valor;
	sub_arvores->dir = NULL;
	sub_arvores->esq = NULL;	
	return sub_arvores;
}
int main() {
	Arvore *raiz = criar(19);
	Arvore *sub_arv_1 = criar(23);
	Arvore *sub_arv_2 = criar(11);
	Arvore *sub_arv_3 = criar(99);
	Arvore *sub_arv_4 = criar(3);
	Arvore *sub_arv_5 = criar(89);
	Arvore *sub_arv_6 = criar(76);
	Arvore *sub_arv_7 = criar(41);
	Arvore *sub_arv_8 = criar(54);
	raiz->esq = sub_arv_1;
	sub_arv_1->esq = sub_arv_2;
	sub_arv_2->esq = sub_arv_3;
	sub_arv_6->esq = sub_arv_8;	
	raiz->dir = sub_arv_6;
	sub_arv_6->dir = sub_arv_7;
	sub_arv_2->dir = sub_arv_4;
	sub_arv_1->dir = sub_arv_5;
	mostrar_arvore(raiz);
	return 0;
}
