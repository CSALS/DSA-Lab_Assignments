#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int top(int arr[],int size) {
	return arr[size-1];
}
int main() {
	int a,b,sum,newSum=0;
	scanf("%d %d %d",&a,&b,&sum);
	int stackA[a],stackB[b];
	for(int i=a-1;i>=0;i--) {
		scanf("%d",&stackA[i]);
	}
	for(int i=b-1;i>=0;i--) {
		scanf("%d",&stackB[i]);
	}
	while(a!=0) {
        printf("%d\n",top(stackA,&a));
        a--;
	}
	int maximumPossibleScore=0;
	while(a != 0 && b != 0) {
		if(top(stackA,a) < top(stackB,b)) {
			int topElement = top(stackA,a);
			if(newSum+topElement <= sum) {
				newSum = newSum + topElement;
				a--;
				maximumPossibleScore++;
			}
			else {
				break;
			}
		}
		else {
			int topElement = top(stackB,b);
			if(newSum+topElement <= sum) {
				newSum = newSum + topElement;
				b--;
				maximumPossibleScore++;
			}
			else {
				break;
			}
		}
	}
	/*while(a > 0) {
		int topElement = top(stackA,a);
		if(newSum+topElement <= sum) {
			newSum = newSum + topElement;
			a--;
			maximumPossibleScore++;
		}
		else {
				break;
			}
	}
	while(b > 0) {
		int topElement = top(stackB,b);
		if(newSum+topElement <= sum) {
			newSum = newSum + topElement;
			b--;
			maximumPossibleScore++;
		}
		else {
				break;
			}
	}*/
	printf("%d \n",maximumPossibleScore);
	return 0;
}

/*
5 4 10
4 2 4 6 1
2 1 8 5 */
