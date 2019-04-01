#include <stdio.h>
#include <stdlib.h>
#define min(a,b) a>b ? b:a
int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif
	int k; scanf("%d",&k); //atmost these many projects
	int w; scanf("%d",&w); //current capital
	int n; scanf("%d",&n); //number of projects
	int profit[n],capital[n];
	//int visited[n]; 
	/*for(int i=0;i<n;i++) {
		scanf("%d",&profit[i]);
		visited[i]=0;
	}can be done without visited*/
	for(int i=0;i<n;i++) {
		scanf("%d",&capital[i]);
	}
	//O(k*n)
	while(k != 0) {
		int index=-1,maxProfit=-1;
		for(int i=0;i<n;i++) {
			if(profit[i]>0 && w>=capital[i] && maxProfit<profit[i]) {
				maxProfit = profit[i];
				index = i;
				//visited[i]=1 Should not be here. We should mark the maximum profitable project visited[i] = 1;
			}
		}
		if(index == -1) break;
		k--;
		w = w+profit[index];
		profit[index] = -1;
	}
	printf("%d\n",w);
	return 0;
}

