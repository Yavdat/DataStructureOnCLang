#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 20
typedef int T;

typedef struct Stack_tag {
    T data[STACK_MAX_SIZE];
    size_t size;
} Stack_t;

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

void push(Stack_t *stack, const T value) {
    if (stack->size >= STACK_MAX_SIZE) {
        fprintf(stderr, "STACK_OVERFLOW\n");
        exit(1);
    }
    stack->data[stack->size] = value;
    stack->size++;
}

T pop(Stack_t *stack) {
    if (stack->size == 0) {
        fprintf(stderr, "STACK_UNDERFLOW\n");
        exit(1);
    }
    stack->size--;
    return stack->data[stack->size];
}

T peek(const Stack_t *stack) {
    if (stack->size <= 0) {
        fprintf(stderr, "STACK_UNDERFLOW\n");
        exit(1);
    }
    return stack->data[stack->size - 1];
}

void printStackValue(const T value) {
    printf("%d", value);
}
 
void printStack(const Stack_t *stack, void (*printStackValue)(const T)) {
    int i;
    int len = stack->size - 1;
    printf("stack (%zu) : ", stack->size);
    for (i = 0; i < len; i++) {
        printStackValue(stack->data[i]);
        printf(" | ");
    }
    if (stack->size != 0) {
        printStackValue(stack->data[i]);
    }
    printf("\n");
}

void main(void) {
    Stack_t stack;
    size_t i;
    stack.size = 0;
 
    push(&stack, 3);
    printStack(&stack, printStackValue);
    push(&stack, 5);
    printStack(&stack, printStackValue);
    push(&stack, 7);
    printStack(&stack, printStackValue);
    printf("%d\n", pop(&stack));
    printStack(&stack, printStackValue);
    printf("%d\n", pop(&stack));
    printStack(&stack, printStackValue);
    printf("%d\n", pop(&stack));
    printStack(&stack, printStackValue);
    pop(&stack);
}