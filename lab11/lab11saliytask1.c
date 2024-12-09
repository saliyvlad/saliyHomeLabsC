#include <stdio.h>
#include <stdlib.h>

void init(int** arr, int n)
{
    *arr = malloc(n * sizeof(int));  // выделяем память и присваиваем указателю
    int i;
    for (i = 0; i < n; ++i) {
        (*arr)[i] = i;  // изменяем значение через указатель на указатель
    }
}

int main()
{
    int* arr = NULL;
    int n = 10;
    init(&arr, n);  // передаем адрес указателя
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    free(arr);  // освобождаем выделенную память
    return 0;
}
