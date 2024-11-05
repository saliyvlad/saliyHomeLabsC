#include <stdio.h>
#include <stdlib.h> // Для rand()
#include <time.h> // для time()

int rand_int(int min, int max) {
        return (rand() % (max - min + 1)) + min;
}


    


int main() {

int N,M;
srand(time(NULL));
scanf("%d",&N);
    int arr_2d[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr_2d[i][j] = rand_int(-100, 100);
        }
    }
switch(N){
        case 1: return arr_2d[0][0];
        case 2:
            return (arr_2d[0][0]*arr_2d[1][1])-(arr_2d[1][0]*arr_2d[0][1]);
        case 3: return 
            arr_2d[0][0]*arr_2d[1][1]*arr_2d[2][2]+//main diagonal
            arr_2d[1][0]*arr_2d[0][2]*arr_2d[2][1]+
            arr_2d[0][1]*arr_2d[2][0]*arr_2d[1][2]-
            arr_2d[0][2]*arr_2d[1][1]*arr_2d[2][0]+//second diagonal
            arr_2d[0][0]*arr_2d[2][1]*arr_2d[1][2]+
            arr_2d[0][1]*arr_2d[1][0]*arr_2d[2][2];
        default:
            printf("d,slad,las\n");
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr_2d[i][j]);
        }
        printf("\n");
    }
    
    

}


#4
#include <stdio.h>

#define MAX_SIZE 3 // Максимальный размер матрицы

float determinant2x2(float matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

float determinant3x3(float matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int main() {
    int N;
    float matrix[MAX_SIZE][MAX_SIZE];
    float b[MAX_SIZE]; // Вектор свободных членов
    float x[MAX_SIZE]; // Решения

    // Запрос размера матрицы
    printf("Введите размер матрицы (2 или 3): ");
    scanf("%d", &N);

    if (N < 2 || N > 3) {
        printf("Неверный размер матрицы!\n");
        return 1;
    }

    // Ввод коэффициентов матрицы
    printf("Введите элементы матрицы (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Ввод вектора свободных членов
    printf("Введите вектор свободных членов:\n");
    for (int i = 0; i < N; i++) {
        scanf("%f", &b[i]);
    }

    // Вычисление определителя матрицы
    float det = (N == 2) ? determinant2x2(matrix) : determinant3x3(matrix);
    if (det == 0) {
        printf("Система не имеет уникального решения.\n");
        return 1;
    }

    // Вычисление x1, x2, ..., xN по формуле Крамера
    for (int i = 0; i < N; i++) {
        float temp[MAX_SIZE][MAX_SIZE];
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                temp[j][k] = matrix[j][k];
            }
            temp[j][i] = b[j]; // Замена i-го столбца на b
        }
        // Вычисляем определитель матрицы temp
        float det_temp = (N == 2) ? determinant2x2(temp) : determinant3x3(temp);
        x[i] = det_temp / det; // Решение по формуле Крамера
    }

    // Вывод решений
    printf("Решение системы:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.2f\n", i + 1, x[i]);
    }

    return 0;
}

#5
#include <stdio.h>

void solveCramer(int n, float a[n][n], float b[n]) {
    float D = 0, Dx[n], Dy[n];
    
    // Вычисление определителя D
    for (int i = 0; i < n; i++) {
        D += (a[0][i] * (a[1][(i + 1) % n] * a[2][(i + 2) % n] - a[1][(i + 2) % n] * a[2][(i + 1) % n]));
    }

    for (int i = 0; i < n; i++) {
        // Замена столбца
        for (int j = 0; j < n; j++) {
            if (j == i) {
                Dx[j] = b[0];
            } else {
                Dx[j] = a[j][i];
            }
        }

        // Вычисление определителя Dx
        float Dx_val = 0;
        for (int j = 0; j < n; j++) {
            Dx_val += (Dx[0] * (Dx[1] * Dx[2] - Dx[1] * Dx[2]));
        }
        
        // Решение
        float x = Dx_val / D;
        printf("x%d = %f\n", i + 1, x);
    }
}

int main() {
    int n = 3; // Пример для 3x3 системы
    float a[3][3] = {{5, -3, 0}, {0, 0, 0}, {0, 0, 0}}; // Пример коэффициентов
    float b[3] = {7, 0, 0}; // Пример свободных членов

    solveCramer(n, a, b);
    return 0;
}

