#include<stdio.h>

typedef struct criarData
{
    unsigned short int dia, mes, ano; 
} tipoData;

tipoData lerData()
{
	tipoData dt;
    scanf("%d %d %d", &dt.dia,&dt.mes,&dt.ano);
	return dt;
	
}

int validaData(tipoData dt)
{
    if(dt.ano >= 1900 && dt.ano <= 2050){
	 	if(dt.mes >= 1 && dt.mes <= 12 ){
	 		switch(dt.mes){
				case 1:
					if(dt.dia >= 1 && dt.dia <= 31){
						return 1;
						break;
					}
				case 2:
						if (dt.ano % 4 == 0){
							if ((dt.ano % 100 != 0) || (dt.ano % 400 == 0)){
								return 1;
								break;
							}else{
								if ((dt.ano % 100 == 0) || (dt.ano % 400 != 0)){
									return 0;
									break;
								}else{
									return 0;
									break;
								}
							}
						}else{
							if(dt.ano % 4 != 0){
								return 0;
								break;
							}
						 	
						}
				case 3:
					if(dt.dia >= 1 && dt.dia <= 31){
						return 1;
						break;
					}
				case 4:
					if(dt.dia >= 1 && dt.dia <= 30){
						return 1;
						break;
					}
				case 5:
					if(dt.dia >= 1 && dt.dia <= 31){
						return 1;
						break;
					}
				case 6:
					if(dt.dia >= 1 && dt.dia <= 30){
						return 1;
						break;
					}
				case 7:
					if(dt.dia >= 1 && dt.dia <= 31){
						return 1;
						break;
					}
				case 8:
					if(dt.dia >= 1 && dt.dia <= 31){
						return 1;
						break;
					}
				case 9:
					if(dt.dia >= 1 && dt.dia <= 30){
						return 1;
						break;
					}
				case 10:
					if(dt.dia >= 1 && dt.dia <= 31){
						return 1;
						break;
					}
				case 11:
					if(dt.dia >= 1 && dt.dia <= 30){
						return 1;
						break;
					}
				case 12:
					if(dt.dia >= 1 && dt.dia <= 31){
						return 1;
						break;
					}
				default:
					return 0;
					break;
			}
		}
	 }else{
		 return 0;
	 }
}

void main() 
{
    tipoData dt;
    dt = lerData();

    printf("%d",validaData(dt));
}
