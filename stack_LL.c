#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* top = NULL;
void push(int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("stack overflow");
        return;
    }
    temp->data = item;
    temp->link = top;
    top = temp;
}
int pop(int item)
{
    struct node * temp;
    if(top == NULL)
    {
        printf("stack underflow");
    }
    temp = top;
    item = temp->data;
    top = top->link;
    free(temp);
    return item;
}
int main()
{
    int item;
        printf("data to be push : ");
        scanf("%d", &item);
        push(item);
        struct node *ptr = top;
        if(top == NULL)
        {
            printf("stack is empty");
        }
        while (ptr != NULL)
        {
            printf(" %d\n", ptr->data);
            ptr = ptr->link;
        }
        printf("data to be pop : ");
        scanf("%d", &item);
        pop(item);
        while (ptr != NULL)
        {
            printf(" %d\n", ptr->data);
            ptr = ptr->link;
        }
}