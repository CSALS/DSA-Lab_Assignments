#include <stdio.h>
int arr[50][50],q[50],visited[50],mark[50],n,f=0,r=-1;

void bfs(int v)
{
	for(int i=0;i<n;i++)
	{
		if(arr[v][i]==1 && visited[i]==0)
		{
			q[++r]=i;
			mark[i] = mark[v]+1;
		}
	}
	if(f<=r)
	{
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}

int main()
{
	int v,e;
	scanf("%d %d",&v,&e);
	n=v;
	for(int i=0;i<v;i++)
	{
		mark[i]=0;
		q[i]=0;
		visited[i]=0;
	}
	int aoe[e][2];
	for(int i=0;i<e;i++)
	{
		scanf(" %d %d",&aoe[i][0],&aoe[i][1]);
	}
	int t,ct=0;
	scanf(" %d",&t);
	for(int i=0;i<e;i++)
	{
		arr[aoe[i][0]][aoe[i][1]]=1;
		arr[aoe[i][1]][aoe[i][0]]=1;
	}
	for(int i=0;i<v;i++)
	{
		visited[i]=1;
		mark[i]=1;
		bfs(i);
		for(int j=0;j<v;j++)
		{
			if(mark[i]-mark[j]==t || mark[j]-mark[i]==t)
			ct++;
		}
		for(int k=0;k<v;k++)
		{
			mark[k]=0;
			q[k]=0;
			visited[k]=0;
		}
	}
	printf("%d \n",ct/2);		
	
	return 0;
}