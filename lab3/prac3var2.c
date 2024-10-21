#include <stdio.h>
void main(){//Программа вычисляет факториал 
	long long int b,c=1,a=1;
	puts("Введите число до 25");
	scanf("%d",&b);
	for (long long int n = a; n%a!=0||n%b!=0;n++){
		c *=n;
}
printf("%lld\n",c*b);
}
