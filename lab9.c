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






#include <stdio.h>
#include <stdlib.h>

void createArrayB(int **A, int n, int **B, int *sizeB) {
    *sizeB = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j && i + j < n - 1) { // Элементы выше главной и побочной диагоналей
                B[*sizeB] = A[i][j];
                (*sizeB)++;
            }
        }
    }
}

double calculateAverage(int **A, int n) {
    double sum = 0;
    int count = n * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += A[i][j];
        }
    }
    return sum / count;
}

int countLessThanAverage(int *B, int sizeB, double average) {
    int count = 0;
    for (int i = 0; i < sizeB; i++) {
        if (B[i] < average) {
            count++;
        }
    }
    return count;
}

void sortMainDiagonal(int **A, int n) {
    int *diagonal = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        diagonal[i] = A[i][i];
    }
    
    // Сортировка (например, пузырьком)
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (diagonal[j] > diagonal[j+1]) {
                int temp = diagonal[j];
                diagonal[j] = diagonal[j+1];
                diagonal[j+1] = temp;
            }
        }
    }
    
    // Запись отсортированной диагонали обратно в матрицу
    for (int i = 0; i < n; i++) {
        A[i][i] = diagonal[i];
    }
    
    free(diagonal);
}

int main() {
    int n = 4; // Размерность матрицы
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }
    
    // Пример заполнения матрицы A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j; // Можно использовать любое заполнение
        }
    }

    int *B = (int *)malloc(n * n * sizeof(int));
    int sizeB;
    createArrayB(A, n, &B, &sizeB);
    
    double average = calculateAverage(A, n);
    int count = countLessThanAverage(B, sizeB, average);
    
    sortMainDiagonal(A, n);

    // Освобождение памяти
    free(B);
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    printf("Количество элементов массива B меньше среднего значения: %d\n", count);
    
    return 0;
}





#include <stdio.h>
#include <stdlib.h>

void createArrayB(int **A, int n, int **B, int *sizeB) {
    *sizeB = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j && i + j < n) { // Элементы выше главной и побочной диагоналей
                B[*sizeB] = A[i][j];
                (*sizeB)++;
            }
        }
    }
}

double calculateAverage(int **A, int n) {
    double sum = 0;
    int count = n * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += A[i][j];
        }
    }
    return sum / count;
}

int countLessThanAverage(int *B, int sizeB, double average) {
    int count = 0;
    for (int i = 0; i < sizeB; i++) {
        if (B[i] < average) {
            count++;
        }
    }
    return count;
}

void sortMainDiagonal(int **A, int n) {
    int *diagonal = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        diagonal[i] = A[i][i];
    }
    
    // Сортировка (например, пузырьком)
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (diagonal[j] > diagonal[j+1]) {
                int temp = diagonal[j];
                diagonal[j] = diagonal[j+1];
                diagonal[j+1] = temp;
            }
        }
    }
    
    // Запись отсортированной диагонали обратно в матрицу
    for (int i = 0; i < n; i++) {
        A[i][i] = diagonal[i];
    }
    
    free(diagonal);
}

int main() {
    int n = 4; // Размерность матрицы
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }
    
    // Пример заполнения матрицы A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j; // Можно использовать любое заполнение
        }
    }

    int *B = (int *)malloc(n * n * sizeof(int));
    int sizeB;
    createArrayB(A, n, &B, &sizeB);
    
    double average = calculateAverage(A, n);
    int count = countLessThanAverage(B, sizeB, average);
    
    sortMainDiagonal(A, n);

    // Освобождение памяти
    free(B);
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    printf("Количество элементов массива B меньше среднего значения: %d\n", count);
    
    return 0;
}







lab9saliy.c: In function ‘createArrayB’:
lab9saliy.c:9:27: warning: assignment to ‘int *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]
    9 |                 B[*sizeB] = A[i][j];
      |                           ^
















#include <stdio.h>
#include <stdlib.h>

