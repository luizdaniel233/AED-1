#include <stdio.h>
#include<stdlib.h>
typedef struct fila Fila;
typedef struct listano ListaNo;
struct fila{
  ListaNo *prim, *ult;
};
struct listano{
  float valor;
  ListaNo* prox;
};
Fila* fila_cria(){
  Fila* l = malloc(sizeof(Fila));
  l->prim = l->ult = NULL;
  return l;
}
int fila_vazia(Fila *l){
  return l->prim==NULL;
}
void insere_lista_inicio(Fila *l, float x){
  ListaNo* p = malloc(sizeof(ListaNo));
  p->valor = x;
  p->prox = l->prim;
  l->prim = l->ult = p;
}
void fila_insere(Fila *l, float x){
  if(fila_vazia(l)){
    insere_lista_inicio(l, x);
    return;
  }
  ListaNo *p = malloc(sizeof(ListaNo));
  p->valor = x;
  l->ult->prox = p;
  l->ult = p;
}
Fila* merge(Fila* l1, Fila* l2){
  Fila *l3 = malloc(sizeof(Fila)); 
  ListaNo *p1 = malloc(sizeof(ListaNo));
  ListaNo *p2 = malloc(sizeof(ListaNo));
  for(p1=l1->prim,p2=l2->prim;p1!=NULL || p2!=NULL;){
    if(p1!=NULL){//Insere valor de p1 em l3
      fila_insere(l3, p1->valor);
      p1 = p1->prox;
    }
    if(p2!=NULL){ //insere valor de p2 em l3
      fila_insere(l3, p2->valor);
      p2 = p2->prox;
    }
  }
  return l3;
}
void imprime_fila(Fila* l1){
  ListaNo* p;
  for(p=l1->prim;p!=NULL;p=p->prox){
    printf("%.1f ",p->valor);
  }
  printf("\n");
}
int main(int argc, char **argv) {
	char c = 0;
  int n;
  float x;
  Fila *l1=fila_cria(),*l2=fila_cria(), *l3;
	
  while( scanf("%f",&x) == 1){
    fila_insere(l1, x);
	  
  }
	scanf("%*s");
	
  while(scanf("%f",&x) == 1){
    fila_insere(l2, x);
	 
  }
	scanf("%*s");
	
  l3 = merge(l1,l2);
  imprime_fila(l3);
  return 0;
}
typedef struct fila Fila;

Fila* fila_cria();

void fila_insere(Fila* f, float v);

float fila_retira(Fila* f);

int fila_vazia(Fila* f);

void fila_libera(Fila* f);
