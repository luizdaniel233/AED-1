#include <stdio.h>
#include <stdlib.h>
void inicializa(int tam,int* v){
	int valor;
	for(int i = 0;i < tam;i++){
		scanf("%d",&valor);
		v[i] = valor;
	}
}
int* soma(int* x1,int* x2,int n){
	int* v3 = malloc(n *sizeof(int));
	for(int i = 0;i < n;i++){
		v3[i] = x1[i] + x2[i];
	}
	for(int i = 0;i < n;i++){
		printf("%d ",v3[i]);
	}
}
int main(){
	int tam;
	scanf("%d",&tam);
	int* v = malloc(tam*sizeof(int));
	int* v2 = malloc(tam*sizeof(int));
	inicializa(tam,v);
	inicializa(tam,v2);
	soma(v,v2,tam);
	free(v);
	free(v2);
return 0;
}
