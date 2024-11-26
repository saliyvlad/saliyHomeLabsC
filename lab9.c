#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>


int manual(int N, int **matrix) {
    int element;
    int c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
                printf("Введите элемент: ");
                while (scanf("%d", &element) != 1) {
                while (!isspace(c = getchar()));
                ungetc(c, stdin);
                printf("Вам нужно ввести одно целое число.\n");
                continue;
                }
            
            matrix[i][j] = element;
        }
    }
    return 0;
}




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
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand()%11 ;
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

int select_mode(int n) {
    int mode=0;
    int c;
    int **matrix = (int **)malloc(n * sizeof(int *));
    int **rows = (int **)malloc(n * sizeof(int *));
    int **cols = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Выберите режим заполнения матрицы\n1) Режим заполнения вручную\n2) Режим случайной генерации\nВвод: ");
    
    while (scanf("%d", &mode) != 1 || !(mode==1 || mode==2)) {
        while (!isspace(c = getchar()));
        ungetc(c, stdin);
        printf("Вам нужно ввести 1 или 2\n");
        continue;
    }
    if (mode == 1) {
        manual(rows, matrix);
    } else if (mode == 2) {
        fillMatrixRandomly(matrix, rows, cols);
    } 

    printf("\nМатрица:\n");
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

int main() {
    int rows, cols,c,n=0;
    
    printf("Введите количество строк и столбцов матрицы: ");
    while (scanf("%d", &rows) != 1 || rows<=0) {
        while (!isspace(c = getchar()));
        ungetc(c,stdin);
        printf("Вам нужно ввести .одно целое число\n");
        continue;
    }
    cols = rows;
    select_mode(n);
    // Динамическое выделение памяти для матрицы
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Заполнение матрицы случайными числами
    fillMatrixRandomly(matrix, rows, cols);

    int minSwapsCol = -1;
    int minSwaps = rows * cols; // Максимально возможное количество перестановок

    // Упорядочиваем каждый столбец
    for (int col = 0; col < cols; col++) {
        int swaps = 0;
        sortColumn(matrix, rows, col, &swaps);
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
    printf("Измененная матрица\n");
    printMatrix(matrix, rows, cols);

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

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
