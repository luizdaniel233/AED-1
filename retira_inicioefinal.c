#include <stdio.h>
#include <stdlib.h>
typedef struct tipoData tipoData;
typedef struct List List;
struct tipoData {
 int info;
 tipoData* prox;
};
struct List {
 tipoData* prim;
};
List* create(int tam) {
 List* l;
 l = malloc(tam*sizeof(List));
 l->prim = NULL;
 return l;
}
void insere(List* l, int v) {
 tipoData* novo = malloc(sizeof(tipoData));
 novo->info = v;
 novo->prox = l->prim;
 l->prim = novo;
}
void delete(List* l, int v) {
 tipoData* ant = NULL;
 tipoData* p = l->prim;
 while(p != NULL && p->info != v) {
  ant = p;
  p = p->prox;
 }
 if(p != NULL) {
  if(ant == NULL) {
   l->prim = p->prox;
  }
  else {
   ant->prox = p->prox;
  }
  free(p);
 }
}
void delete_ini(List* l) {
 tipoData* p = l->prim;
 delete(l, p->info);
}
void delete_finally(List* l) {
 int r;
 tipoData* p = l->prim;
 for(p; p != NULL; p = p->prox) {
  r = p->info;
 }
 delete(l, r);
}
void imprime_lista(List* l1){
  tipoData* p;
  for(p=l1->prim;p!=NULL;p=p->prox){
    printf("%d ",p->info);
  }
  printf("\n");
}
 

int main() {
 List* l;
	int tam;
	scanf("%d",&tam);
 	l = create(tam);
 	int num;
	for(int i = 0;i < tam;i++){
		scanf("%d",&num);
		insere(l, num);
	}
	int qtd = 0;
	int op;
	scanf("%d",&qtd);
	for(int j = 0;j < qtd;j++){
		scanf("%d",&op);
		if(op == 0){
			delete_ini(l);
		}else{
			if(op == 1){
				delete_finally(l);
			}
		}
	}
	imprime_lista(l);
 return 0;
}
