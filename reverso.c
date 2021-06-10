#include <stdio.h>
#include <stdlib.h>
void inicializa(int tam,float* vet){
	float valor;
	for(int i = 0;i < tam;i++){
		scanf("%f",&valor);
		vet[i] = valor;
	}
}
float* reverso(int n, float* v){
	float* v2;
	v2[n] = v[n];
	return v2;
}
int main(){
	int tam;
	scanf("%d",&tam);
	float* vet = malloc(tam * sizeof(int));
	inicializa(tam,vet);
	float* v2 = malloc(tam * sizeof(int));
	for(int i = tam;i >= 0;i--){
 		v2[i] = vet[i];
	}
	for(int j = tam - 1; j >= 0;j--){
		printf("%.2f ",v2[j]);
	}
	free(vet);
	free(v2);
	return 0;
}
