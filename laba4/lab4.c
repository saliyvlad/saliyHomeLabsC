#include <stdio.h>
int main(){
	int height;
	int m=0;
	printf("Введите высоту треугольника");
	scanf("%d",&height);
	for(int m=0;m<2;m++){//Изменить количество треугольников можно поменяв цифру в условии
	for(int i = 1;i<=height;i++){

		for(int j = height;j>i;j--){
			printf(" ");
		}
			for(int k=1;k<=(2*i-1);k++){
				printf("*");
						
					
					}
				printf("\n");
				}
}		
	return 0;

}
