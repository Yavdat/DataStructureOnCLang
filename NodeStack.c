#include <stdio.h>
#include <stdlib.h>

typedef int T;

typedef struct Node_tag {
    T value;
    struct Node_tag *next;
} Node_t;

/*
Функция ставки первого элемента проста: создаем новый узел.
Указатель next кидаем на старый узел.
Далее указатель на вершину стека перекидываем на вновь созданный узел.
Теперь вершина стека указывает на новый узел.
*/

void push(Node_t **head, T value) {

    Node_t *tmp = malloc(sizeof(Node_t));
    if (tmp == NULL) {
        fprintf(stderr, "STACK_OVERFLOW\n");
        exit(1);
    }

    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}

Node_t* pop_node(Node_t **head) {
    Node_t *out;
    if ((*head) == NULL) {
        fprintf(stderr, "STACK_UNDERFLOW\n");
        exit(1);
    }
    out = *head;
    *head = (*head)->next;
    return out;
}

T pop_value(Node_t **head) {
    Node_t *out;
    T value;
    if ((*head) == NULL) {
        fprintf(stderr, "STACK_OVERFLOW\n");
        exit(1);
    }
    out = *head;
    *head = (*head)->next;
    value = out->value;
    free(out);
    return value;
}

T peek(const Node_t* head) {
    if (head == NULL) {
        fprintf(stderr, "STACK_UNDERFLOW\n");
        exit(1);
    }
    return head->value;
}

void printStack(const Node_t* head) {
    printf("stack > ");
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
}

size_t getSize(const Node_t* head) {
    size_t size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}

void main(void)
{
    Node_t *head = NULL;
    for (int i=0; i<300; i++) {
        push(&head, i);
    }
    printf("size = %zu\n", getSize(head));
    while (head) {
        printf("%d ", peek(head));
        printf("%d ", pop_value(&head));
    }
    printf("size = %zu\n", getSize(head));

    head = NULL;
    Node_t *tmp;
    for (int i=0; i<300; i++) {
        push(&head, i);
    }
    printf("size = %zu\n", getSize(head));
    while (head) {
        printf("%d ", peek(head));
        tmp = pop_node(&head);
        printf("%d ", tmp->value);
        free(tmp);
    }
    printf("\nsize = %zu\n", getSize(head));
}