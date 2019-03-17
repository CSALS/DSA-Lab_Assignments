#include <stdio.h>
//n less than 1000
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n][n];
	int prime[n*n];
	int ct=0,primeno=2;
	while(ct<n*n)
	{
	   int isPRIME = 1;
	   //-1 not prime , 1 prime
	   for(int i=2;i<primeno;i++){
		if(primeno%i==0)
		{ isPRIME=-1; break; }	
	   }
	   if(isPRIME==1){
		prime[ct]=primeno;
		ct++;
	   }
	   primeno++;	   	
	}
	
	for(int i=0;i<n*n;i++)
	printf("%d ",prime[i]);
	
	int k=1,c1=0,c2=n-1,r1=0,r2=n-1;
	int m=n*n-1;
	while(k<=n*n)
	{
	   	if(n%2==0){
	   	//right
		for(int i=c1;i<=c2;i++)
		{arr[r1][i]=prime[m];m--;}
		//down
		for(int i=r1+1;i<=r2;i++)
		{arr[i][c2]=prime[m];m--;}
		//left
		for(int i=c2-1;i>=c1;i--)
		{arr[r2][i]=prime[m];m--;}
		//up
		for(int i=r2-1;i>=r1+1;i--)
		{arr[i][c1]=prime[m];m--;}

		c1++; c2--;
		r1++; r2--;
		}

		else{
		//left
		for(int i=c2;i>=c1;i--)
		{arr[r2][i]=prime[m];m--;}
		//up
		for(int i=r2-1;i>=r1;i--)
		{arr[i][c1]=prime[m];m--;}
		//right
		for(int i=c1+1;i<=c2;i++)
		{arr[r1][i]=prime[m];m--;}
		//down
		for(int i=r1+1;i<=r2-1;i++)
		{arr[i][c2]=prime[m];m--;}

		c1++; c2--;
		r1++; r2--;
		}
		k++;
	}
	printf("\n"); printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		printf("%d \t",arr[i][j]);
		printf("\n");
	}


	return 0;
}