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

//МОЕ РЕШЕНИЕ
#include <stdio.h>

#define SIZE 3 // Размер массивов A и B

int main() {
    // 1. Создаем массивы A и B
    float A[SIZE * 2] = {1.0, 2.0, 3.0, -1.0, 4.0, 0.5}; // Пример значений для A
    float B[SIZE * 2] = {2.0, -3.0, 1.0, 2.5, 0.0, -4.0}; // Пример значений для B
    float C[SIZE * 2]; // Массив для хранения суммы

    // 2. Сложение A и B в C
    for (int i = 0; i < SIZE * 2; i++) {
        C[i] = A[i] + B[i];
    }

    // 3. Нахождение максимальной реальной части в A
    float max_real_A = A[0];
    int count_imag_B_negative = 0;

    for (int i = 0; i < SIZE; i++) {
        // Проверяем реальную часть
        if (A[i * 2] > max_real_A) {
            max_real_A = A[i * 2];
        }
        // Проверяем мнимую часть B
        if (B[i * 2 + 1] < 0) {
            count_imag_B_negative++;
        }
    }

    printf("Максимальная реальная часть массива A: %.2f\n", max_real_A);
    printf("Количество мнимых частей, которые меньше 0 в массиве B: %d\n", count_imag_B_negative);

    // 4. Вычисление среднего арифметического элементов массива C
    float sum_C = 0;
    for (int i = 0; i < SIZE * 2; i++) {
        sum_C += C[i];
    }
    float average_C = sum_C / (SIZE * 2);
    printf("Среднее арифметическое элементов массива C: %.2f\n", average_C);

    return 0;
}
