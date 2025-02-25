#include <stdio.h>
#include <stdlib.h>

// Оценка 3, пункт 1: Структура узла
typedef struct node {
    int data;
    struct node *next;
    struct node *prev; // Оценка 4, пункт 4: Указатель на предыдущий узел
} Node;

// Функция для добавления узла в конец списка (обратный порядок)
Node* addNodeToEnd(Node *head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL; // Оценка 4, пункт 4: Инициализация prev

    if (head == NULL) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current; // Оценка 4, пункт 4: Установка prev
    }
    return head;
}

// Функция для вывода списка
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Оценка 5: Функция для присоединения одного списка к другому
Node* connectLists(Node* list1Head, Node* list2Head) {
    // Находим конец первого списка
    Node* current = list1Head;
    if (current == NULL) return list2Head; //если первый список пустой, просто возвращаем второй
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = list2Head; // Присоединяем второй список к первому

    // Проставляем prev для элементов второго списка
    current = list2Head;
    while(current != NULL) {
        current->prev = current == list2Head ? list1Head : current->prev;
        current = current->next;
    }

     return list1Head; // Возвращаем голову первого списка

}

//Функция освобождения памяти, выделенной под список
void freeList(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    int data, n, i;

    // Оценка 3, пункт 3: Создание списка 1 из n элементов
    printf("Введите количество элементов для первого списка (N): ");
    scanf("%d", &n);
    printf("Введите элементы первого списка, разделенные пробелами (введите 0 для завершения):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        if (data == 0) break;
        head1 = addNodeToEnd(head1, data); // Добавление в конец, список "обратный"
    }

    printf("Первый список:\n");
    printList(head1);

    // Оценка 5: Создание списка 2 из k элементов
    printf("Введите количество элементов для второго списка (K): ");
    scanf("%d", &n);
    printf("Введите элементы второго списка, разделенные пробелами (введите 0 для завершения):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        if (data == 0) break;
        head2 = addNodeToEnd(head2, data); // Добавление в конец, список "обратный"
    }

    printf("Второй список:\n");
    printList(head2);

    // Оценка 5: Присоединение списков
    Node* combinedHead = connectLists(head1, head2);
    printf("Объединенный список:\n");
    printList(combinedHead);

    // Оценка 6: Интерфейс управления списком (упрощенная версия WASD)
    Node *current = combinedHead;
    char command;

    printf("\nУправление списком: (S - начало, D - вперед, A - назад, Q - выход)\n");

    do {
        printf("Текущее значение: ");
        if (current != NULL) {
            printf("%d\n", current->data);
        } else {
            printf("NULL (конец списка)\n");
        }

        printf("Введите команду: ");
        scanf(" %c", &command); // Важно: пробел перед %c, чтобы считать символ новой строки

        switch (command) {
            case 'S': // Начало
            case 's':
                current = combinedHead;
                break;
            case 'D': // Вперед
            case 'd':
            case '6':
                if (current != NULL && current->next != NULL) {
                    current = current->next;
                } else {
                    printf("Достигнут конец списка. Возврат в начало.\n");
                    current = combinedHead;
                }
                break;
            case 'A': // Назад
            case 'a':
            case '4':
                if (current != NULL && current->prev != NULL) {
                    current = current->prev;
                } else {
                    printf("Достигнуто начало списка.\n");
                }
                break;
            case 'Q': // Выход
            case 'q':
                printf("Выход из программы.\n");
                break;
            default:
                printf("Неизвестная команда.\n");
        }
    } while (command != 'Q' && command != 'q');

    // Освобождаем память
    freeList(combinedHead); // Используем freeList чтобы избежать утечек памяти
    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Для toupper

// Структура узла списка
struct Node {
    int data;
    struct Node* next;  // Указатель на следующий узел
    struct Node* down;  // Указатель на дополнительный узел (для оценки 4 и 5)
};

// Функция добавления узла в конец списка
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE); // Очень важно проверять результат malloc
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->down = NULL;  //ВАЖНО ИНИЦИАЛИЗИРОВАТЬ

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}


// Функция вывода списка на экран
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// Функция создания списка из ввода пользователя
struct Node* createList() {
    struct Node* head = NULL;
    int data;
    printf("Введите значения, 0 для окончания: ");
    while (scanf("%d", &data) == 1 && data != 0) { //scanf возвращает кол-во успешно прочитанных элементов. Важно проверять!
        appendNode(&head, data);
    }
    return head;
}



