#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void push(int x) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Stack Overflow (Memory full)\n");
        return;
    }
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}
void pop() {
    struct Node *temp;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        temp = top;
        printf("Popped element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}
void display() {
    struct Node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();

    return 0;
}






