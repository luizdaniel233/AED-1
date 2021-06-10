#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;

struct aluno{

	char nome[81];

	char matricula[8];

	char turma;

	float p1;

	float p2;

	float p3;

};

void imprime_aprovados(int n, char t, Aluno** turmas)
{
	int i;
	float media = 0, cont = 0, soma = 0;

	for(i = 0; i < n; i++)
	{
		if((turmas[i] -> turma) == t)
		{
			soma += ((turmas[i] -> p1) + (turmas[i] -> p2) + (turmas[i] -> p3))/3;
			cont++;
		}
	}
	if(cont != 0)
	{
		media = soma/cont;
		printf("%.2f\n", media);
	}
	else
	{
		printf("%.2f\n", media);
	}
	
}
void inicializa(int n, Aluno** turmas)
{
	int i;
	for(i = 0; i < n; i++)
	{
		turmas[i] = NULL;
	}
}
void preenche (int n, Aluno** turmas)
{
	int i;

	for(i = 0; i < n; i++)
	{
		turmas[i] = (Aluno*) malloc(4*sizeof(Aluno));
	}


	for(i = 0; i < n; i++)
	{
		scanf("%s ", &(turmas[i] -> nome));
		scanf("%s ", &(turmas[i] -> matricula));
		scanf(" %c", &(turmas[i] -> turma));
		scanf("%f %f %f", &(turmas[i] -> p1), &(turmas[i] -> p2), &(turmas[i] -> p3));
	}

}
void retira (int n, Aluno** turmas)
{
	int i;

	for(i = 0; i < n; i++)
	{
		free(turmas[i]);
	}
}

void main(void)
{
	int numAlunos, consulta;
	char t;
	scanf("%d", &numAlunos);

	Aluno* turmas[numAlunos];
	inicializa(numAlunos, turmas);	
	preenche(numAlunos, turmas);

	scanf("%d", &consulta);
	while(consulta >= 1)
	{
		scanf(" %c", &t);
		imprime_aprovados(numAlunos, t, turmas);

		consulta--;
	}
	retira(numAlunos, turmas);
}