// Функция для создания второго списка и связывания с первым (Вариант 4)
void createAndLinkSecondList(struct Node* head, struct Node** secondHead) {
    struct Node* current = head;
    struct Node* secondListCurrent = NULL;
    int count = 1;

    while (current != NULL) {
        // Создаем узел во втором списке только для четных позиций в первом списке
        if (count % 2 == 0) {
            int data;
            printf("Введите значение для узла, связанного с %d: ", current->data);
            if (scanf("%d", &data) != 1) {
                fprintf(stderr, "Ошибка чтения ввода\n");
                //Обычно здесь надо как-то освободить память и выйти, чтобы не было утечек. В примере для краткости - пропуск.
                //  Лучше в этой ситуации прервать создание второго списка, чем выделить много памяти и оставить ее неинициализированной.
                break;
            }

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            if (newNode == NULL) {
                fprintf(stderr, "Ошибка выделения памяти\n");
                exit(EXIT_FAILURE);
            }
            newNode->data = data;
            newNode->next = NULL;
            newNode->down = NULL;

            current->down = newNode; // Связываем текущий узел с новым узлом

             if(*secondHead == NULL){
                  *secondHead = newNode;
                  secondListCurrent = newNode;
             }
            else {
                 secondListCurrent->next = newNode;
                 secondListCurrent = newNode;
            }
        }
        current = current->next;
        count++;
    }

}


int main() {
    // Оценка 3: Создание и вывод списка
    printf("Создание первого списка:\n");
    struct Node* head = createList();
    printf("Первый список: ");
    printList(head);

    //Оценка 4 и 5: Создание второго списка и связывание с первым
    struct Node* secondHead = NULL;
    createAndLinkSecondList(head, &secondHead);
    printf("Теперь можно перемещаться по списку.  WASD или 2,4,6,8 (A/4 - влево, D/6 - вправо, S/2 - вниз, W/8 - вверх, Q - выход):\n");

    struct Node* current = head;
    char input;

    while (1) {
        if (current) {
             printf("Текущий узел: %d\n", current->data);
        } else {
            printf("Текущий узел: NULL\n");
        }

        printf("Введите направление: ");

        if (scanf(" %c", &input) != 1) { // Важно: пробел перед %c, чтобы пропустить пробельные символы
            fprintf(stderr, "Ошибка чтения ввода\n");
            break;
        }
        input = toupper(input); // Приводим к верхнему регистру


        if (input == 'Q') {
            break;
        }

        struct Node* nextNode = NULL; // Временная переменная для следующего узла

        switch (input) {
            case 'D': // Вправо
            case '6':
                nextNode = current ? current->next : NULL; // Если current не NULL, перейти к следующему узлу
                if (nextNode) {
                    current = nextNode; // Если есть следующий узел, перемещаемся к нему
                } else {
                    printf("Достигнут конец списка. Возврат в начало.\n");
                    current = head; // Возвращаемся к началу
                }
                break;
            case 'A': // Влево
            case '4':
                 printf("Перемещение влево не реализовано. Возврат в начало.\n");
                 current = head;
                break;

            case 'S': // Вниз
            case '2':
                nextNode = current ? current->down : NULL;
                if (nextNode) {
                    current = nextNode;
                } else {
                    printf("Нет связанного узла снизу.\n");
                }
                break;
            case 'W': // Вверх
            case '8':
                 printf("Перемещение вверх не реализовано. Возврат в начало.\n");
                 current = head;
                break;

            default:
                printf("Неверный ввод.\n");
        }
    }

    printf("Конец программы.\n");

    // TODO: Очень важно добавить освобождение памяти всех выделенных узлов!
    // Это необходимо сделать, чтобы не было утечек памяти.

    return 0;
}













#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Для toupper

// Структура узла списка
struct Node {
    int data;
    struct Node* next;  // Указатель на следующий узел
    struct Node* down;  // Указатель на второй список

    Node(int value) : data(value), next(NULL), down(NULL) {}
};

// Функция добавления узла в конец списка
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->down = NULL;  // Теперь down тоже инициализируется!

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}


