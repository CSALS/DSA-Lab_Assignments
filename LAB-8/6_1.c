#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 10000
//This approach uses extra stack for minimum
int stack[INT_MAX];
int topStack=-1;
int minStack[INT_MAX];
int topMinStack=-1;
/* ith elemenet in minStack is the minimum element of first 'i' elements of
 original stack */
void push(int data) {
	if(topStack==INT_MAX-1) {
		printf("Stack Overflow");
	}
	else {
		stack[++topStack] = data;
		if(topMinStack==-1) {
			minStack[++topMinStack] = data;
		}
		else {
			if(data < minStack[topMinStack])
				minStack[topMinStack+1] = data;
			else
				minStack[topMinStack+1] = minStack[topMinStack];
				topMinStack++;
		}
	}
}
int pop() {
	topMinStack--;
	return stack[topStack--];
}
int empty() {
	if(topStack==-1) return 0; //empty
	return 1;
}
int minimum() {
	return minStack[topMinStack];
}
int main() {
	/*#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif*/

	int flag=1;
	while(flag==1) {
	printf("Press 1 for pushing an element \n Press 2 for popping the top element \n Press 3 for retrieving the minimum element \n Press 4 for exiting \n");
	int input; scanf("%d",&input);
		switch(input) {
			case 4:
			printf("BYE");
			flag=0;
			break;
			case 1:
			printf("Enter the element \n");
			int n; scanf("%d",&n);
			push(n);
			break;
			case 2:
			if(empty()) {
				printf("The top element is :- %d \n",pop());
			}
			else {
				printf("Empty Stack \n");
			}
			break;
			case 3:
			if(empty()) {
				printf("The minimum element is = %d \n",minimum());
			}
			else {
				printf("Empty Stack \n");
			}
			break;
			default:
			printf("Enter valid element \n");
		}
	}
	
	return 0;
}
