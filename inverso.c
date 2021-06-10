/*
#include <stdio.h>
void inverte(int ent){
	int vet[ent];
	int valor;
	for(int i = 0;i < ent;i++){
		scanf("%d",&valor);
		vet[i] = valor;
	}
	for(int i = ent-1;i >= 0;i--){
		printf("%d ",vet[i]);
	}
}


int main(){
	int ent;
	scanf("%d",&ent);
	int vet[ent];
	inverte(ent);
	//imprime(ent);
	return 0;
}
*/
#include <stdio.h>

void preenche (int n, int *v)
{
   int num, i;
   for(i = 0; i < n; i++)
   {
      scanf("%d", &num);
      v[i] = num;
   }
}
void inverte(int n, int *v)
{
  preenche(n, v);
  int aux = 0, i;
  for(i = 0; i < n/2; i++)
  {
     aux = v[n-1];
     v[n-1] = v[i];
     v[i] = aux;
  }
}
void imprime (int n, int *v)
{
   int num, i;
   for(i = 0; i < n; i++)
   {
      
      printf("%d ",v[i]);
   }
}
int main()
{
	  int n;
	  scanf("%d",&n);
	  int *v[n];
	  inverte(n, v);
	  imprime(n,v);
	  return 0;
}
