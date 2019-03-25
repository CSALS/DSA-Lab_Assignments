//O(n^3) = Time Complexity
#include <stdio.h>
#include <limits.h>
int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif

	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	int sum=0;
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			int min=INT_MAX;
			for(int k=i;k<=j;k++) {
				//all arr[k] are part of one subarray
				if(arr[k]<min) {
					min = arr[k];
				}
			}
			sum = sum + min;
		}
	}
	printf("%d \n",sum);
	return 0;
}
