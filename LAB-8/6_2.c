#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//This approach uses no extra space
int stack[INT_MAX];
int topStack=-1; int minElement=INT_MAX;
int empty() {
	if(topStack==-1) return 0; //empty
	return 1;
}
int top() {
	return stack[topStack];
}
void push(int data) {
	if(topStack==INT_MAX-1) {
		printf("Stack Overflow");
		return;
	}
	if(empty()) {
		stack[++topStack] = data;
		minElement = data;
	}
	else {
		if(data >= minElement)
			stack[++topStack] = data;
		else if(data < minElement) { //data is new minimum element
			stack[++topStack] = 2*data - minElement;
			minElement = data;
		}
	}

}
void pop() {
	int topElement = top();
	topStack--;
	if(topElement < minElement) {
		minElement = 2*minElement - topElement;
	}
}
int minimum() {
	return minElement;
}
int main() {


	int flag=1;
	while(flag==1) {
	printf("Press 1 for pushing an element\nPress 2 for popping the top element\nPress 3 for retrieving the minimum element\nPress 4 for exiting\n");
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
				printf("The top element is :- %d \n",top());
				pop();
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
