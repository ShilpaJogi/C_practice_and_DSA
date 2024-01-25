#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node *head, *tail = NULL;

int insert(int ndata)
{
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    new1 -> data = ndata;
    new1 -> link = NULL;
    
    if(head == NULL)
    {
        head = new1;
        tail = new1;
    }
    else
    {
        tail -> link = new1;
        tail = new1;
    }
    return 0;
}
void display(struct node *head)
{
  struct node *p;
    if(head == NULL)
    {
        printf("list is empty");
    }
    p = head;
    while(p != NULL)
    {
        printf("%d\n", p -> data);
        p = p -> link;
    }
}
void count(struct node *head)
{
    struct node *p;
    int cnt = 0;
    p = head;
    while(p != NULL)
    {
        p = p -> link;
        cnt++;
    }
    printf("count is %d\n", cnt);
}
void searching(struct node *head, int item)
{
    struct node *p = head;
    int pos = 1;
    while(p != NULL)
    {
        if(p -> data == item)
        {
            printf("item found %d\t at position %d\n",item, pos);
        }
        p = p -> link;
        pos++;
    }
    // printf("item not found");
}
int insertatbeg(int ndata)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = ndata;
    new_node -> link = head;
    head = new_node;
    return 0;
}
int insertatend(int ndata)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = ndata;
    struct node* p = head;
    while( p-> link != NULL)
    {
           p = p -> link;
    }
    // new_node -> link = p -> link;
    // p -> link = new_node;
    //or we can write this way also
    p -> link = new_node;
    new_node -> link = NULL;
    return 0;
}
int insertafternode(int ndata, int item)
{
    struct node *p = head, *new_node;
    while(p != NULL)
    {
        if(p -> data == ndata)
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> data = item;
            new_node -> link = p -> link;
            p -> link = new_node;
        }
        p = p -> link;
    }
    return 0;
}
int insertbeforenode(int ndata, int item)
{
    struct node *new_node, *p;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    p = head;
    if(ndata == head -> data)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = item;
        new_node -> link = head;
        head = new_node;
    }
    while(p -> link != NULL)
    {
        if(p -> link -> data == ndata)
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> data = item;
            new_node -> link = p -> link;
            p -> link = new_node;
            return 0;
        }
        p = p -> link;
    }
    return 0;
}
int insertatpos(int ndata, int pos)
{
    struct node *new_node, *p = head;
    int i;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = ndata;
    if(pos == 1)
    {
        new_node -> link = head;
        head = new_node;
        return 0;
    }
    for(i = 1; (i < pos - 1) && (p != NULL); i++)
    {
        p = p -> link;
    }
    if(p == NULL)
    {
        printf("less elements %d\n", pos);
    }
    else
    {
        new_node -> link = p -> link;
        p -> link = new_node;
    }
    return 0;
}
int deletefirstnode(int pos)
{
    struct node *p;
    if(pos == 1)
    {
    p = head;
    head = head -> link;
    free(p);
    return 0;
    }
}
int deletebwnodes(int ndata)
{
    struct node *p, *temp;
    p = head;
    while(p -> link != NULL)
    {
        if(p -> link -> data == ndata)
        {
            temp = p -> link;
            p -> link = temp -> link;
            free(temp);
            return 0;
        }
        p = p -> link;
    }
}
int deleteatend(int ndata)
{
    struct node *p, *temp;
    if(head == NULL)
    {
        printf("list is empty");
        return 0;
    }
    if(head -> data == ndata)
    {
        temp = head;
        head = head -> link;
        free(temp);
        return 0;
    }
    p = head;
    while(p -> link != NULL)
    {
        if(p -> link -> data == ndata){
        temp = p -> link;
        p -> link = temp -> link;
        free(temp);
        return 0;
        }
        p = p -> link;
    }
}
int reverselist(struct node* head)
{
    struct node *p, *next, *prev;
    prev = NULL;
    p = head;
    while(p != NULL)
    {
        next = p -> link;
        p -> link = prev;
        prev = p;
        p = next;
    }
    head = prev;
    return 0;
}
int main()
{
    insert(1);      //create list
    insert(2);
    insert(3);
    insertatbeg(4);         //insert at beginning
    insertatend(5);         //insert at ending
    insertafternode(1, 6);       //insertion between nodes - after a 1st node
    insertbeforenode(2, 7);       //insertion between nodes - before a 2nd node
    insertatpos(8, 5);       //insertion between nodes - 5th pos at node data 8
    deletefirstnode(1);     //delete first node in list
    deletebwnodes(8);        //delete between the nodes
    deleteatend(5);         //delte at the end of the list
    // reverselist(head);
    display(head);      //display the nodes
    count(head);         //count the number of nodes
    searching(head, 2);      //search an item in created list
}