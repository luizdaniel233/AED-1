#include <stdio.h>
#include<stdlib.h>
typedef struct lista Lista;
typedef struct listano ListaNo;
struct lista{
  ListaNo *prim, *ult;
};
struct listano{
  double valor;
  ListaNo* prox;
};
Lista* cria_lista(){
  Lista* l = malloc(sizeof(Lista));
  l->prim = l->ult = NULL;
  return l;
}
int listaVazia(Lista *l){
  return l->prim==NULL;
}
void insere_lista_inicio(Lista *l, double x){
  ListaNo* p = malloc(sizeof(ListaNo));
  p->valor = x;
  p->prox = l->prim;
  l->prim = l->ult = p;
}
void insere_lista_fim(Lista *l, double x){
  if(listaVazia(l)){
    insere_lista_inicio(l, x);
    return;
  }
  ListaNo *p = malloc(sizeof(ListaNo));
  p->valor = x;
  l->ult->prox = p;
  l->ult = p;
}
Lista* merge(Lista* l1, Lista* l2){
  Lista *l3 = malloc(sizeof(Lista)); 
  ListaNo *p1 = malloc(sizeof(ListaNo));
  ListaNo *p2 = malloc(sizeof(ListaNo));
  for(p1=l1->prim,p2=l2->prim;p1!=NULL || p2!=NULL;){
    if(p1!=NULL){//Insere valor de p1 em l3
      insere_lista_fim(l3, p1->valor);
      p1 = p1->prox;
    }
    if(p2!=NULL){ //insere valor de p2 em l3
      insere_lista_fim(l3, p2->valor);
      p2 = p2->prox;
    }
  }
  return l3;
}
void imprime_lista(Lista* l1){
  ListaNo* p;
  for(p=l1->prim;p!=NULL;p=p->prox){
    printf("%.1lf ",p->valor);
  }
  printf("\n");
}
int main(void) {
  int n;
  double x;
  Lista *l1=cria_lista(),*l2=cria_lista(), *l3;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lf",&x);
    insere_lista_inicio(l1, x);
  }
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lf",&x);
    insere_lista_inicio(l2, x);
  }
  l3 = merge(l1,l2);
  imprime_lista(l3);
  return 0;
}
