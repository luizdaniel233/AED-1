#include <stdio.h>
#include <stdlib.h>

typedef struct complexo Complexo;
struct complexo
{
    float re;
    float im;
};

Complexo *cria_numero(Complexo *n)
{
    n = (Complexo *)malloc(sizeof(Complexo));

    if (n == NULL)
    {
        exit(1);
    }

    return n;
}
void libera(Complexo *n)
{
    free(n);
}
//////////////acessar////////////////////////////
float parte_re(Complexo *n)
{
    return n->re;
}

float parte_im(Complexo *n)
{
    return n->im;
}
//////////////atribuir///////////////////////////
void atribuir_complexo(Complexo *n)
{
    float a, b;
    scanf("%f%f", &a, &b);
    n->re = a;
    n->im = b;
}
/////////////operacoes///////////////////////////
Complexo *soma_complexo(Complexo *n1, Complexo *n2)
{
    Complexo* soma;

    soma = (Complexo *)malloc(sizeof(Complexo));

    if (soma == NULL)
    {
        exit(1);
    }

    soma->re = n1->re + n2->re;
    soma->im = n1->im + n2->im;

    return soma;
}

Complexo *subtracao_complexo(Complexo *n1, Complexo *n2)
{
    Complexo* subtracao;

    subtracao = (Complexo *)malloc(sizeof(Complexo));

    if (subtracao == NULL)
    {
        exit(1);
    }

    subtracao->re = n1->re - n2->re;
    subtracao->im = n1->im - n2->im;

    return subtracao;
}
Complexo *multiplicacao_complexo(Complexo *n1, Complexo *n2)
{
    Complexo* multiplicacao;

    multiplicacao = (Complexo *)malloc(sizeof(Complexo));

    if (multiplicacao == NULL)
    {
        exit(1);
    }

    multiplicacao->re = ((n1->re * n2->re) - (n1->im * n2->im));
    multiplicacao->im = ((n1->im * n2->re) + (n1->re * n2->im));

    return multiplicacao;
}
Complexo *divisao_complexo(Complexo *n1, Complexo *n2)
{
    Complexo* divisao;

    divisao = (Complexo *)malloc(sizeof(Complexo));

    if (divisao == NULL)
    {
        exit(1);
    }

    divisao->re = ((n1->re * n2->re) + (n1->im * n2->im)) / ((n2->re * n2->re) + (n2->im * n2->im));
    divisao->im = ((n1->im * n2->re) - (n1->re * n2->im)) / ((n2->re * n2->re) + (n2->im * n2->im));

    return divisao;
}

int main(void)
{
    Complexo *p, *q, *soma, *subtracao, *multiplicacao, *divisao;

    p = cria_numero(p);
    q = cria_numero(p);
    atribuir_complexo(p);
    atribuir_complexo(q);

    soma = soma_complexo(p, q);
    printf("Soma: parte real: %.2f parte imaginaria: %.2f\n", parte_re(soma), parte_im(soma));
    subtracao = subtracao_complexo(p, q);
    printf("Subtracao: parte real: %.2f parte imaginaria: %.2f\n", parte_re(subtracao), parte_im(subtracao));
    multiplicacao = multiplicacao_complexo(p, q);
    printf("Multiplicacao: parte real: %.2f parte imaginaria: %.2f\n", parte_re(multiplicacao), parte_im(multiplicacao));
    divisao = divisao_complexo(p, q);
    printf("Divisao: parte real: %.2f parte imaginaria: %.2f\n", parte_re(divisao), parte_im(divisao));

    libera(p);
    libera(q);
    libera(soma);
    libera(subtracao);
    libera(multiplicacao);
    libera(divisao);

    return 0;
}




Complexo *cria_numero(Complexo *n);

void libera(Complexo *n);

float parte_re(Complexo *n);

float parte_im(Complexo *n);

void atribuir_complexo(Complexo *n);

Complexo *soma_complexo(Complexo *n1, Complexo *n2);

Complexo *subtracao_complexo(Complexo *n1, Complexo *n2);

Complexo *multiplicacao_complexo(Complexo *n1, Complexo *n2);

Complexo *divisao_complexo(Complexo *n1, Complexo *n2);
