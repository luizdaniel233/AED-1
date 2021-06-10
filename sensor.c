#include <stdio.h>
#include <math.h>
void inicializa(int tam,float vet[]){
	float valor;
	for(int i = 0;i < tam;i++){
		scanf("%f",&valor);
		vet[i] = valor;
	}
	
}
void media_variancia(int n, float x[], float *pm, float *pv){
	printf("%.2f\n",*pm);
	printf("%.2f\n",*pv);
}
int main(){
	float acumM,acumV;
	int tam;
	scanf("%d",&tam);
	float vet[tam];
	inicializa(tam,vet);
	for(int j = 0;j < tam;j++){
		acumM += vet[j];
		
	}
	acumM = acumM/tam;
	for(int c = 0;c < tam;c ++){
		acumV += pow((vet[c] - acumM),2)/tam;
	}
	media_variancia(tam,vet,&acumM,&acumV);
	
}
