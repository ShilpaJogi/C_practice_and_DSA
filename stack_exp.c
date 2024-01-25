#include<stdio.h>
#define MAX 10
int top = -1;
int stack_arr[MAX];
void push(int item)
{
    if(top == MAX-1)
    {
        printf("stack overflow");
    }
    top = top + 1;
   stack_arr[top] = item ;
}
int pop(int item)
{
    if(top == - 1)
    {
        printf("stack underflow");
    }
    top = top - 1;
    item = stack_arr[top];
    return item;
}
int peek(int item)
{
    if(top == -1)
    {
        printf("stack underflow");
    }
    return(stack_arr[top]);
}
int main()
{
    int item;
    while(top != MAX-1)
    {
        printf("item to be push : ");
        scanf("%d", &item);
        push(item);
    }
    for(int i = 0; i < MAX; i++)
    {
        printf("pushed items -> %d\t", stack_arr[i]);
    }
    while(top != 4)
    {
        printf("item to be pop : ");
        scanf("%d", &item);
        pop(item);
    }
    for(int i = 0; i < 5; i++)
    {
        printf("poped items -> %d\t", stack_arr[i]);
    }
    for(int i = top; i>= 0; i--)
    {
        printf("\nfinal stack -> %d\t", stack_arr[i]);
    }
    peek(item);
    printf("\ntop -> %d", top);
}