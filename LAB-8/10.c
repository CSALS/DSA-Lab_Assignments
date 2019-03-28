//BRUTE FORCE APPROACH
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

int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif
	int n,k,op=0;
	scanf("%d %d",&n,&k);
	char signals[n];
	for(int i=0;i<n;i++) {
		scanf(" %c",&signals[i]);
	}
	for(int i=0;i<n-1;i++) {
		int m = min(n,i+k-1); 
		while(signals[i]!='G') {
			op++;
			for(int j=i;j<=m;j++) {
				if(signals[j]=='G') signals[j]='R';
				else if(signals[j]=='R') signals[j]='Y';
				else if(signals[j]=='Y') signals[j]='G';
			}
		}
	}
	//printf("%d\n",op);
	if(signals[n-1]=='R') op = op+2;
	else if(signals[n-1]=='Y') op = op+1;
	printf("%d\n",op);
    return 0;	
}


