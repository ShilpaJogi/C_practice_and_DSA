#include<stdio.h>
#include<stdlib.h>
#define MAX  6
struct node{
    int data;
    struct node *next;
};
struct node *head, *tail = NULL;
void insertion(int ndata)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = ndata;
    newnode -> next = NULL;
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail -> next= newnode;
        tail = newnode;
    }
}
int main()
{
    
    insertion(2);
    insertion(5);
    insertion(8);
    struct node *current = head;
    while(current != NULL)
    {
        printf("list is %d", current -> data);
        current = current -> next;
    }
    if(head == NULL)
    {
        printf("list is empty");
    }
}