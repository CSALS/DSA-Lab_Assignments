#include <stdio.h>

int arr[50][50],n,m,q[50],visited[50],f=0,r=-1,mark[50],uni[50];

void bfs(int v)
{
	for(int i=0;i<n;i++)
	{
		if(arr[v][i]==1 && visited[i]==0)
		{
			q[++r]=i;
			mark[i] = mark[v] + 1;
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


	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a-1][b-1]=1;
		arr[b-1][a-1]=1;
	}
	scanf(" %d",&m);
	for(int i=0;i<m;i++)
	{
		int x;
		scanf(" %d",&x);
		uni[x-1]=1;
	}

	visited[0]=1;
	mark[0]=1;
	bfs(0);



	for(int i=0;i<n;i++)
        printf("%d ",mark[i]);

	int min=100000,index=0;
	for(int i=n-1;i>=0;i--)
	{
		if(mark[i]<=min && uni[i]==1 )
		{
			min = mark[i];
			index = i;
		}
	}

	printf("%d \n",index+1);

}

/*
5
0 1
0 4
1 2
4 3
f=0 r=-1
void bfs(int v)
{
	for(int i=0;i<n;i++)
	{
		if(arr[v][i]==1 && visited[i]==0)
		q[++r] = i;
	}
	if(f<=r)
	{
		visited[q[f]]=1;
		bfs(q[f++]);
	}

}




*/
