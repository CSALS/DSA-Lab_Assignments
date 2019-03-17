#include <stdio.h>
int n,m;
int aoe[1000][2];
int visited[1000];
int ct;

void dfs(int v)
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
			ct++;
			dfs(w);
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



    for(int i=1;i<=n;i++)
    {
        ct=0;
		for(int i=1;i<=n;i++) visited[i]=0;
        dfs(i);
        if(ct==n-1)
            printf(" %d ",i);
    }


	return 0;
}
