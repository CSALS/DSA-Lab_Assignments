#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_MAX 100000
int stack[INT_MAX];
int top=-1;
int length;
char str[10000];
void push(int x) {
	if(top == INT_MAX-1) {
		printf("Stack Overflow \n");
		return;
	}
	stack[++top]=x;
}
int pop() {
	if(top == -1) {
		return -1;
	}
	return stack[top--];
}
int empty() {
	if(top == -1) return 0;
	return 1;
}
int check_balanced() {
	for(int i=0;i<length;i++) {
		if(str[i]=='[' || str[i]=='(' || str[i]=='{') {
			push(str[i]);
		}
		else {
			if(str[i]==']') {
				if(pop()!='[')
					return -1;
			}
			if(str[i]=='}') {
				if(pop()!='{')
					return -1;
			}
			if(str[i]==')') {
				if(pop()!='(')
					return -1;
			}
		}
	}
	if(empty()==0)
		return 1;
	return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif

	
	scanf("%s",str);
	length=strlen(str);

	if(check_balanced()==1)
		printf("Balanced \n");
	else
		printf("Not Balanced \n");
	
	return 0;
}
