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
tipoLista* criarLista() {
 tipoLista* l;
 l = malloc(sizeof(tipoLista));
 l->prim = NULL;
 return l;
}
void inserirLista(tipoLista* l, int v) {
 tipoNo* novo = malloc(sizeof(tipoNo));
 novo->info = v;
 novo->prox = l->prim;
 l->prim = novo;
}
int comprimento(tipoLista* l) {
 int count = 0;
 tipoNo* p;
 for(p = l->prim; p != NULL; p=p->prox) {
  count++;
 }
 return count;
}
int main() {
 tipoLista* l;
 l = criarLista();
 int num;
 while(scanf("%d", &num) != EOF) {
  inserirLista(l, num);
 }
 printf("%d", comprimento(l));
 return 0;
}
