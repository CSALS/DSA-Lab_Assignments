//BRUTE FORCE approach 
#include<stdio.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define nl printf("\n");
int minWaitingTime = INT_MAX;
void swap(int *a,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp; //xor swapping isn't working in this case. why?
}
//repititive permutations will be found if duplicates present
void computePermutation(int arr[],int start,int end,int a[],int b[],int n) {
	if(start == end) {
		//permutation is ready
		int totalTimePassed = 0 , totalWaitingTime = 0;
		for(int i=0;i<n;i++) {
			totalWaitingTime = totalWaitingTime + b[arr[i]] + max(0,totalTimePassed - a[arr[i]]);
			totalTimePassed  = max(a[arr[i]],totalTimePassed) + b[arr[i]];
		}
		minWaitingTime = min(minWaitingTime,totalWaitingTime);
		return;
		/*for(int i=0;i<n;i++)
			printf("%d ",arr[i]); nl;*/
		return;
	}
	int i;
	for(i=start;i<=end;i++) {
		swap((arr+i),(arr+start));
		computePermutation(arr,start+1,end,a,b,n);
		swap((arr+i),(arr+start));
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
	int arr[n],a[n],b[n];
	for(int i=0;i<n;i++) {
		scanf("%d %d",&a[i],&b[i]);
		arr[i]=i;
	}
	computePermutation(arr,0,n-1,a,b,n);
	printf("%lf",((double)(minWaitingTime))/n);
    return 0;	
}


