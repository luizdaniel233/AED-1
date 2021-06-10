#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int raizes (double a, double b, double c, double* px1, double* px2);
int main(){
	 double a,b,c,delta,raiz,total1,total2,total3;
	scanf("%lf %lf %lf",&a,&b,&c);
	delta = (pow(b,2) - (4 * a * c));
	//printf("%2.lf",sqrt(delta));
	//raiz = (pow(b,2) - (4 * a * c)
	total1 = (-b + sqrt(delta)) / (2*a);
	total2 = (-b - sqrt(delta)) / (2*a);
	total3 = raizes(a,b,c,&total1,&total2);
		//printf("%.2f %.2f\n",total1,total2);
	return 0;
}
int raizes (double a, double b, double c, double* px1, double* px2){
	double delta;
	delta = (pow(b,2) - (4 * a * c));
	if(delta > 0){
		printf("2 %.2lf %.2lf\n",*px1,*px2);
	}else{
		if(delta == 0){
			printf("1 %.2lf",*px1);
		}else{
			printf("-1");
		}
	}
}
