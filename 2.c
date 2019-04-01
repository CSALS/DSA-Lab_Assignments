#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Greedy approach doesn't work in this case
int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif
	int a,b,m,newSum=0;
	scanf("%d %d %d",&a,&b,&m);
	int stackA[a],stackB[b];
	for(int i=0;i<a;i++) {
		scanf("%d",&stackA[i]);
	}
	for(int i=0;i<b;i++) {
		scanf("%d",&stackB[i]);
	}
	int ans=0,sum=0,i;
	for(i=0;i<a;i++) {
		if(sum+stackA[i]<=m) {
			sum = sum + stackA[i];
		}
		else {
			break;
		}
	}
	int x = i , y = 0;
	ans = x+y;
	/*(x,y) is valid pair now increment y and check if (x,y) is valid , if not valid
	then decrement x till that pair is valid
	out of all valid pairs select the one with maximum sum */
	while(y<b && x>=0) {
		sum = sum + stackB[y++];
		while(sum > m && x > 0) {
			//Not valid pair
			sum = sum - stackA[--x];
		}
		if(sum <= m && ans < (x + y)) {
			ans = x + y;
		}
	}
	printf("%d \n",ans);
	
	
	return 0;
}

/*
5 4 10
4 2 4 6 1
2 1 8 5 */
//greedy doesn't work .. check for test case like {9,9,9} and {10,1,1,1,1} sum is 13
	
