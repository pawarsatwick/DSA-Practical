// stack using array
#include <stdio.h>
#define MAX 5
int stack[MAX], top=-1;
void push(int x){
    if (top== MAX-1)
        printf("Stack overflow\n");
    else 
        stack[++top]=x;
}
void pop()
{
    if(top==-1)
        printf("stack underflow\n");
    else 
        printf("Element popped:\n %d",stack[top--]);
}
void display()
{
    int i;
    if(top==-1)
        printf("Stack is empty\n");
    else 
    {
        for(i=top; i>=0; i--)
            printf(" %d ", stack[i]);
        printf("\n");
    }
}
int main()
{
    push(10);
    push(20);
    push(40);
    push(70);
    push(80);
    display();
    pop();
    display();
    return 0;
}

// Queue using array
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front= -1, rear= -1;
void enqueue(int value){
    if(rear== MAX -1){
        printf("Queue is overflow\n");
    }else {
        if (front== -1)front=0;
        queue[++rear]== value;
        printf("%d inserted \n", value);
    }
}
void dequeue()
{
    if(front== -1|| front>rear){
        printf("Queue is empty!\n");
    }
    else 
    {
        printf("%d deleted\n", queue[front++]);
    }
}
void display() {
    if (front == -1 || front > rear) 
    {
        printf("Queue is Empty!\n");
    }else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main(){
    int choice, value;
    while(1){
        printf("\n 1.Enqueue\n 2.dequeue\n 3.display\n 4.Exit\n");
        printf("enter choice:");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// 
