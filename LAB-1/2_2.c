#include <stdio.h>
#include <stdbool.h>
#define v 9
#define INT_MAX 10000
int minDistance(int dist[],bool set[])
{
	int min = INT_MAX ;
	int index;
	for(int i=0; i<v ; i++)
	{
		if(set[i]==false && dist[i] <= min)
		{
			min = dist[i];
			index = i;
		}
	}

	return index;
}

void printSolution(int dist[],int shortest[v][v],int src)
{

   for (int i = 0; i < v; i++)
        shortest[src][i] = dist[i];
}

void dijkstra(int graph[v][v],int src,int shortest[v][v])
{
	int dist[v];
	bool set[v];

	for(int i=0;i<v;i++)
	{
		dist[i] = INT_MAX;
		set[i] = false;
	}
	dist[src]=0;

	for(int count=0;count<v-1;count++)
	{
		//picking min distance vertex from set of vertices not yet processed
		int u = minDistance(dist,set);
		//in first iteration always index is 0
		set[u] = true;

		//updating dist value of adjacent vertices
		for(int i =0; i<v; i++)
		{
			/* update dist[i] only if it is not in set , and there is an
				edge from u to i and total weight of path from src to i through u
				is smaller than current value of dist[i] */
			if( !set[i] && graph[u][i] && dist[u] != INT_MAX && dist[u]+graph[u][i] < dist[i] )
				dist[i] = dist[u] + graph[u][i];
		}
	}
	printSolution(dist,shortest,src);
}

int main()
{
   /* int graph[v][v];
	printf("enter adjacency matrix \n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			scanf(" %d",&graph[i][j]);
		}
	} */
	int shortest[v][v];

	int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

	//dijkstra(graph,0);

	for(int i=0; i<v; i++)
    {
        dijkstra(graph,i,shortest);
    }
    int max = 0;
    int u,V;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            printf("%d ",shortest[i][j]);
            if(shortest[i][j]>=max)
            {
                max = shortest[i][j];
                u = i; V = j;
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("%d to %d distance = %d \n",u,V,max);
    // 0 4 0 0 0 0 0 8 0
    // 4 0 8 0 0 0 0 11 0
    // 0 8 0 7 0 4 0 0 2
    // 0 0 7 0 9 14 0 0 0
    // 0 0 0 9 0 10 0 0 0
    // 0 0 4 14 10 0 2 0 0
    // 0 0 0 0 0 2 0 1 6
    // 8 11 0 0 0 0 1 0 7
    // 0 0 2 0 0 0 6 7 0

}
