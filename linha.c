#include <stdio.h>
#include <math.h>
typedef struct ponto Ponto;
struct ponto{
	float x,y;
};
float distancia(Ponto a, Ponto b){

    float distancia_entre_centros;
    float dc1, dc2;

    dc1 = pow((a.x - b.x), 2);
    dc2 = pow((a.y - b.y), 2);

    distancia_entre_centros = sqrt(dc1 + dc2);
    //printf("%f", distancia_entre_centros);

    return distancia_entre_centros;

}

float comprimento(int n, Ponto* v){
    float distancia_pontos;
    float resultado = 0;

    for(int i = 0; i < n-1; i++){
       resultado += distancia(v[i], v[i+1]);
       //printf("%f\n", v[i].x);
    }
    return resultado;
}
int main()
{
    int qtd_pontos;
    float comprimento_da_linha;
    scanf("%d", &qtd_pontos);
    Ponto pontos_da_linha[qtd_pontos];

    for(int i = 0; i < qtd_pontos; i++){
        scanf("%f %f", &pontos_da_linha[i].x, &pontos_da_linha[i].y);
    }

    comprimento_da_linha = comprimento(qtd_pontos, pontos_da_linha);
    printf("%.2f", comprimento_da_linha);
    //printf("%f", pontos_da_linha[0].x);

    return 0;
}
