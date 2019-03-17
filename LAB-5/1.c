#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);

		int rg[n][2],ind[211],rind[n];
		for(int i=0;i<n;i++)
			scanf("%d %d",&rg[i][0],&rg[i][1]);
			if(n==2)
		{
			printf("IM\tCA");
			continue;
		}
		for(int i=0;i<211;i++) ind[i]=0;
		int c=0;
		for(int i=0;i<n;i++)
		{
			int flag=0;
			for(int j=rg[i][0];j<=rg[i][1];j++)
			{
				if(ind[j]!=0)
					flag=ind[j];
			}
			if(flag==0)
			{
				for(int j=rg[i][0];j<=rg[i][1];j++)
					ind[j]=c+1;
					rind[i]=c+1;

			}
			else
			{
				for(int j=rg[i][0];j<=rg[i][1];j++)
					ind[j]=flag;
					rind[i]=flag;
			}
			c++;
		}
		int ca=0; int im=0;
		for(int i=0;i<n;i++)
		{
			if(rind[i]%2==0) ca++;
			else im++;
		}
		if(ca==n || im==n)
			printf("-1\n");
		else
		{
			for(int i=0;i<n;i++)
			{
				if(rind[i]%2==0) printf("CA \t");
				else printf("IM \t");
			}
			printf("\n");
		}

	}
}
