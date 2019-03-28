#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define nl printf("\n")
#define INT_MAX 100000
void swap(int *a,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp; //xor swapping isn't working in this case. why?
}
int minHeap[INT_MAX]; int minHeapSize=0;
int maxHeap[INT_MAX]; int maxHeapSize=0;
void heapifyDown(int i,int heap[],int condition,int size) {
	int leftIndex = 2*i+1;
	int rightIndex = 2*i+2;
	if(leftIndex < size) {
		//left index exists
		if(condition == 0) {
			//min Heap
			int smallerIndex = leftIndex;
			if(rightIndex < size) {
				//right index exists
				if(heap[leftIndex] > heap[rightIndex])
					smallerIndex = rightIndex;
			}
			if(heap[smallerIndex] < heap[i]) {
				swap(&heap[i],&heap[smallerIndex]);
				heapifyDown(smallerIndex,heap,condition,size);
			}
		}
		else {
			//max Heap
			int largestIndex = leftIndex;
			if(rightIndex < size) {
				//right index exists
				if(heap[leftIndex] < heap[rightIndex])
					largestIndex = rightIndex;
			}
			if(heap[largestIndex] > heap[i]) {
				swap(&heap[i],&heap[largestIndex]);
				heapifyDown(largestIndex,heap,condition,size);
			}
		}
	}
}
void pop(int heap[],int *size,int condition) {
	heap[0] = heap[*size-1];
	(*size)--;
	heapifyDown(0,heap,condition,*size);
}
int top(int heap[],int size) {
	return heap[0];
}
void heapifyUp(int i,int heap[],int condition) {
	int parentIndex = floor((i-1)/2);
	if(parentIndex < 0)
		return;
	if(condition == 0) {
		//min Heap
		if(heap[i] < heap[parentIndex]) {
			swap(&heap[i],&heap[parentIndex]);
			heapifyUp(parentIndex,heap,condition);
		}
	}
	else {
		//max Heap
		if(heap[i] > heap[parentIndex]) {
			swap(&heap[i],&heap[parentIndex]);
			heapifyUp(parentIndex,heap,condition);
		}
	}
}
void push(int heap[],int *size,int x,int condition) {
	heap[*size] = x;
	(*size)++;
	heapifyUp(*size-1,heap,condition);
}
void insert(int x) {
	if(maxHeapSize && x>=top(maxHeap,maxHeapSize))
		push(minHeap,&minHeapSize,x,0);
	else
		push(maxHeap,&maxHeapSize,x,1);
}
void balance() {
	if((minHeapSize-maxHeapSize)>1 || (minHeapSize-maxHeapSize)<-1) {
		if(minHeapSize > maxHeapSize) {
			push(maxHeap,&maxHeapSize,top(minHeap,minHeapSize),1);
			pop(minHeap,&minHeapSize,0);
		}
		else {
			push(minHeap,&minHeapSize,top(maxHeap,maxHeapSize),0);
			pop(maxHeap,&maxHeapSize,1);
		}
	}
}
double getMedian() {
	if(minHeapSize == maxHeapSize) {
		return (double)(top(maxHeap,maxHeapSize)+top(minHeap,minHeapSize))/2;
	}
	else {
		if(minHeapSize > maxHeapSize) 
			return top(minHeap,minHeapSize);
		else
			return top(maxHeap,maxHeapSize);
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif
	int n; scanf("%d",&n);
	while(n--) {
		int x; scanf("%d",&x);
		insert(x);
		//printf("top min %d\n",top(minHeap,minHeapSize));
		//printf("top max %d\n",top(maxHeap,maxHeapSize));
		balance();
		//printf("top min %d\n",top(minHeap,minHeapSize));
		//printf("top max %d\n",top(maxHeap,maxHeapSize));
		printf("%lf\n",getMedian());
	}
    return 0;	
}

