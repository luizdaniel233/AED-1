#include <stdio.h>
#define N 3
	int triangular_inferior(double A[][N]){
		double valor;
		int acumI,acumNI;
		for(int i =0;i < N;i++){
			for(int j = 0;j < N;j++){
				scanf("%lf",&valor);
				A[i][j] = valor;
			}
		}
		for(int i =0;i < N;i++){
			for(int j = 0;j < N;j++){
				if((i < j)&& A[i][j] == 0){
					acumI += 1;
				}else{
					acumNI = 0;
				}
			}
		}
		return acumI;
	}
int main(){
	double mat[N][N];
	if(triangular_inferior(mat) > 0){
		printf("1");
	}else{
		printf("0");
	}
	
	return 0;
}
