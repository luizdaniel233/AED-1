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
int mostrar(tipoLista* l){
	tipoNo* p;
	int ult;
	for(p = l->prim; p != NULL; p=p->prox) {
		ult = p->info;
		
	}
	
	return ult;
}
 

int main() {
 tipoLista* l;
	int tam;
	scanf("%d",&tam);
 	l = criarLista(tam);
 	int num;
	for(int i = 0;i < tam;i++){
		scanf("%d",&num);
		inserirLista(l, num);
	}
	printf("%d ",mostrar(l));
 return 0;
}