// Функция вывода списка на экран
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// Функция создания списка из ввода пользователя
struct Node* createList() {
    struct Node* head = NULL;
    int data;
    printf("Введите значения, 0 для окончания: ");
    while (scanf("%d", &data) == 1 && data != 0) {
        appendNode(&head, data);
    }
    return head;
}

// Функция для создания второго списка и связывания с первым (Вариант 4)
void createAndLinkSecondList(struct Node* head) {
    struct Node* current = head;
    int count = 1;

    while (current != NULL) {
        // Создаем узел во втором списке только для четных позиций в первом списке
        if (count % 2 == 0) {
            int data;
            printf("Введите значение для узла, связанного с %d: ", current->data);
            if (scanf("%d", &data) != 1) {
                fprintf(stderr, "Ошибка чтения ввода\n");
                break;  // Прерываем цикл в случае ошибки
            }

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            if (newNode == NULL) {
                fprintf(stderr, "Ошибка выделения памяти\n");
                exit(EXIT_FAILURE);
            }
            newNode->data = data;
            newNode->next = NULL;
            newNode->down = NULL;  // И down, и next инициализируются NULL

            current->down = newNode; // Связываем текущий узел с новым узлом
        }
        current = current->next;
        count++;
    }
}


int main() {
    // Оценка 3: Создание и вывод списка
    printf("Создание первого списка:\n");
    struct Node* head = createList();
    printf("Первый список: ");
    printList(head);

    //Оценка 4: Создание второго списка и связывание с первым
    createAndLinkSecondList(head); // Теперь secondHead не нужен в этой функции.
    printf("Второй список создан и связан с первым.\n");

    printf("Теперь можно перемещаться по списку.  WASD или 2,4,6,8 (A/4 - влево, D/6 - вправо, S/2 - вниз, W/8 - вверх, Q - выход):\n");

    struct Node* current = head;
    char input;

    while (1) {
        if (current) {
             printf("Текущий узел: %d\n", current->data);
        } else {
            printf("Текущий узел: NULL\n");
        }

        printf("Введите направление: ");

        if (scanf(" %c", &input) != 1) {
            fprintf(stderr, "Ошибка чтения ввода\n");
            break;
        }
        input = toupper(input); // Приводим к верхнему регистру


        if (input == 'Q') {
            break;
        }

        struct Node* nextNode = NULL; // Временная переменная для следующего узла

        switch (input) {
            case 'D': // Вправо
            case '6':
                nextNode = current ? current->next : NULL; // Если current не NULL, перейти к следующему узлу
                if (nextNode) {
                    current = nextNode; // Если есть следующий узел, перемещаемся к нему
                } else {
                    printf("Достигнут конец списка. Возврат в начало.\n");
                    current = head; // Возвращаемся к началу
                }
                break;
            case 'A': // Влево
            case '4':
                 printf("Перемещение влево не реализовано. Возврат в начало.\n");
                 current = head;
                break;

            case 'S': // Вниз
            case '2':
                nextNode = current ? current->down : NULL;
                if (nextNode) {
                    current = nextNode;
                } else {
                    printf("Нет связанного узла снизу.\n");
                }
                break;
            case 'W': // Вверх
            case '8':
                 printf("Перемещение вверх не реализовано. Возврат в начало.\n");
                 current = head;
                break;

            default:
                printf("Неверный ввод.\n");
        }
    }

    printf("Конец программы.\n");

     // TODO: Очень важно добавить освобождение памяти всех выделенных узлов!
    // Это необходимо сделать, чтобы не было утечек памяти.

    return 0;
}


















#include <stdio.h>
#include <stdlib.h>

// Структура узла списка
struct Node {
    int data;
    struct Node* next;  // Указатель на следующий узел
};

// Функция добавления узла в конец списка
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Функция вывода списка на экран
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Функция создания списка из ввода пользователя
struct Node* createList() {
    struct Node* head = NULL;
    int data;
    printf("Введите значения, 0 для окончания: ");
    while (scanf("%d", &data) == 1 && data != 0) {
        appendNode(&head, data);
    }
    return head;
}

int main() {
    // Оценка 3: Создание и вывод списка
    printf("Создание списка:\n");
    struct Node* head = createList();
    printf("Список: ");
    printList(head);

    // TODO: Добавить освобождение памяти всех выделенных узлов!
    // Это необходимо сделать, чтобы не было утечек памяти.

    return 0;
}
