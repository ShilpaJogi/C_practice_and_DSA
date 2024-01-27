#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *addempty(int ndata)
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = ndata;
    tmp -> next = NULL;
    tmp -> prev = NULL;
    head = tmp;
    return head;
}
struct node *addatend(int ndata)
{
    struct node *tmp, *p;
    tmp = (struct node*)malloc(sizeof(struct node)); 
    tmp -> data = ndata;
    p = head;
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = tmp;
    tmp -> next = NULL;
    tmp -> prev = p;
    return head;
}
struct node *createlist(struct node *head)
{
    int i, n, ndata;
    printf("enter the no.of nodes :");
    scanf("%d", &n);
    head = NULL;
    if(n == 0)
    {
       return head;
    }
    printf("enter elements to be inserted :");
    scanf("%d\n", &ndata);
    head = addempty(ndata);
    for (i = 2; i <= n; i++)
    {
        printf("enter elements to be insert :");
        scanf("%d\n", &ndata);
        head = addatend(ndata);
    }
    return head;
}
struct node *addafter(int ndata, int item)
{
    struct node *tmp, *p;
    p = head;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = ndata;
    while(p != NULL)
    {
        if(p -> data == item)
        {
            tmp -> prev = p;
            tmp -> next = p -> next;
            p -> next = tmp;
            return head;
        }
        p = p -> next;
    }
    printf("%d not present in list\n", item);
}
struct node *addbefore(int ndata, int item)
{
    struct node *tmp, *p;
    p = head;
    if(head -> data == item)
    {
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp -> data = ndata;
        tmp -> prev = NULL;
        tmp -> next = head;
        head -> prev = tmp;
        head = tmp;
        return head;
    }
    while(p != NULL)
    {
        if(p -> data == item) 
        {
            tmp = (struct node*)malloc(sizeof(struct node));
            tmp -> data = ndata;
            tmp -> prev = p -> prev;
            tmp -> next = p;
            p -> prev -> next = tmp;
            p -> prev = tmp;
            return head;
        }
        p = p -> next;
    }
    printf("%d not present in list\n", item);
}
void display(struct node *head)
{
    struct node *p;
    p = head;
    if(head == NULL)
    {
        printf("list is empty");
    }
    while(p != NULL)
    {
        printf("%d\n", p -> data);
        p = p -> next;
    }
}
struct node *deletefirst(int ndata)
{
    struct node *tmp;
    if(head -> data == ndata)
    {
    tmp = head;
    head = head -> next;
    head -> prev = NULL;
    free(tmp);
    return head;
    }
    tmp = head -> next;
    while(tmp -> next != NULL)
    {
        if(tmp -> data == ndata)
        {
            tmp -> prev -> next = tmp -> next;
            tmp -> next -> prev = tmp -> prev;
            free(tmp);
            return head;
        }
        tmp = tmp->next;
    }
}
struct node *reverselist(struct node *head)
{
    struct node *p1, *p2, *p;
    p1 =head;
    p2 = p1 -> next;
    p1 -> next = NULL;
    p1 -> prev = p2;
    while(p2 != NULL)
    {
        p2 -> prev = p2 -> next;
        p2 -> next = p1;
        p1 = p2;
        p2 = p2 -> prev;
    }
    head = p1;
    p = head;
    while(p != NULL)
    {
        printf("reversed list %d\n", p -> data);
        p = p -> next;
    }
    return head;
}
int main()
{
    createlist(head);
    addafter(5, 2);
    addbefore(6, 2);
    display(head);
    deletefirst(1);
    display(head);
    reverselist(head);
    // display(head);
    // insertatfirst(1);
}