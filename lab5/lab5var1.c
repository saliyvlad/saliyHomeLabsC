#include <stdio.h>

void count_bits(unsigned int a, int *zero_count, int *one_count) {
    *zero_count = 0;
    *one_count = 0;

    for (int i = 0; i < sizeof(a) * 8; i++) { // Проходим по всем битам
        if (a & (1 << i)) { // Проверка, установлен ли i-й бит
            (*one_count)++;
        } else {
            (*zero_count)++;
        }
    }
}

int main() {
    unsigned int a;
    int zero_count, one_count;

    printf("Введите неотрицательное число: ");
    scanf("%u", &a);

    count_bits(a, &zero_count, &one_count);

    printf("Количество единичных битов: %d\n", one_count);
    printf("Количество нулевых битов: %d\n", zero_count);

    return 0;
}
