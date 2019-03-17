#include <stdio.h>

int main()
{
    while(1) {
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<n;i++)
	{
		if(arr[i]==-1) continue;
		if(arr[i]==arr[i+1])
		{
			arr[i]=-1; arr[i+1]=-1;
		}
	}
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=-1)
		{
			printf("%d \n",arr[i]);
			flag=1;
			break;
		}
	}
    }
	return 0;
}
