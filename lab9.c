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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int **matrix, int rows, int cols, int random);
void sortColumn(int **matrix, int rows, int col);
int countPositive(int **matrix, int rows, int col);
void replaceColumnWithZeros(int **matrix, int rows, int col);
void printMatrix(int **matrix, int rows, int cols);

int main() {
    int rows, cols, i, j;
    int random;

    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d %d", &rows, &cols);
    printf("Заполнить матрицу случайными числами? (1 - да, 0 - нет): ");
    scanf("%d", &random);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    fillMatrix(matrix, rows, cols, random);
    printf("Исходная матрица:\n");
    printMatrix(matrix, rows, cols);

    int minSwapsCol = 0;
    int minSwaps = rows * cols; // Начальное большое значение

    for (j = 0; j < cols; j++) {
        sortColumn(matrix, rows, j);
        int positiveCount = countPositive(matrix, rows, j);
        int swaps = countPositive(matrix, rows, j); // Подсчет перестановок (здесь нужно уточнить логику)
        
        if (swaps < minSwaps) {
            minSwaps = swaps;
            minSwapsCol = j;
        }
    }

    printf("Матрица после сортировки:\n");
    printMatrix(matrix, rows, cols);

    replaceColumnWithZeros(matrix, rows, minSwapsCol);
    printf("Матрица после замены столбца %d на нули:\n", minSwapsCol);
    printMatrix(matrix, rows, cols);

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void fillMatrix(int **matrix, int rows, int cols, int random) {
    if (random) {
        srand(time(NULL));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rand() % 100 - 50; // Числа от -50 до 49
            }
        }
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("Введите элемент [%d][%d]: ", i, j);
                scanf("%d", &matrix[i][j]);
            }
        }
    }
}

void sortColumn(int **matrix, int rows, int col) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (matrix[i][col] > matrix[j][col]) {
                int temp = matrix[i][col];
                matrix[i][col] = matrix[j][col];
                matrix[j][col] = temp;
            }
        }
    }
}

int countPositive(int **matrix, int rows, int col) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][col] > 0) {
            count++;
        }
    }
    return count;
}

void replaceColumnWithZeros(int **matrix, int rows, int col) {
    for (int i = 0; i < rows; i++) {
        matrix[i][col] = 0;
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int **matrix, int rows, int cols, int random);
void sortColumn(int **matrix, int rows, int col);
int countPositive(int **matrix, int rows, int col);
void replaceColumnWithZeros(int **matrix, int rows, int col);
void printMatrix(int **matrix, int rows, int cols);

int main() {
    int rows, cols, i, j;
    int random;

    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d %d", &rows, &cols);
    printf("Заполнить матрицу случайными числами? (1 - да, 0 - нет): ");
    scanf("%d", &random);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    fillMatrix(matrix, rows, cols, random);
    printf("Исходная матрица:\n");
    printMatrix(matrix, rows, cols);

    int minSwapsCol = 0;
    int minSwaps = rows * cols; // Начальное большое значение

    for (j = 0; j < cols; j++) {
        sortColumn(matrix, rows, j);
        int positiveCount = countPositive(matrix, rows, j);
        int swaps = countPositive(matrix, rows, j); // Подсчет перестановок (здесь нужно уточнить логику)
        
        if (swaps < minSwaps) {
            minSwaps = swaps;
            minSwapsCol = j;
        }
    }

    printf("Матрица после сортировки:\n");
    printMatrix(matrix, rows, cols);

    replaceColumnWithZeros(matrix, rows, minSwapsCol);
    printf("Матрица после замены столбца %d на нули:\n", minSwapsCol);
    printMatrix(matrix, rows, cols);

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void fillMatrix(int **matrix, int rows, int cols, int random) {
    if (random) {
        srand(time(NULL));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rand() % 100 - 50; // Числа от -50 до 49
            }
        }
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("Введите элемент [%d][%d]: ", i, j);
                scanf("%d", &matrix[i][j]);
            }
        }
    }
}

void sortColumn(int **matrix, int rows, int col) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (matrix[i][col] > matrix[j][col]) {
                int temp = matrix[i][col];
                matrix[i][col] = matrix[j][col];
                matrix[j][col] = temp;
            }
        }
    }
}

int countPositive(int **matrix, int rows, int col) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][col] > 0) {
            count++;
        }
    }
    return count;
}

void replaceColumnWithZeros(int **matrix, int rows, int col) {
    for (int i = 0; i < rows; i++) {
        matrix[i][col] = 0;
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
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
