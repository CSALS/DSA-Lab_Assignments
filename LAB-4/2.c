#include <stdio.h>
#include <math.h>
int sum=0,n,k;
void sum1(int v)
{
	if(v==0)
		return;
	else
	{
		sum = sum + v;
		sum1(floor(v/k));
	}
}

int main()
{
	int i;
	printf("enter \n");
	scanf(" %d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		sum1(i);
		if(sum==n)
		{
			break;
		}
		else sum=0;
	}
	printf("%d \n",i);
	return 0;
}
