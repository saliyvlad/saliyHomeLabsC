#include <stdio.h>

int main() {
    int N;
    
    // Запрашиваем у пользователя размер матрицы
    printf("Введите размер матрицы N: ");
    scanf("%d", &N);
    
    // Создаем матрицу NxN
    int matrix[100][100]; // Предположим, что максимальный размер N = 100
    int i, j;
    
    // Инициализируем переменные для отслеживания границ
    int top = 0;
    int bottom = N-1 ;
    int left = 0;
    int right = N-1 ;
    
    int num = 1; // Начальное значение для заполнения матрицы

    // Заполняем матрицу по спирали
    while (top <= bottom && left <= right) {
        // Заполняем верхнюю строку
        for (j = left; j <= right; j++) {
            matrix[top][j] = num++;
        }
        top++;

        // Заполняем правый столбец
        for (i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Заполняем нижнюю строку, если еще не переполнена
        if (top <= bottom) {
            for (j = right; j >= left; j--) {
                matrix[bottom][j] = num++;
            }
            bottom--;
        }

        // Заполняем левый столбец, если еще не переполнен
        if (left <= right) {
            for (i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    // Выводим заполненную матрицу
    printf("Заполненная матрица:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
