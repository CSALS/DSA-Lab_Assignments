#include <stdio.h>
#include <stdlib.h>

//singly linked list
struct SLL
{
	int data;
	struct SLL* next;
};

void print(struct Node* head,int n)
{
	int len=0,i;
	struct Node* temp = head;
	//counting no. of nodes
	while(temp != NULL)
	{
		temp=temp->next;
		len++;
	}
	//check if value of n is not more than length
	if(n>len)
	printf("Size exceeded");
	
	temp = head;
	//getting (len-n+1)th node from begining
	for(i=1;i<len-n+1;i++)
	temp = temp->next;
	printf("%d ",temp->data);
}

void push(struct Node** head_ref,int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->next = *head_ref;
	new_node->data = new_data;
	*head_ref = new_node;
}


int main()
{
	struct Node* head=NULL;

	return 0;
}

