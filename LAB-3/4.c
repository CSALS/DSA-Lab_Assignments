#include <stdio.h>
#include <stdbool.h>
int n;
int arr[1000][1000];
int path[1000];
int end=0,result=0;
int minDistance(int dist[],bool set[])
{
	int min = 10000,index;
	for(int i=0;i<n;i++)
	{
		if(dist[i]<min && set[i]==false)
		{
			min = dist[i];
			index = i;
		}
	}
	return index;
}
void printPath(int parent[],int j)
{
	if(parent[j]==-1) return;
	printPath(parent,parent[j]);
	path[end++]=j;
}
int main()
{
	int x,y;
	scanf("%d %d %d ",&n,&x,&y);
	int temp=n-1;
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
			arr[i][j]=0;
	while(temp--)
	{
		int x1,y1;
		scanf(" %d %d",&x1,&y1);
		arr[x1][y1]=1;
		arr[y1][x1]=1;
	}

	for(int src=0;src<n;src++)
    {
        int dist[n],parent[n];
        bool set[n];
        for(int i=0;i<n;i++)
        {
            dist[i]=10000;
            parent[i]=-1; set[i]=false;
        }
        dist[src]=0;
        parent[src]=-1;
        //shortest path for all vertices
        for(int count=0;count<n-1;count++)
        {
            int u = minDistance(dist,set);
            set[u] = true;

            //update all adjacent
            for(int v=0;v<n;v++)
            {
                if(set[v]==false && arr[u][v]==1 && dist[u]!=10000 && dist[u]+arr[u][v] < dist[v])
                {
                    dist[v] = dist[u]+arr[u][v] ;
                    parent[v] = u;
                }
            }
        }
        for(int j=0;j<n;j++)
        {   if(j==src) continue; end=0;
            path[end++]=src; printPath(parent,j); printf("\n");
            int flag=0;
            for(int i=0;i<end;i++)
            {
                printf(" %d ",path[i]);
                if(path[i]==x) flag=1;
                if(path[i]==y && flag==1) { flag=-1; }
            }
            if(flag!=-1) result++;
        }

    }
    printf("%d ",result);

	return 0;
}
