#include <stdio.h>
#include <stdlib.h>

int main() {
    int size; // Размер матрицы
    printf("Введите размер матрицы: ");
    scanf("%d", &size);

    // Динамическое выделение памяти для матрицы A
    int **A = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        A[i] = (int *)malloc(size * sizeof(int));
    }

    // Динамическое выделение памяти для массива B
    int *B = (int *)malloc(size * size * sizeof(int));
    int count = 0;
    int sum = 0;
    int num_elements = 0;

    // Ввод матрицы A
    printf("Введите элементы матрицы A:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &A[i][j]);
            sum += A[i][j]; // Сумма всех элементов для среднего
            num_elements++;

            // Элементы выше главной диагонали
            if (i < j) {
                B[count++] = A[i][j];
            }
            // Элементы выше побочной диагонали
            if (i + j < size - 1) {
                B[count++] = A[i][j];
            }
        }
    }

    // Определяем среднее значение
    double average = (double)sum / num_elements;

    // Подсчитываем количество элементов меньше среднего
    int less_than_average = 0;
    for (int i = 0; i < count; i++) {
        if (B[i] < average) {
            less_than_average++;
        }
    }

    // Упорядочиваем главную диагональ
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (A[i][i] > A[j][j]) {
                int temp = A[i][i];
                A[i][i] = A[j][j];
                A[j][j] = temp;
            }
        }
    }

    // Вывод результатов
    printf("Количество элементов массива B меньше среднего значения: %d\n", less_than_average);

    // Освобождение выделенной памяти
    for (int i = 0; i < size; i++) {
        free(A[i]);
    }
    free(A);
    free(B);

    return 0;
}
