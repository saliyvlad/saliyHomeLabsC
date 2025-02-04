Если ваш код вызывает ошибку "Segmentation fault", это может быть связано с несколькими причинами. Ниже приведен обновленный и более безопасный вариант программы, который избегает потенциальных проблем.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct Student {
    char name[64];
    int math;
    int phy;
    int inf;
    int total;
};

struct Student addStudent(const char *name, int math, int phy, int inf) {
    struct Student newStudent;
    strncpy(newStudent.name, name, sizeof(newStudent.name) - 1);
    newStudent.name[sizeof(newStudent.name) - 1] = '\0'; // Гарантируем, что строка будет нуль-терминирована
    newStudent.math = math;
    newStudent.phy = phy;
    newStudent.inf = inf;
    newStudent.total = math + phy + inf;
    return newStudent;
}

void printStudentInfo(struct Student student) {
    printf("Имя: %s\n", student.name);
    printf("Оценка по математике: %d\n", student.math);
    printf("Оценка по физике: %d\n", student.phy);
    printf("Оценка по информатике: %d\n", student.inf);
    printf("Общий балл: %d\n\n", student.total);
}

void insertionSort(struct Student students[], int n) {
    for (int i = 1; i < n; i++) {
        struct Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].total < key.total) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

const char *names[] = {
    "Иван", "Мария", "Петр", "Анастасия", "Дмитрий",
    "Елена", "Сергей", "Татьяна", "Алексей", "Юлия"
};

int main() {
    struct Student students[N];
    srand((unsigned int)time(NULL)); // Инициализация генератора случайных чисел

    // Заполнение массивов случайными данными
    for (int i = 0; i < N; i++) {
        const char *name = names[rand() % (sizeof(names) / sizeof(names[0]))];
        int math = rand() % 101;
        int phy = rand() % 101;
        int inf = rand() % 101;
        students[i] = addStudent(name, math, phy, inf);
    }

    printf("Список студентов до сортировки:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    // Сортировка
    insertionSort(students, N);

    printf("Список студентов после сортировки:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    return 0;
}


### Основные изменения:
1. Устранение проблемы с буфером: Использование sizeof(newStudent.name) - 1 при копировании строки, чтобы избежать переполнения.
2. Установка завершающего нуля: Добавил явное присвоение нулевого символа в конец строки newStudent.name, чтобы гарантировать ее корректное завершение.
3. Инициализация генератора случайных чисел: Добавлено srand((unsigned int)time(NULL)); для генерации различных случайных чисел при каждом запуске программы.

Попробуйте запустить обновленный код и проверьте, исчезла ли ошибка.
