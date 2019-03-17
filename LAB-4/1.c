#include <stdio.h>
int no_of_items=0,cost=10000,s;
void printcombination(int arr[],int n,int r)
{
	int data[r];
	findcombination(arr,data,0,n-1,0,r,n);
}
int findindex(int data,int n,int arr[])
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==data)
			return (i+1);
	}
}
void findcombination(int arr[],int data[],int start,int end,int index,int r,int n)
{
	//index - current index in data[]
	//start , end - in arr[]

	if(index==r)
	{
		//current combination is ready
		int sum=0;
		for(int i=0;i<r;i++)
		{
			sum = sum + data[i] + r*findindex(data[i],n,arr);
		}
		if(sum<=s)
		{
			if(r>no_of_items)
			{
                    cost=sum;
                    no_of_items=r;
			}
			else if(r==no_of_items)
            {
                if(sum<cost)
                {
                    cost=sum;
                }
            }
		}
	}
	else
	{
		for(int i=start;i<=end && end-i+1>=r-index;i++)
		{
			data[index] = arr[i];
			findcombination(arr,data,i+1,end,index+1,r,n);
		}
	}
}

int main()
{
	int n;
	scanf("%d %d",&n,&s);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int r=1;r<=n;r++)
	printcombination(arr,n,r);
	printf("%d %d \n",no_of_items,cost);
	return 0;
}
