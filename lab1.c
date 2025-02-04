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
    strncpy(newStudent.name, name, 64);
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

int main() {
    struct Student students[N];
    const char *names[N] = {
        "Иван", "Мария", "Петр", "Анастасия", "Дмитрий",
        "Елена", "Сергей", "Татьяна", "Алексей", "Юлия",
        // Добавить ещё имена для большей случайности
    };

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
