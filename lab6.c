#include<stdio.h>
int main(){
int A[10]={1,2,-3,4,-32,27,49,-9,-5,0};
int B[10]={6,-4,-8,6,1,-22,4,-4,8,6};
int C[10]={0};
for (int i = 0; i<10; i++){
    C[i]=A[i]+B[i];
    printf(" %d", C[i]);
}
int max = 0;
int count = 0;
for (int i = 0; i<10; i=i+2){
    if (A[i]>max){
        max= A[i];
    }
    if (B[i+1]<0){
        count++;
    }
}
int summ = 0;
for (int i=0; i<10; i++){
    summ+=C[i];
}
printf("\nМаксимальное из реальных А:\n%d",max);
printf("\nКоличепство отрицательных в мнимых В:\n%d",count);
printf("\nСреднее всех элементов С:\n%d",summ/10);
}
