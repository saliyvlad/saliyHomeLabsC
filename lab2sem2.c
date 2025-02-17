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
