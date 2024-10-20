#include <stdio.h>

void printHexadecimal(unsigned int a) {
    // Массив для хранения шестнадцатеричных символов
    char hexDigits[] = "0123456789ABCDEF";
    
    // Переменная для хранения результата
    char hexResult[9]; // 8 символов + 1 для нуль-терминатора
    int index = 0;

    // Обрабатываем число, извлекая тетрады
    while (a > 0) {
        // Извлекаем последние 4 бита
        int nibble = a & 0xF; // 0xF = 1111 в двоичной системе
        hexResult[index++] = hexDigits[nibble]; // Сохраняем соответствующий символ
        a >>= 4; // Сдвигаем число вправо на 4 бита
    }

    // Печатаем результат в обратном порядке
    printf("Шестнадцатеричное представление: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hexResult[i]);//вывод одиночного символа, без перехода на новую строку
    }
    putchar('\n');
}

int main() {
    unsigned int a;

    printf("Введите целое положительное число: ");
    scanf("%u", &a);

    if (a > 0) {
        printHexadecimal(a);
    } else {
        printf("Число должно быть больше 0.\n");
    }

    return 0;
}
