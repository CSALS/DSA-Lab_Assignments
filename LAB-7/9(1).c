#include<stdio.h>
int i,j;
#define swap(a,b) a=a+b-(b=a)
int  intcontact(int a,int b)
{
	int t=10;
	while(b>=t)
		t*=10;
  return a*t+b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(intcontact(a[i],a[j])<intcontact(a[j],a[i]))
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}

