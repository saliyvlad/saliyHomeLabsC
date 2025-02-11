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


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n=10;
int A[10];
int N=100;
int B[100];

// // Функция для сортировки выбором (SelectSort)
void selectionSort(int n, int A[n]) {
    int C=0;
    int M=0;
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            C++;
            if (A[j] < A[k]) { 
                k = j;
            }
        }
        if(A[i]!=A[k]){ // защита от фиктивности
            M++;
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
        }
    } 
    printf("Число сравнений:%d\n",C);
    printf("Число перемещений:%d\n",M);
    printf("Трудоемкость:%d\n",M+C);
}
void FillInc(int n, int A[n]){
    int i=0;
    while(n!= -1){
        A[i]=i+1;
        i+=1;
	n-=1;
    }
}

void FillDec(int n, int A[n]){
    int i=0;
    while(n!= -1){
        A[n]=i;
        i+=1;
	n-=1;
    }
}
void FillRand(int n, int A[n]){
    srand(time(NULL));
    int i=0;
    while(n!= -1){
        A[n]=rand()%100;
        n-=1;
    }
}

int CheckSum(int n, int A[n]){
    int i=0;
    while(n!=-1){
        i+=A[n-1];
        n-=1;
    }
    return i;
}

int RunNumber(int n, int A[n]){
    int i=0;
    n=0;
    while(n!= 10){
        if(A[n]>A[n+1]&& n!=10){
            i+=1;
        }
	    if (n == 9 && i == 0) {
            i+=1;
        }
        n+=1;
    }
    return i;
}

int RunNumber100(int n, int A[n]){
    int i=0;
    n=0;
    while(n!= 100){
        if(A[n]>A[n+1]&& n!=100){
            i+=1;
        }
	    if (n == 99 && i == 0) {
            i+=1;
        }
        n+=1;
    }
    return i;
}

void PrintMas(int n, int A[n]){
    int i=0;
    while(i!=10){
        printf("%d ",A[i]);
        i+=1;
    }
}
void PrintMas100(int n, int A[n]){
    int i=0;
    while(i!=100){
        printf("%d ",A[i]);
        i+=1;
    }
}
void RunNumberAv(int n, int A[n]){
    int i=0,c=0;
    int sum=0;
    int B[10];
    while(n!= 0){
        if(A[n]<A[n+1]){
            i+=1;
        }
	else{
            sum +=1;
        }
	B[n]=sum;
        n-=1;
    }
    n=10;
    while(n!= -1){
        c+=B[n];
        n-=1;
    }

    printf("%fсреднее..\n",c/i);
}
int main(){ 

    printf("==========================================================================");
    printf("\nдля случайного\n");
    FillRand(n, A);
    PrintMas(n,A);
    CheckSum(n,A);
    RunNumber(n,A);
    selectionSort(n, A);     
    printf("Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber(n, A), CheckSum(n, A));

    printf("\nдля убывающего\n");
    FillDec(n,A);
    PrintMas(n,A);
    CheckSum(n,A);
    RunNumber(n,A);
    selectionSort(n, A);     
    printf("Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber(n, A), CheckSum(n, A));

    printf("\nдля Возрастающего\n");
    FillInc(n,A);
    PrintMas(n,A);
    CheckSum(n,A);
    RunNumber(n,A);
    selectionSort(n, A);     
    printf("Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber(n, A), CheckSum(n, A));

    printf("==========================================================================");

    printf("\nдля случайного\n");
    FillRand(N, B);
    printf("Исходн. Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber100(N, B), CheckSum(N, B));
    selectionSort(N, B); 
    printf("\nУлучш. Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber100(N, B), CheckSum(N, B));

    printf("\nдля убывающего\n");
    FillDec(N, B);
    printf("Исходн. Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber100(N, B), CheckSum(N, B));
    selectionSort(N, B);
    printf("\nУлучш. Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber100(N, B), CheckSum(N, B));

    printf("\nдля Возрастающего\n");
    FillInc(N,B);
    printf("Исходн. Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber100(N, B), CheckSum(N, B));
    selectionSort(N, B); 
    printf("\nУлучш. Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber100(N, B), CheckSum(N, B));

    printf("==========================================================================");

    printf("N M(т.)+C(т.) Исходный M(ф)+C(ф) Улучшенный М(ф)+С(ф)");
    printf("%dd")

}
// ====================================================================================

