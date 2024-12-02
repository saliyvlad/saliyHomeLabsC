#include <stdio.h>
#include "circle.h"

void initCircle(Circle* circle) {
    scanf("%f %f %f", &circle->x0, &circle->y0, &circle->R);
}

float calculateLength(Circle circle) {
    return 2 * 3.14159 * circle.R; // Используем число Пи
}

int intersectsXAxis(Circle circle) {
    return (circle.y0 - circle.R <= 0 && circle.y0 + circle.R >= 0);
}

int intersectsYAxis(Circle circle) {
    return (circle.x0 - circle.R <= 0 && circle.x0 + circle.R >= 0);
}
