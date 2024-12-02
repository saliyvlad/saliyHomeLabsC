#ifndef CIRCLE_H
#define CIRCLE_H

typedef struct {
    float x0; // Координата x центра
    float y0; // Координата y центра
    float R;  // Радиус
} Circle;

void initCircle(Circle* circle);
float calculateLength(Circle circle);
int intersectsXAxis(Circle circle);
int intersectsYAxis(Circle circle);

#endif // CIRCLE_H
