#include <stdio.h>

void printMatrix(double matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

double determinant(double matrix[10][10], int n) {
    double det = 0;
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    double temp[10][10];
    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                temp[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(temp, n - 1);
    }
    return det;
}

void solveCramer(double matrix[10][10], double results[10], int n) {
    double detMain = determinant(matrix, n);
    if (detMain == 0) {
        printf("Система не имеет уникального решения.\n");
        return;
    }
    double x[10];
    for (int i = 0; i < n; i++) {
        double temp[10][10];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp[j][k] = matrix[j][k];
            }
        }
        for (int j = 0; j < n; j++) {
            temp[j][i] = results[j];
        }
        x[i] = determinant(temp, n) / detMain;
    }
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.2lf\n", i, x[i]);
    }
}

int main() {
    int n;
    printf("Введите размерность системы (N): ");
    scanf("%d", &n);
    double matrix[10][10], results[10];
    printf("Введите коэффициенты матрицы (NxN):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    printf("Введите свободные члены:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &results[i]);
    }
    solveCramer(matrix, results, n);
    return 0;
}
