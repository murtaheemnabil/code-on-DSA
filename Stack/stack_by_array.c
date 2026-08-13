#include <stdio.h>
#include <stdbool.h>

#define MAX 5
struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

bool isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

bool isEmpty(struct Stack *s) {
    return s->top == -1;
}
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Cannot push %d: Stack Overflow!\n", value);
        return;
    }
    s->top++;
    s->items[s->top] = value;
    printf("Pushed: %d\n", value);
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Cannot pop: Stack Underflow!\n");
        return -1;
    }
    int poppedValue = s->items[s->top];
    s->top--;
    return poppedValue;
}
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top];
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Current Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
int main() {
    struct Stack myStack;
    initStack(&myStack);


    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    display(&myStack);


    printf("Top element (peek): %d\n", peek(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));

    display(&myStack);
    return 0;
}
