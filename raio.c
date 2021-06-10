#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct ponto Ponto;
struct ponto
{

	float r;
	float t;
};

float distancia_radial(Ponto *p)
{
	float r1;

	r1 = sqrt((p->r * p->r) + (p->t * p->t));

	return r1;
}

Ponto *coordenadas_polares(Ponto *p)
{
	float r1;

	r1 = distancia_radial(p);

    if(p -> r != 0)
    {
        p->r = r1 * cos(atan(p->t / p->r));
	    p->t = r1 * sin(atan(p->t / p->r));
    } 

	return p;
}

float distancia_coordenadas_polares(Ponto *p1, Ponto *p2)
{
	float d;

    p1 = coordenadas_polares(p1);
    p2 = coordenadas_polares(p2);

	return d = sqrt((p1->r - p2->r) * (p1->r - p2->r) + (p1->t - p2->t) * (p1->t - p2->t));
}

Ponto *pto_cria(float x, float y)
{
	Ponto* p = (Ponto *)malloc(sizeof(Ponto));

	if (p == NULL)
	{
		exit(1);
	}

	p -> r = x;
	p -> t = y;

    return p;
}

void pto_acessa(Ponto *p, float *x, float *y)
{
	*x = p->r;
	*y = p->t;
}

void pto_atribui(Ponto *p, float x, float y)
{
	p->r = x;
	p->t = y;
}

void pto_libera(Ponto *p)
{
	free(p);
}

int main(void)
{
	float x1, y1, x2, y2;
	scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

	Ponto* p = pto_cria(x1, y1);
	Ponto* q = pto_cria(x2, y2);

	float d = distancia_coordenadas_polares(p, q);
	printf("%.2f\n", d);

	pto_libera(p);
	pto_libera(q);

	return 0;
}

float distancia_radial(Ponto* p);

Ponto* coordenadas_polares(Ponto* p);

float distancia_coordenadas_polares(Ponto* p1, Ponto* p2); 

Ponto* pto_cria(float x, float y);

void pto_acessa(Ponto *p, float *x, float *y);

void pto_atribui(Ponto *p, float x, float y);

void pto_libera(Ponto* p);
