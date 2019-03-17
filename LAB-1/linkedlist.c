#include <stdio.h>
#include <stdlib.h>

//singly linked list
struct SLL
{
	int data;
	struct SLL* next;
};
struct SLL* root=NULL;
void printSLL()
{
	struct SLL* temp = root;
	while(temp != NULL)
	{
		printf(" %d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void insertSLL(int x)
{
	struct SLL* new_node = (struct SLL*)malloc(sizeof(struct SLL));
	new_node->data = x;
	new_node->next = NULL;
	if(root == NULL)
	{
		root = new_node;
	}
	else
	{
		struct SLL* temp = root;
		while(temp->next != NULL)
		temp = temp->next;
		temp->next = new_node;
	}
}
void kthSLL(int k)
{
	int len=0;
	struct SLL* temp = root;
	while(temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	if(k > len)
	printf("length exceeded");
	else
	{
		temp = root;
		for(int i=1;i<len-k+1;i++)
		temp = temp->next;
		printf("%d ",temp->data);
	}
}
//doubly linked list
struct DLL
{
	int data;
	struct DLL *prev,*next;
};
struct DLL *front=NULL;
void printDLL()
{
	struct DLL* temp = front;
	while(temp != NULL)
	{
		printf(" %d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void insertDLL(int x)
{
	struct DLL* new_node = (struct DLL*)malloc(sizeof(struct DLL));
	new_node->data = x;
	new_node->next = NULL;
	new_node->prev = NULL;
	if(front == NULL)
	{
		front = new_node;
	}
	else
	{
		struct DLL* temp = front;
		while(temp->next != NULL)
		temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;

	}
}
void kthDLL(int k)
{
	int len=0;
	struct DLL* temp = front;
	while(temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	if(k > len)
	printf("length exceeded");
	else
	{
		temp = front;
		for(int i=1;i<len-k+1;i++)
		temp = temp->next;
		printf("%d ",temp->data);
	}

}
//circular linked list
struct CLL
{
	int data;
	struct CLL* next;
};
struct CLL* head = NULL;
void printCLL()
{
	struct CLL* temp = head;
	while(head != NULL)
	{
		do{
		   printf(" %d ",temp->data);
		   temp = temp->next;
	 	}while(temp != head);
	}
}
void insertCLL(int x)
{
	struct CLL* new_node = (struct CLL*)malloc(sizeof(struct CLL));
	new_node->data = x;
	new_node->next = NULL;
	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		struct CLL* temp = head;
		while(temp->next != NULL)
		temp = temp->next;
		temp->next = new_node;
	}
}
void kthCLL(int k)
{
    int len = 0;
    struct CLL* temp = head;
    do
    {
        len++;
        temp = temp->next;
    }while(temp != head);
    printf("length is \n %d",len);
    if(k > len)
	printf("length exceeded");
	else
	{
		temp = head;
		for(int i=1;i<len-k+1;i++)
		temp = temp->next;
		printf("%d ",temp->data);
	}
}

int main()
{
	int n,k;
    printf("enter number");
	scanf("%d",&n);
	//1 - SLL , 2-DLL , 3-CLL
	switch(n)
	{
		case 1:
		while(1)
		{
		   int t;
                   scanf("%d",&t);
                   if(t==-1)
                   break;
                   else
        	   insertSLL(t);
		}
		scanf("%d",&k);
		kthSLL(k);
	  	break;

		case 2:
		while(1)
		{
		   int t;
                   scanf("%d",&t);
                   if(t==-1)
                   break;
                   else
        	   insertDLL(t);
		}
		scanf("%d",&k);
		kthDLL(k);
	  	break;

	  	case 3:
		while(1)
		{
		   int t;
                   scanf("%d",&t);
                   if(t==-1)
                   break;
                   else
        	   insertCLL(t);
		}
		struct CLL* temp = head;
		while(temp->next != NULL)
            temp = temp->next;
        temp->next = head;
        scanf("%d",&k);
		kthCLL(k);
	  	break;

	}

	return 0;
}
