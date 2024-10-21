#include <stdio.h>
void main(){//Программа вычисляет простое число  
	int a,n;
	puts("введите число для проверки:");
	scanf("%d",&a);
	for (n = 2; n<a && a%n!=0;n++);
{	
	if (n==a) puts("простое число");
	else puts("0");
}
}
