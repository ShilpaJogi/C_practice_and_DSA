#include<stdio.h>
#include<stdlib.h>
//sorting single linked list by Re-arranging links
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
struct node *selectionsort_rearranginglink(struct node *head)
{
    struct node *p, *q, *r, *s, *tmp;
    for(r=p=head; p -> link != NULL; r=p, p = p -> link)
    {
        for(s=q=p->link; q!= NULL; s=q, q = q->link)
        {
            if((p->data) > (q->data))
            {
                tmp = p -> link;
                p -> link = q ->link;
                q -> link = tmp;
                if(p != head)
                {
                    r -> link = q;
                    s -> link = p;
                }
                if(p == head)
                {
                    head = q;
                }
                tmp = p;
                p = q;
                q = tmp;
            }
        }
    }
    
            while(p != NULL)
            {
                printf("%d\n", p -> data);
                p = p->link;
            }
    return head;
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
    selectionsort_rearranginglink(head);
    printf("after sorting data : \n");
    display(head);

}