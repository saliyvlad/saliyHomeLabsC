#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N_SMALL 100
#define N_MEDIUM 1000
#define N_LARGE 10000
#define NAME_SIZE 64
#define MAX_SCORE 100

// Структура Student
struct Student {
    char name[NAME_SIZE];
    int math;
    int phy;
    int inf;
    int total;
};

// Функция addStudent()
struct Student addStudent(const char* name, int math, int phy, int inf) {
    struct Student newStudent;
    strncpy(newStudent.name, name, NAME_SIZE - 1);
    newStudent.name[NAME_SIZE - 1] = '\0'; // Гарантируем нулевой символ
    newStudent.math = math;
    newStudent.phy = phy;
    newStudent.inf = inf;
    newStudent.total = math + phy + inf;
    return newStudent;
}

// Функция printStudentInfo()
void printStudentInfo(struct Student student) {
    printf("Имя: %s\n", student.name);
    printf("Математика: %d\n", student.math);
    printf("Физика: %d\n", student.phy);
    printf("Информатика: %d\n", student.inf);
    printf("Общий балл: %d\n", student.total);
    printf("------------------------\n");
}

// Вспомогательная функция для обмена элементов
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// 8) Реализация QuickSort

// Функция для разбиения массива (partition)
int partition(struct Student arr[], int low, int high) {
    int pivot = arr[high].total; // Выбираем последний элемент в качестве опорного
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].total > pivot) { // Сортировка по убыванию
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Рекурсивная функция QuickSort
void quickSort(struct Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 10), 11) Функция для измерения времени сортировки (clock())
double measureSortingTime(struct Student arr[], int n, void (*sort_func)(struct Student[], int, int)) {
    clock_t start_time, end_time;
    double elapsed_time;

    start_time = clock(); // Запускаем таймер

    sort_func(arr, 0, n - 1); // Вызываем функцию сортировки

    end_time = clock(); // Останавливаем таймер

    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    return elapsed_time;
}


// 9) Получение информации о процессоре (убрано)
//  printProcessorInfo() удалена для упрощения кода.

int main() {

    // Используем динамическое выделение памяти
    struct Student *students_small = (struct Student*)malloc(N_SMALL * sizeof(struct Student));
    struct Student *students_medium = (struct Student*)malloc(N_MEDIUM * sizeof(struct Student));
    struct Student *students_large = (struct Student*)malloc(N_LARGE * sizeof(struct Student));

    if (!students_small || !students_medium || !students_large) {
        perror("Ошибка выделения памяти");
        return 1;
    }

    srand(time(NULL));

    // Заполнение массивов студентов для разных размеров
    for (int i = 0; i < N_SMALL; i++) {
        char name[NAME_SIZE];
        sprintf(name, "Студент%d", i + 1);
        int math = rand() % (MAX_SCORE + 1);
        int phy = rand() % (MAX_SCORE + 1);
        int inf = rand() % (MAX_SCORE + 1);
        students_small[i] = addStudent(name, math, phy, inf);
    }

    for (int i = 0; i < N_MEDIUM; i++) {
        char name[NAME_SIZE];
        sprintf(name, "Студент%d", i + 1);
        int math = rand() % (MAX_SCORE + 1);
        int phy = rand() % (MAX_SCORE + 1);
        int inf = rand() % (MAX_SCORE + 1);
        students_medium[i] = addStudent(name, math, phy, inf);
    }

    for (int i = 0; i < N_LARGE; i++) {
        char name[NAME_SIZE];
        sprintf(name, "Студент%d", i + 1);
        int math = rand() % (MAX_SCORE + 1);
        int phy = rand() % (MAX_SCORE + 1);
        int inf = rand() % (MAX_SCORE + 1);
        students_large[i] = addStudent(name, math, phy, inf);
    }


    // 10), 11) Измерение времени и вывод результатов

    // Маленький набор данных
    double time_small = measureSortingTime(students_small, N_SMALL, quickSort);
    printf("\nВремя сортировки quickSort для N = %d: %f секунд\n", N_SMALL, time_small);

    // Средний набор данных
    double time_medium = measureSortingTime(students_medium, N_MEDIUM, quickSort);
    printf("Время сортировки quickSort для N = %d: %f секунд\n", N_MEDIUM, time_medium);

    // Большой набор данных
    double time_large = measureSortingTime(students_large, N_LARGE, quickSort);
    printf("Время сортировки quickSort для N = %d: %f секунд\n", N_LARGE, time_large);


    printf("\nРазмер структуры Student: %zu байт\n", sizeof(struct Student));

    // Освобождаем выделенную память
    free(students_small);
    free(students_medium);
    free(students_large);

    return 0;
}
