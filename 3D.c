#include <stdio.h>
#include <stdlib.h>
typedef struct vetor{
	float x;
	float y;
	float z;
} Vetor;
float escalar(Vetor* v1, Vetor* v2){
	//Vetor* v3;
	float acum;
	acum = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	
	return acum;
}

int main(){
 Vetor v1;
 Vetor v2;
	scanf("%f %f %f %f %f %f",&v1.x,&v1.y,&v1.z,&v2.x,&v2.y,&v2.z);
	printf("%.2f",escalar(&v1,&v2));
}
