#include <stdio.h>
int n,m;
int graph[100][100];
int new_graph[100][100];
int stack[100];
int visited_1[100];
int visited_2[100];
int end=0;
int min=10000;
int ways=1;
int cost[100];
void push(int i)
{
	stack[end++]=i;
}
int pop()
{
	return stack[--end];
}

void fill_stack(int vertex)
{
	visited_1[vertex]=1;
	//recur for all neighbouring vertices
	for(int i=1;i<=n;i++)
	{
		if(graph[vertex][i]==1 && visited_1[i]==0)
			fill_stack(i);
	}
	//when there are no neighbouring vertices left for the current vertex the control comes here
	push(vertex);
}
void transpose()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(graph[i][j]==1)
			{
				new_graph[j][i]=1;
			}
			if(graph[j][j]==1)
			{
				new_graph[i][j]=1;
			}
		}
	}
}
void dfs(int vertex)
{
	visited_2[vertex]=1;
	//vertex is in one strongly connected component
	//printf("\n %d %d \n",vertex,cost[vertex]);
	//printf("%d %d ",min,ways);
	if(cost[vertex]<min)
		min=cost[vertex];
	else if(cost[vertex]==min)
		ways++;
    //printf("\n %d %d \n",min,ways);
	for(int i=1;i<=n;i++)
	{
		if(visited_2[i]==0 && new_graph[vertex][i]==1)
		{
			dfs(i);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&cost[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a][b]=1;
	}
	for(int i=1;i<=n;i++)
	{
		visited_2[i]=0;
		visited_1[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(visited_1[i]==0) //that vertex not visited
		fill_stack(i);
	}
	transpose();
	int ans_ways=1;
	int ans_cost=0;
	for(int i=end-1;i>=0;i--)
	{
		int value=pop();
		if(visited_2[value]==0)
		{
			min=10000;
			ways=1;
			dfs(value);
			//printf("%d %d \n",min,ways);
			ans_cost=ans_cost+min;
			ans_ways=ans_ways*ways;
		}
	}
	printf("%d %d\n",ans_ways,ans_cost);

	return 0;
}
