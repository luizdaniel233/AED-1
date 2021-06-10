#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct ponto Ponto;
struct ponto{
	float x,y;
};
typedef struct circulo Circulo;
struct circulo{
	Ponto c;
	float r;
};
int intersecao(Circulo* a, Circulo* b){

    float distancia_entre_centros, soma_raios;
    float dc1, dc2;

    soma_raios = a->r + b->r;

    dc1 = pow((a->c.x - a->c.y), 2);
    dc2 = pow((b->c.x - b->c.y), 2);

    distancia_entre_centros = sqrt(dc1 + dc2);

    if(distancia_entre_centros <= soma_raios){
        return 1;
    }else{
        return 0;
    }

}
int main(){
	Ponto p;
	Circulo cc;
	Circulo cc2;
	scanf("%f %f %f %f %f %f",&cc.c.x,&cc.c.y,&cc.r,&cc2.c.x,&cc2.c.y,&cc2.r);
	printf("%d",intersecao(&cc,&cc2));
	
return 0;
}
