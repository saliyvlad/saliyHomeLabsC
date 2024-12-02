#include <stdio.h>
#include "circle.h"

int main() {
    int N;
    printf("Введите количество окружностей: ");
    scanf("%d", &N);

    Circle circles[N];

    for (int i = 0; i < N; i++) {
        printf("Введите координаты центра (x0, y0) и радиус (R) для окружности %d: ", i + 1);
        initCircle(&circles[i]);
    }

    for (int i = 0; i < N; i++) {
        float length = calculateLength(circles[i]);
        printf("Длина окружности %d: %.2f\n", i + 1, length);

        if (intersectsXAxis(circles[i])) {
            printf("Окружность %d пересекает ось OX.\n", i + 1);
        } else {
            printf("Окружность %d не пересекает ось OX.\n", i + 1);
        }

        if (intersectsYAxis(circles[i])) {
            printf("Окружность %d пересекает ось OY.\n", i + 1);
        } else {
            printf("Окружность %d не пересекает ось OY.\n", i + 1);
        }
    }

    return 0;
}
