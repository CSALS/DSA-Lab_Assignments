#include <stdio.h>
#include <stdbool.h>
int arr[1000][1000];
int n,count;

void dfs(int row,int col,bool visited[][n])
{
	int rowNbr[] = {-1,-1,-1,0,0,1,1,1};
	int colNbr[] = {-1,0,1,-1,1,-1,0,1};
	visited[row][col]=true;

	//DFS on all 8 neighbours
	for(int k=0;k<8;k++)
	{
		int new_row = row+rowNbr[k];
		int new_col = col+colNbr[k];
		if(new_row>=0 && new_row <n && new_col>=0 && new_col<n && arr[new_row][new_col] && !visited[new_row][new_col])
		{
			//can include in this region
			count++;
			dfs(new_row,new_col,visited);
		}
	}
}

int largestRegion()
{
	bool visited[n][n];
	int result=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j] && !visited[i][j])
			{
				//cell value is 1 & not visited
				//new region found
				//count stores size of this region
				count=1;
				dfs(i,j,visited);

				if(result<count)
					result = count;
			}
		}
	}
	return result;
}

int main()
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	}
	printf("%d \n",largestRegion());
	return 0;
}