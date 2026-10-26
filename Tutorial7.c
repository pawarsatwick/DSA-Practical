#include <stdio.h>
#include <ctype.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int value)
{
    stack[++top]=value;
}
int pop()
{
    int value;
    value=stack[top];
    top--;
    return value;
}
void evaluateexpression(char*exp)
{
    for(int i=0; exp[i]!='\0'; i++)
    {
        char ch=exp[i];
        if(isdigit(ch))
        {
            push(ch-'0');
        }
        else
        {
            int v1=pop();
            int v2=pop();
            int r;
            switch(ch)
            {
                case '+':
                    r=v2+v1;
                    break;
                case '-':
                    r=v2-v1;
                    break;
                case '*':
                    r=v2*v1;
                    break;
                case '/':
                    r=v2/v1;
                    break;
            }
            push(r);
    }
}
printf("result = %d",pop());
}
int main()
{
    char exp[20];
    printf("Enter the postfix expression: ");
    scanf("%s",exp);
    evaluateexpression(exp);
    return 0;
}
