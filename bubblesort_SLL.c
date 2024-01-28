#include<stdio.h>
#include<stdlib.h>
//sorting single linked list by exchanging data
struct node{
    int data;
    struct node *link;
};
struct node *head, *tail = NULL;
int insert(int ndata)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = ndata;
    tmp -> link = NULL;
    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else{
        tail -> link = tmp;
        tail = tmp;
    }
    return 0;
}
void display(struct node *head)
{
    struct node *p;
    p = head;
    while(p != NULL)
    {
        printf("%d\t%d\n", p -> data, &p -> data);
        p = p -> link;
    }
}
void bubblesort(struct node *head)
{
    struct node *p, *q;
    int tmp;
    for(tail = NULL; tail != head -> link; tail = q)
    {
        for(p = head; p -> link != tail; p = p -> link)
        {
            q = p -> link;
            if(p -> data > q -> data)
            {
                tmp = p -> data;
                p -> data = q -> data;
                q -> data = tmp;
            }
        }
    }
}
int main()
{
    int ndata, n;
    printf("enter the no.of nodes :");
    scanf("%d", &n);
    for(int i =1; i<=n; i++)
    {
        printf("enter the elements to be insert :");
        scanf("%d", &ndata);
        insert(ndata);
    }
    display(head);
    bubblesort(head);
    printf("after sorting data : \n");
    display(head);

}