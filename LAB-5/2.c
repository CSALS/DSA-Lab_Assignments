#include <stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n],b[m];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);

	//SORTING 1st array
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(b[i]==a[j])
			{
				printf("%d ",a[j]);
				a[j]=-1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=-1)
			printf("%d ",a[i]);
	}

	return 0;
}
