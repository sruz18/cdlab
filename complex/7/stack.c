#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// PUSH
void push() {
    int x;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    top++;
    stack[top] = x;
}

// POP
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", stack[top]);
    top--;
}

// DISPLAY
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

// MAIN
int main() {
    int choice;

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        if (choice == 1)
            push();
        else if (choice == 2)
            pop();
        else if (choice == 3)
            display();
        else if (choice == 4)
            break;
        else
            printf("Invalid choice\n");
    }

    return 0;
}