#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 1e7

int arr[INT_MAX];
int end=-1;
int min_arr[INT_MAX];

void push(int data) {
	if(end==INT_MAX-1) {
		printf("Stack Overflow");
	}
	else {
		arr[++end] = data;
				
	}
}
int pop() {
	return arr[end--];
}
int empty() {
	if(end==-1) return 0; //empty
	return 1;
}
int minimum() {
	
}
int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif

	int flag=1;
	while(flag==1) {
	printf("Press 1 for pushing an element \n Press 2 for popping the top element \n Press 3 for retrieving the minimum element \n Press 4 for exiting");
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
