#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
int n,a[10000],c[10000],sum=0;
int pro(int i)
{
	int b[n],mini=100000,t=(sum/i);
	for(int p=0;p<(1<<n);p++)
	{
	    int s=0;
		for(int j=0;j<n;j++)
		{
			if(p&(1<<j))
				s++;
		}
		if(s == i)
		{
			for(int j=0;j<n;j++) b[j]=0;
			for(int j=0;j<n;j++)
			{
				if(p&(1<<j))
					b[j] = t;
			}
			int su=0;
			for(int j=0;j<n;j++)
			{
				su = su + ((max(a[j],b[j])-min(a[j],b[j]))*c[j]);
			}
			mini = min(mini,su);
		}
	}
	return mini;
}


int main()
{
	int num=0,mi=10000,ht=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum = sum + a[i];
	}
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);

	for(int i=1;i<=n;i++)
	{
		if(sum%i==0)
		{
			int val = pro(i);
			if(val < mi)
			{
				mi = val;
				num = i;
				ht = sum/i;
			}
		}
	}
	printf("%d %d %d",mi,num,ht);
}

