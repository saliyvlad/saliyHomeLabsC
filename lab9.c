#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>

void fillMatrix(int **matrix, int rows, int cols, int random);
void sortColumn(int **matrix, int rows, int col);
int countPositive(int **matrix, int rows, int col);
void replaceColumnWithZeros(int **matrix, int rows, int col);
void printMatrix(int **matrix, int rows, int cols);

int main() {
    int rows, cols, i, j;
    int random,c;

    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d %d", &rows, &cols);
    
    printf("Выберите режим заполнения матрицы\n0) Режим заполнения вручную\n1) Режим случайной генерации\nВвод: ");

    while (scanf("%d", &random) != 1 || !(random==1 || random==0)) {
        while (!isspace(c = getchar()));
        ungetc(c, stdin);
        printf("Вам нужно ввести 1 или 0\n");
        continue;
    }

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    fillMatrix(matrix, rows, cols, random);
    printf("Исходная матрица:\n");
    printMatrix(matrix, rows, cols);

    int minSwapsCol = 0;
    int minSwaps = rows * cols; 

    for (j = 0; j < cols; j++) {
        sortColumn(matrix, rows, j);
        int positiveCount = countPositive(matrix, rows, j);
        int swaps = countPositive(matrix, rows, j); 
        
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
    int c;
    if (random) {
        srand(time(NULL));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rand() % 11;
            }
        }
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("Введите элемент [%d][%d]: ", i, j);
                
                while (scanf("%d", &matrix[i][j]) != 1) {
                while (!isspace(c = getchar()));
                ungetc(c, stdin);
                printf("Вам нужно ввести одно целое число.\n");
                continue;
                }
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
