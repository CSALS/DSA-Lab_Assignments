#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
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
	int n; scanf("%d",&n);
	int arr[n][n];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	}
	/*for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			printf("%d ",arr[i][j]); printf("\n");
	}*/
	int answer=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	for(int r=i;r<n;r++)
	for(int c=j;c<n;c++)
	{
		//one sub matrix ready
		int oneCount=0;
		for(int l1=i;l1<=r;l1++)
			for(int l2=j;l2<=c;l2++)
				//printf("%d ",arr[l1][l2]); printf("\n");
				if(arr[l1][l2]==1)
					oneCount++;
		if(oneCount==1)
			answer++;
	}
	printf("%d \n",answer);
    return 0;	
}


