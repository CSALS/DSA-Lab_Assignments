#include <stdio.h>
//spiral matrix
//N is odd then left up right down
//N is even then right down left up
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n][n];
	
	int k=n*n,c1=0,c2=n-1,r1=0,r2=n-1;
	
	while(k>=1)
	{
		if(n%2==0){
		//right
		for(int i=c1;i<=c2;i++)
		arr[r1][i]=k--;
		//down
		for(int i=r1+1;i<=r2;i++)
		arr[i][c2]=k--;
		//left
		for(int i=c2-1;i>=c1;i--)
		arr[r2][i]=k--;
		//up
		for(int i=r2-1;i>=r1+1;i--)
		arr[i][c1]=k--;

		c1++; c2--;
		r1++; r2--;
		}

		else{
		//left
		for(int i=c2;i>=c1;i--)
		arr[r2][i]=k--;
		//up
		for(int i=r2-1;i>=r1;i--)
		arr[i][c1]=k--;
		//right
		for(int i=c1+1;i<=c2;i++)
		arr[r1][i]=k--;
		//down
		for(int i=r1+1;i<=r2-1;i++)
		arr[i][c2]=k--;

		c1++; c2--;
		r1++; r2--;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		printf("%d \t",arr[i][j]);
		printf("\n");
	}

	return 0;
}