oo#include <stdio.h>

#define MAX_NUMBERS 100000

int main() {
    char input[1000]; // Ввод строки
    int numbers[MAX_NUMBERS]; // Массив для хранения чисел
    int count = 0; // Счетчик чисел

    // Считываем строку
    printf("Введите интервал: ");
    scanf("%[^\n]", input);

    int i = 0;
    while (input[i] != '\0') {
        int start = 0;
        int end = 0;

        // Считываем начальное число
        while (input[i] >= '0' && input[i] <= '9') {
            start = start * 10 + (input[i] - '0');
            i++;
        }

        // Проверяем, есть ли дефис (интервал)
        if (input[i] == '-') {
            i++; // Пропускаем дефис

            // Считываем конечное число
            while (input[i] >= '0' && input[i] <= '9') {
                end = end * 10 + (input[i] - '0');
                i++;
            }

            // Заполняем массив числами в интервале
            for (int j = start; j <= end; j++) {
                numbers[count++] = j;
            }
        } else {
            // Если это не интервал, просто добавляем число
            numbers[count++] = start;
        }

        // Пропускаем запятую и пробел
        while (input[i] == ',' || input[i] == ' ') {
            i++;
        }
    }

    // Сортируем массив чисел (простой алгоритм сортировки)
    for (int j = 0; j < count - 1; j++) {
        for (int k = 0; k < count - j - 1; k++) {
            if (numbers[k] > numbers[k + 1]) {
                int temp = numbers[k];
                numbers[k] = numbers[k + 1];
                numbers[k + 1] = temp;
            }
        }
    }

    // Выводим результат
    for (int j = 0; j < count; j++) {
        printf("%d ", numbers[j]);
    }
    printf("\n");

    return 0;
}
