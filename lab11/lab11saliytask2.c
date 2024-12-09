#include <stdio.h>

typedef struct
{
    char str[6];  // Увеличиваем размер массива для хранения 4 цифр и символа конца строки
    int num;
} NumberRepr;

void format(NumberRepr* number)
{
    sprintf(number->str, "%3d", number->num);
}

int main()
{
    NumberRepr number = { .num = 1025 };
    format(&number);
x    printf("str: %s\n", number.str);
    printf("num: %d\n", number.num);
    return 0;
}
