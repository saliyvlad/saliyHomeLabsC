// #include<stdio.h>
// int main(){
// int A[10]={1,2,-3,4,-32,27,49,-9,-5,0};
// int B[10]={6,-4,-8,6,1,-22,4,-4,8,6};
// int C[10]={0};
// for (int i = 0; i<10; i++){
//     C[i]=A[i]+B[i];
//     printf(" %d", C[i]);
// }
// int max = 0;
// int count = 0;
// for (int i = 0; i<10; i=i+2){
//     if (A[i]>max){
//         max= A[i];
//     }
//     if (B[i+1]<0){
//         count++;
//     }
// }
// int summ = 0;
// for (int i=0; i<10; i++){
//     summ+=C[i];
// }
// printf("\nМаксимальное из реальных А:\n%d",max);
// printf("\nКоличепство отрицательных в мнимых В:\n%d",count);
// printf("\nСреднее всех элементов С:\n%d",summ/10);
// }

// //МОЕ РЕШЕНИЕ
// #include <stdio.h>

// #define SIZE 3 // Размер массивов A и B

// int main() {
//     // 1. Создаем массивы A и B
//     float A[SIZE * 2] = {1.0, 2.0, 3.0, -1.0, 4.0, 0.5}; // Пример значений для A
//     float B[SIZE * 2] = {2.0, -3.0, 1.0, 2.5, 0.0, -4.0}; // Пример значений для B
//     float C[SIZE * 2]; // Массив для хранения суммы

//     // 2. Сложение A и B в C
//     for (int i = 0; i < SIZE * 2; i++) {
//         C[i] = A[i] + B[i];
//     }

//     // 3. Нахождение максимальной реальной части в A
//     float max_real_A = A[0];
//     int count_imag_B_negative = 0;

//     for (int i = 0; i < SIZE; i++) {
//         // Проверяем реальную часть
//         if (A[i * 2] > max_real_A) {
//             max_real_A = A[i * 2];
//         }
//         // Проверяем мнимую часть B
//         if (B[i * 2 + 1] < 0) {
//             count_imag_B_negative++;
//         }
//     }

//     printf("Максимальная реальная часть массива A: %.2f\n", max_real_A);
//     printf("Количество мнимых частей, которые меньше 0 в массиве B: %d\n", count_imag_B_negative);

//     // 4. Вычисление среднего арифметического элементов массива C
//     float sum_C = 0;
//     for (int i = 0; i < SIZE * 2; i++) {
//         sum_C += C[i];
//     }
//     float average_C = sum_C / (SIZE * 2);
//     printf("Среднее арифметическое элементов массива C: %.2f\n", average_C);

//     return 0;
// }
// #НА 5
// #include <stdio.h>

// int is_prime(int num) {
//     if (num < 2) return 0;
//     for (int i = 2; i * i <= num; i++) {
//         if (num % i == 0) return 0;
//     }
//     return 1;
// }

// int is_perfect(int num) {
//     int sum = 0;
//     for (int i = 1; i < num; i++) {
//         if (num % i == 0) sum += i;
//     }
//     return sum == num;
// }

// void process_array(int arr[], int size) {
//     int last_prime_index = -1, first_perfect_index = -1;

//     for (int i = 0; i < size; i++) {
//         if (is_prime(arr[i])) {
//             last_prime_index = i;
//         }
//         if (first_perfect_index == -1 && is_perfect(arr[i])) {
//             first_perfect_index = i;
//         }
//     }

//     if (last_prime_index != -1 && first_perfect_index != -1) {
//         int temp = arr[last_prime_index];
//         arr[last_prime_index] = arr[first_perfect_index];
//         arr[first_perfect_index] = temp;
//     }

//     // Удаление четных чисел
//     for (int i = 0; i < size; i++) {
//         if (arr[i] % 2 == 0) {
//             for (int j = i; j < size - 1; j++) {
//                 arr[j] = arr[j + 1];
//             }
//             size--;
//             i--; // Проверяем текущую позицию снова
//         }
//     }

//     // Вывод массива
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
// }

// int main() {
//     int X[] = {1, 2, 3, 4, 5, 6, 28}; // Пример массива
//     int size = sizeof(X) / sizeof(X[0]);
//     process_array(X, size);
//     return 0;
// }





// #include <stdio.h>

// int is_prime(int n) {
//     if (n <= 1) return 0;
//     for (int i = 2; i*i <= n; i++) {
//         if (n % i == 0) return 0;
//     }
//     return 1;
// }

// int is_perfect(int n) {
//     if (n <= 1) return 0;
//     int sum = 0;
//     for (int i = 1; i < n; i++) {
//         if (n % i == 0) {
//             sum += i;
//         }
//     }
//     return sum == n;
// }

// int main() {
//     int X[] = {6, 28, 4, 5, 9, 15, 21, 12, 3, 10};
//     int size = sizeof(X) / sizeof(X[0]);
//     int last_prime_index = -1;
//     int first_perfect_index = -1;

//     // Поиск последнего простого и первого совершенного числа
//     for (int i = 0; i < size; i++) {
//         if (is_prime(X[i])) {
//             last_prime_index = i; // обновляем индекс последнего простого
//         }
//         if (is_perfect(X[i]) && first_perfect_index == -1) {
//             first_perfect_index = i; // сохраняем индекс первого совершенного
//         }
//     }

//     // Обмен местами последнего простого и первого совершенного
//     if (last_prime_index != -1 && first_perfect_index != -1) {
//         int temp = X[last_prime_index];
//         X[last_prime_index] = X[first_perfect_index];
//         X[first_perfect_index] = temp;
//     }

//     // Удаление четных чисел
//     int new_size = 0;
//     int new_X[size]; // новый массив для хранения нечетных чисел

//     for (int i = 0; i < size; i++) {
//         if (X[i] % 2 != 0) {
//             new_X[new_size] = X[i];
//             new_size++;
//         }
//     }

//     // Вывод результата
//     printf("Результат: ");
//     for (int i = 0; i < new_size; i++) {
//         printf("%d ", new_X[i]);
//     }
//     printf("\n");

//     return 0;
// }






