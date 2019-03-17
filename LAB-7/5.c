#include <stdio.h>
int n,m,s,t;
int dist[1000][1000];
int graph[1000][1000];
int main()
{
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dist[i][j]=100000;
			if(i==j) dist[i][j]=0;
			graph[i][j]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		dist[u][v]=1;
		dist[v][u]=1;
		graph[u][v]=1;
		graph[v][u]=1;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	int count=0;
	for(int u=1;u<n;u++)
	{
		for(int v=u+1;v<=n;v++)
		{
			if(graph[u][v]==0) //no edge b/w these 2 vertices
			{
				int x = dist[s][u] + dist[v][t] + 1;
				int y = dist[s][v] + dist[u][t] + 1;
				if(x>=dist[s][t] && y>=dist[s][t])
					count++;
			}
		}
	}
	printf("%d \n",count);

	return 0;
}
