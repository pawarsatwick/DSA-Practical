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
