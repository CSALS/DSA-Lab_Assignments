#include <stdio.h>

struct SLL
{
	int data,ind;
	struct SLL *next;
};
struct SLL *front = NULL;

void add(int data,int ind)
{
	struct SLL *t = (struct SLL *)malloc(sizeof(struct SLL));
	t->data = data;
	t->ind = ind;
	t->next = NULL;
	if(front == NULL)
	front = t;
	else
	{
		struct SLL *trav;
		trav=front;
		while(trav->next!=NULL)
		trav = trav->next;
		trav->next=t;
	}
}

void print()
{
	struct SLL *trav = front;
	while(trav!=NULL)
	{
		printf("%d ",trav->ind);
		trav=trav->next;
	}
	printf("\n");
}

void shuffle(int k)
{
	if(k==1 || k==0) return;
	
	struct SLL *start=front,*end=NULL,*trav=front;
	 struct SLL* temp = (struct SLL *)malloc(sizeof(struct SLL));
	while(start!=end)
	{
		
		trav=start;
		temp->data = start->data;
		temp->ind= start->ind;
		while(trav->next!=end)
		{
			
			trav->data = trav->next->data;
			trav->ind = trav->next->ind;
			trav=trav->next;
		}
	
		trav->data = temp->data;
		trav->ind = temp->ind;
		end = trav;
		if(((start->ind)%k)==0)
		start = start->next;
	}
	
}

int main()
{
	int k,x,i=1;
	scanf("%d",&k);
	while(1)
	{
		scanf("%d",&x);
		if(x==-1)
		break;
		else
		{ add(x,i); i++; }
	}
	print();
	shuffle(k);
	print();
	return 0;
}
// 3 1 2 3 4 5 6 7 8 9 -1