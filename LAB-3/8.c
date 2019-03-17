#include <stdio.h>
int n,m;
int aoe[1000][2];
int visited[1000];
int ct;

void dfs(int v,int y)
{
	visited[v]=1;
	for(int i=0;i<m;i++)
	{
		int w;
		if(aoe[i][0]==v)
			w = aoe[i][1];
		else
			continue;

		if(visited[w]==0)
		{
			if(w==y)
			{
				ct=1;

			}
			dfs(w,y);
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf(" %d %d",&aoe[i][0],&aoe[i][1]);
	}


	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int x,y;
		ct=0;
		for(int i=1;i<=n;i++) visited[i]=0;
		scanf(" %d %d",&x,&y);
		dfs(x,y);
		if(ct==1) printf("YES \n");
		else printf("NO \n");
	}

	return 0;
}