void createArrayB(int **A, int n, int **B, int *sizeB) {
    *sizeB = 0;
    // Изначально выделяем память для массива B
    *B = (int *)malloc(n * n * sizeof(int)); // Максимально возможный размер
    if (*B == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j && i + j < n) { // Элементы выше главной и побочной диагоналей
                (*B)[*sizeB] = A[i][j]; // Записываем значение в массив B
                (*sizeB)++;
            }
        }
    }
}

double calculateAverage(int **A, int n) {
    double sum = 0;
    int count = n * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += A[i][j];
        }
    }
    return sum / count;
}

int countLessThanAverage(int *B, int sizeB, double average) {
    int count = 0;
    for (int i = 0; i < sizeB; i++) {
        if (B[i] < average) {
            count++;
        }
    }
    return count;
}

void sortMainDiagonal(int **A, int n) {
    int *diagonal = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        diagonal[i] = A[i][i];
    }
    
    // Сортировка (например, пузырьком)
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (diagonal[j] > diagonal[j+1]) {
                int temp = diagonal[j];
                diagonal[j] = diagonal[j+1];
                diagonal[j+1] = temp;
            }
        }
    }
    
    // Запись отсортированной диагонали обратно в матрицу
    for (int i = 0; i < n; i++) {
        A[i][i] = diagonal[i];
    }
    
    free(diagonal);
}

int main() {
    int n = 4; // Размерность матрицы
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }
    
    // Пример заполнения матрицы A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j; // Можно использовать любое заполнение
        }
    }

    int *B = NULL; // Объявляем указатель на массив B
    int sizeB;
    createArrayB(A, n, &B, &sizeB);
    
    double average = calculateAverage(A, n);
    int count = countLessThanAverage(B, sizeB, average);
    
    sortMainDiagonal(A, n);

    // Освобождение памяти
    free(B);
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    printf("Количество элементов массива B меньше среднего значения: %d\n", count);
    
    return 0;
}












#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortColumn(int **matrix, int rows, int col, int *swaps) {
    // Сортировка столбца с подсчетом перестановок
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (matrix[j][col] < matrix[i][col]) {
                // Обмен элементов
                int temp = matrix[i][col];
                matrix[i][col] = matrix[j][col];
                matrix[j][col] = temp;
                (*swaps)++;  // Увеличиваем счетчик перестановок
            }
        }
    }
}

int countPositiveInColumn(int **matrix, int rows, int col) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][col] > 0) {
            count++;
        }
    }
    return count;
}

void fillMatrixRandomly(int **matrix, int rows, int cols) {
    srand(time(NULL)); // Инициализация генератора случайных чисел
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 101 - 50; // Заполнение случайными числами от -50 до 50
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    printf("Матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d %d", &rows, &cols);

    // Динамическое выделение памяти для матрицы
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Заполнение матрицы случайными числами
    fillMatrixRandomly(matrix, rows, cols);
    
    // Вывод исходной матрицы
    printMatrix(matrix, rows, cols);

    int minSwapsCol = -1;
    int minSwaps = rows * cols; // Максимально возможное количество перестановок

    // Упорядочиваем каждый столбец
    for (int col = 0; col < cols; col++) {
        int swaps = 0;

        // Сортируем столбец и подсчитываем количество перестановок
        sortColumn(matrix, rows, col, &swaps);

        // Если текущее количество перестановок меньше минимального, обновляем
        if (swaps < minSwaps) {
            minSwaps = swaps;
            minSwapsCol = col;
        }
    }

    // Подсчет положительных элементов в столбце с минимальным количеством перестановок
    if (minSwapsCol != -1) {
        int positiveCount = countPositiveInColumn(matrix, rows, minSwapsCol);
        printf("Количество положительных элементов в столбце %d: %d\n", minSwapsCol + 1, positiveCount);

        // Заменяем элементы этого столбца на нули
        for (int i = 0; i < rows; i++) {
            matrix[i][minSwapsCol] = 0;
        }
    }

    // Вывод измененной матрицы
    printf("Измененная матрица:\n");
    printMatrix(matrix, rows, cols);

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}


