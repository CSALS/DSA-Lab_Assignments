#include <stdio.h>
#include <stdlib.h>
int arr[1000];
int n;
int comp(const void *a,const void *b) {
	return *(int *)a - *(int *)b;
}
void sort() {
	qsort(arr,n,sizeof(int),comp);
}

int main() {

	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif

	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	sort();
	int a=0,b=0;
	for(int i=0;i<n;i++) {
		if(i%2==0) { // i&1 , i%2
			a = a*10 + arr[i];
		}
		else {
			b = b*10 + arr[i];
		}
	}
	printf("Sum is %d %d %d \n",a,b,(a+b));
	return 0;
}
