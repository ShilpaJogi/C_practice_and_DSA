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
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
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
void selectionsort(struct node *head)
{
    struct node *p, *q;
    int tmp;
    p = head;
    for(p = head; p -> link != NULL; p = p -> link)
    {
        for(q = p -> link; q != NULL; q = q -> link)
        {
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
    int i, n, ndata;
    printf("enter the no.of nodes :");
    scanf("%d", &n);
    for(i = 1; i<=n; i++)
    {
        printf("enter the elements to be insert :");
        scanf("%d", &ndata);
        insert(ndata);
    }
    display(head);
    selectionsort(head);
    printf("after sorting :\n");
    display(head);
}