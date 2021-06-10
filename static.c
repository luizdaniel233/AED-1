#include<stdio.h>

int f(int n){
	static int c;
	c++;
    printf("OLA %d\n",c);
    if (n>0) {
        n--;
        f(n);
        n--;
        f(n);
		 
		 
    }
//printf("%d\n",cont);
}
int main()
{
   	int n;
    scanf("%d", &n);
    f(n);
 	return 0; 
}
