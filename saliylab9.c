#include <stdio.h>
#include <stdlib.h> // Для rand()
#include <time.h> // для time()

//Функция для рандомайзера
int rand_int(int min, int max) {
        return (rand() % (max - min + 1)) + min;
}




//Функция заполнения матрицы случайными числами
int matrix_stack(int N){
int arr_2d[N][N];
float x[N];
float b[N];
float sum = 0.00;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr_2d[i][j] = rand_int(0, 100);
        }
    }
    for (int i = 0; i < N; i++) {
        b[i] = rand_int(-100, 100);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr_2d[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += arr_2d[i][j];
        }
        
    }
    sum = sum / (N*N);
    printf("%f",sum);
}


int sr_arifm(int N, int arr_2d){
    
}

int main() {

int N;

srand(time(NULL));
printf("Введите размер матрицы: ");
scanf("%d", &N);
    matrix_stack(N);
    
}