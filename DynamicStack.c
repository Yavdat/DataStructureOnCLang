#include <stdio.h>
#include <stdlib.h>

typedef int T;

typedef struct Stack_tag {
    T *data;
    size_t size;
    size_t top;
} Stack_t;

#define INIT_SIZE 10;
#define MULTIPLIER 2;

#define STACK_OVERFLOW -100;
#define STACK_UNDERFLOW -101;
#define OUT_OF_MEMORY -102;

Stack_t* createStack() {
    Stack_t *out = NULL;
    out = malloc(sizeof(Stack_t));
    if (out == NULL) {
        fprintf(stderr, "OUT_OF_MEMORY\n");
        exit(1);
    }
    out->size = INIT_SIZE;
    out->data = malloc(out->size * sizeof(T));
    if (out->data == NULL) {
        free(out);
        fprintf(stderr, "OUT_OF_MEMORY\n");
        exit(1);
    }
    out->top = 0;
    return out;
}

void deleteStack(Stack_t **stack) {
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resize(Stack_t *stack) {
    stack->size *= MULTIPLIER;
    stack->data = realloc(stack->data, stack->size * sizeof(T));
    if (stack->data == NULL) {
        fprintf(stderr, "STACK_OVERFLOW\n");
        exit(1);
    }
}

void push(Stack_t *stack, T value) {
    if (stack->top >= stack->size) {
        printf("resize stack\n");
        resize(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;
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

void implode(Stack_t *stack) {
    stack->size = stack->top;
    stack->data = realloc(stack->data, stack->size * sizeof(T));
}

void main(void) {
    
    Stack_t *s = createStack();

    for (int i = 0; i < 300; i++) {
        push(s, i);
    }

    // implode(s);

    for (int i = 0; i < 300; i++) {
        // printf("%d ", peek(s));
        printf("%d ", pop(s));
    }

    deleteStack(&s);
}