#include <stdio.h>
#include <stdlib.h>
typedef struct tipoNo tipoNo;
typedef struct tipoLista tipoLista;
struct tipoNo {
 int info;
 tipoNo* prox;
};
struct tipoLista {
 tipoNo* prim;
};
tipoLista* criarLista(int tam) {
 tipoLista* l;
 l = malloc(tam*sizeof(tipoLista));
 l->prim = NULL;
 return l;
}
void inserirLista(tipoLista* l, int v) {
 tipoNo* novo = malloc(sizeof(tipoNo));
 novo->info = v;
 novo->prox = l->prim;
 l->prim = novo;
}
void concatena(tipoLista* l1){
	tipoNo* p;
	tipoNo* p2;
	for(p = l1->prim; p != NULL; p=p->prox) {
		printf("%d ",p->info);
		
	}
	
}
 

int main() {
 tipoLista* l;
 tipoLista* l2;
	int tam;
	scanf("%d",&tam);
 	l = criarLista(tam);
 	int num;
	for(int i = 0;i < tam;i++){
		scanf("%d",&num);
		inserirLista(l, num);
	}
	scanf("%d",&tam);
	l2 = criarLista(tam);
	for(int j = 0;j < tam;j++){
		scanf("%d",&num);
		inserirLista(l2, num);
	}
	
	concatena(l);
	concatena(l2);
 return 0;
}
