#include <stdio.h>

float determinant2x2(float a, float b, float c, float d) {
    return a * d - b * c;
}

float determinant3x3(float m[3][3]) {
    return m[0][0] * determinant2x2(m[1][1], m[1][2], m[2][1], m[2][2]) -
           m[0][1] * determinant2x2(m[1][0], m[1][2], m[2][0], m[2][2]) +
           m[0][2] * determinant2x2(m[1][0], m[1][1], m[2][0], m[2][1]);
}

void solve2x2(float a, float b, float c, float d, float e, float f) {
    float D = determinant2x2(a, b, c, d);
    if (D == 0) {
        printf("Нет единственного решения.\n");
        return;
    }
    float Dx = determinant2x2(e, b, f, d);
    float Dy = determinant2x2(a, e, c, f);
    printf("x = %.2f, y = %.2f\n", Dx / D, Dy / D);
}

void solve3x3(float m[3][3], float b[3]) {
    float D = determinant3x3(m);
    if (D == 0) {
        printf("Нет единственного решения.\n");
        return;
    }
    
    float Dx[3][3], Dy[3][3], Dz[3][3];

    // Заполнение матриц для Dx, Dy и Dz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Dx[i][j] = m[i][j];
            Dy[i][j] = m[i][j];
            Dz[i][j] = m[i][j];
        }
        Dx[i][0] = b[i]; // Замена первого столбца для Dx
        Dy[i][1] = b[i]; // Замена второго столбца для Dy
        Dz[i][2] = b[i]; // Замена третьего столбца для Dz
    }
    
    float x = determinant3x3(Dx) / D;
    float y = determinant3x3(Dy) / D;
    float z = determinant3x3(Dz) / D;
    
    printf("x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
}

int main() {
    // Пример для 2x2
    printf("Решение системы 2x2:\n");
    solve2x2(5, 2, 2, 1, 7, 9);

    // Пример для 3x3
    printf("Решение системы 3x3:\n");
    float matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    float b[3] = {5, 8, 2};
    solve3x3(matrix, b);

    return 0;
}
