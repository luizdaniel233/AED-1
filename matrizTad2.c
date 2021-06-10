#include <stdio.h>
#include <stdlib.h>
typedef struct matriz Matriz;
struct matriz{
  int lin;
  int col;
  float** v;
};

Matriz* mat_cria(int m, int n)
{
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));

    if(mat == NULL)
    {
        exit(1);
    }

    mat -> lin = m;
    mat -> col = n;

    float** u = (float**)malloc(m*sizeof(float*));

    if(u == NULL)
    {
        exit(1);
    }

    int i;
    for(i = 0; i < m; i++)
    {
        u[i] = (float*)malloc(n*sizeof(float));
    }

    mat -> v = u;

    return mat;
}

void mat_libera(Matriz* mat)
{
    free(mat -> v);
    free(mat);
}

float mat_acessa(Matriz* mat, int i, int j)
{
    int n = mat -> col;
    return mat -> v[i][j];
}

void mat_atribui(Matriz* mat, int i, int j, float valor)
{
    int n = mat -> col;
    mat -> v[i][j] = valor;
}

int mat_linhas(Matriz* mat)
{
    return mat -> lin;
}

int mat_colunas(Matriz* mat)
{
    return mat -> col;
}

Matriz* transposta(Matriz* mat)
{
    Matriz* trp = (Matriz*)malloc(sizeof(Matriz));

    if(trp == NULL)
    {
        exit(1);
    }
    trp -> lin = mat -> col;
    trp -> col = mat -> lin;

    int m = trp -> lin;
    int n = trp -> col;

    float** w = (float**)malloc(m*sizeof(float*));
    if(w == NULL)
    {
        exit(1);
    }
    int i, j;
    for(i = 0; i < m; i++)
    {
        w[i] = (float*)malloc(n*sizeof(float));
    }
    trp -> v = w;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            w[j][i] = mat_acessa(mat, i, j);
        }
    }
    return trp;
}
int main(void)
{
    int m, n;

    scanf("%d%d", &m, &n);

    Matriz* mat;
    mat = mat_cria(m, n);

    int i, j;
    float v;
    for(i = 0; i < mat_linhas(mat); i++)
	{
		for(j = 0; j < mat_colunas(mat); j++)
		{
			scanf("%f", &v);
			mat_atribui(mat, i, j, v);
		}  
	}

    Matriz* trp;
    trp = transposta(mat);

    for(i = 0; i < mat_linhas(trp); i++)
    {
        for(j = 0; j < mat_colunas(trp); j++)
        {
            printf("%.2f ", mat_acessa(trp, i, j));
        }
        printf("\n");
    }

    return 0;
}


Matriz* mat_cria(int m, int n);

void mat_libera(Matriz* mat);

float mat_acessa(Matriz* mat, int i, int j);

void mat_atribui(Matriz* mat, int i, int j, float v);

int mat_linhas(Matriz* mat);

int mat_colunas(Matriz* mat);

Matriz* transposta(Matriz* mat);
