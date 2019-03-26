#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define nl \n
void swap(int *a,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp; //xor swapping isn't working in this case. why?
}
int sum = 0 , diff = 0;
int minHeap[INT_MAX];
int endHeap = -1;
bool empty() {
	if(endHeap == -1)
		return true; //empty
	return false; //not empty
}
int top() {
	//GETTING MIN ELEMENT TAKES O(n) time
	int min = INT_MAX;
	for(int i=0;i<=endHeap;i++)
		if(minHeap[i] < min && minHeap[i]!=-108)
			min = minHeap[i];
	return min;
}
void push(int data) {
		minHeap[++endHeap] = data; //INSERTION TAKES O(1) time
}
void pop() {
	int minIndex , min = INT_MAX;
	for(int i=0;i<=endHeap;i++)
		if(minHeap[i] < min) {
			min = minHeap[i];
			minIndex = i;
		}
	minHeap[minIndex] = -108;
}
int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif
	int n; scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) {
		int minElement = top();
		if(empty()==false && minElement < a[i]) {
			diff = a[i] - minElement;
			sum = sum + diff;
			pop();
			push(a[i]);
		}
		push(a[i]);
	}
	printf("%d \n",sum);

    return 0;	
}


