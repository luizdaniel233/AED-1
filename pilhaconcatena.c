#include <stdio.h>
#include <stdlib.h>
typedef struct pilha Pilha;
void concatena_pilhas(Pilha* p1, Pilha* p2);
struct pilha{
	int n;
	int dim;
	float* vet;
};
Pilha* pilha_cria(void){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->dim  = 2;
	p->vet = malloc(p->dim*sizeof(float));
	p->n = 0;
	return p;
}
void pilha_push(Pilha* p,float v){
	if(p->n == p->dim){
		p->dim = 2*p->dim;
		p->vet = realloc(p->vet,p->dim * sizeof(float));
	}
	p->vet[p->n] = v;
	p->n = p->n+1;
}

int pilha_vazia(Pilha* p){
	return (p->n == 0);
}
float pilha_pop(Pilha* p){
	if(pilha_vazia(p)){
		printf("\n*\n");
		exit(1);
	}
	p->n = p->n - 1;
	float v = p->vet[p->n];
}
void pilha_libera(Pilha* p){
	free(p->vet);
	free(p);
}
void pilha_imprime(Pilha* p){
	for(int i=p->n-1;i>= 0;i--){
		printf("%.1f\n",p->vet[i]);
	}
}
void concatena_pilhas(Pilha* p1, Pilha* p2){
	
}
int main(){
	int tamanhop;
	int ops;
	float valor;
	scanf("%d",&tamanhop);
	Pilha* vet[tamanhop];
	vet[0] = pilha_cria();
	for(int j = 0;j < tamanhop;j++){
			scanf("%f",&valor);
			pilha_push(vet[0],valor);
	}
	scanf("%d",&tamanhop);
	Pilha* vet2[tamanhop];
	vet2[0] = pilha_cria();
	for(int j = 0;j < tamanhop;j++){
			scanf("%f",&valor);
			pilha_push(vet2[0],valor);
	}
		pilha_imprime(vet2[0]);
		pilha_imprime(vet[0]);
	   
	return 0;
}
