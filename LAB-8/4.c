#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<math.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define nl printf("\n")
void swap(int *a,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp; //xor swapping isn't working in this case. why?
}
int minHeap[INT_MAX];
int heapLength=0; int n;
void heapifyUp(int index) {
	int parentIndex = floor((index-1)/2);
	if(parentIndex < 0)
		return;
	if(minHeap[index] < minHeap[parentIndex]) {
		swap(&minHeap[index],&minHeap[parentIndex]);
		heapifyUp(parentIndex);
	}
}
void heapifyDown(int index) {
	int leftChildIndex = 2*index+1;
	int rightChildIndex = 2*index+2;
	//Left Child exists
	if(leftChildIndex < heapLength) {
		int smallerIndex = leftChildIndex;
		//If right child exists
		if(rightChildIndex < heapLength) {
			if(minHeap[leftChildIndex] > minHeap[rightChildIndex])
				smallerIndex = rightChildIndex;
		}
		if(minHeap[smallerIndex] < minHeap[index]) {
			swap(&minHeap[smallerIndex],&minHeap[index]);
			heapifyDown(smallerIndex);
		}
	}
}
void insert(int data) {
	minHeap[heapLength++] = data;
	heapifyUp(heapLength-1); //heapify from bottom node to top
}
int removeTop() {
	//heaplength==0 then no element to remove
	int topElement = minHeap[0];
	minHeap[0] = minHeap[heapLength-1];
	heapLength--;
	heapifyDown(0); //heapify from top node 0 to bottom
	return topElement;
}
void buildHeap(int arr[],int n) {
	for(int i=0;i<n;i++) {
		insert(arr[i]);
	}
}
bool isEmpty() {
	if(heapLength == 0)
		return true;
	return false;
}
int main() {
	/*#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif*/
	int k; scanf("%d %d",&n,&k);
	int arr[n],op=0; bool isPossible=true;
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	buildHeap(arr,n);
	while(1) {
		if(isEmpty()) {
			isPossible = false;
			break;
		}
		int firstLeastElement = removeTop();
		if(firstLeastElement >= k)
			break;
		//Now firstLeastElement is less than K for sure
		if(isEmpty()==true) {
			if(firstLeastElement < k) {
				isPossible = false;			
			}
			break;
		}
		int secondLeastElement = removeTop();
		int newElement = firstLeastElement + 2*secondLeastElement;
		op++;
		insert(newElement);
	}
	if(isPossible==false)
		printf("-1\n");
	else
		printf("%d\n",op);
    return 0;	
}

