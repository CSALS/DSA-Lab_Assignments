#include<stdio.h>
int n,arr[1000],k,flag=-1;

int binary_search(int left,int right)
{
	if(left>right)
	{
		flag=left+1;
		return -1;
	}

	int mid = (left+right)/2;
		if(arr[mid]==k)
			return mid;
		if(k>arr[mid])
			return binary_search(mid+1,right);
		else if(k<arr[mid])
			return binary_search(left,mid-1);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&k);
	int left = 0 , right = n-1;
	int index = binary_search(left,right);
	if(index!=-1)
		printf("Naruto %d\n",index+1);
	else
		printf("Sasuke %d\n",flag);
	return 0;
}
