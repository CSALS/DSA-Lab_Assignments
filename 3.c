#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define max(a,b) (a>b) ? a:b
#define min(a,b) (a<b) ? a:b
//DP approach 
//Timed out for few cases
int floorSqrt(int n) {
	if(n == 0 || n == 1)
		return n;
	int i=1,result=1;
	while(result <= n) {
		i++; result = i*i;
	}
	return (i-1);
}
int dp[INT_MAX] = {0};
int moves(int n) {
	if(n <= 3)
		return n;
	if(dp[n] > 0) return dp[n];
	int minMove = INT_MAX;
	for(int i=2;i<=floorSqrt(n);i++) {
		if(n % i == 0) {
			int maxFactor = n/i;
			minMove = min(minMove , 1+moves(maxFactor));
		}
	}
	minMove = min(minMove , 1+moves(n-1));
	dp[n] = minMove;
	return minMove;
}
int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif
	int q; scanf("%d",&q);
	while(q--) {
		int n; scanf("%d",&n);
		printf("%d\n",moves(n));		
	} 

	return 0;
}


