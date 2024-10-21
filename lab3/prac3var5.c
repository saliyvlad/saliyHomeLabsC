#include <stdio.h>
void main(){//Программа проверяет на четность
	int n,a,s;
	scanf("%d",&a);
	for (int s=0,n = 2; n<=a;n++){
	if(a%n==0 || a == 2)s++;

	if (s==0){puts("1");break;}
	else {puts("0");break;}
}
}
