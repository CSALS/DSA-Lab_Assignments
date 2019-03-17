#include <stdio.h>



struct Node
{
    int data;
    struct Node* next;
};

struct Node* h1=NULL,*h2=NULL,*mergeHead=NULL;

struct Node *newNode(int x)
{
    struct Node* temp = (struct Node* )malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void insert1(int x)
{
    struct Node* temp = newNode(x);
    if(!h1)
    {
        h1 = temp;
        return;
    }
    struct Node* trav=h1;
    while(trav->next!=NULL)
    {
        trav=trav->next;
    }
    trav->next = temp;
}
void insert2(int x)
{
    struct Node* temp = newNode(x);
    if(!h2)
    {
        h2 = temp;
        return;
    }
    struct Node* trav=h2;
    while(trav->next!=NULL)
    {
        trav=trav->next;
    }
    trav->next = temp;
}
void printList(struct Node* head)
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
struct Node *merge(struct Node* h1,struct Node* h2)
{
    if(!h1)
        return h2;
    if(!h2)
        return h1;

    if(h1->data < h2->data)
    {
        h1->next = merge(h1->next,h2);
        return h1;
    }
    else
    {
        h2->next = merge(h1,h2->next);
        return h2;
    }
}
int main()
{
    int n1,n2,x;
    scanf("%d %d",&n1,&n2);
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);
        insert1(x);
    }
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&x);
        insert2(x);
    }
    printList(merge(h1,h2));
    return 0;
}
