#include <stdio.h>
int a[100][2];
int n;


int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i][0]);
		a[i][1] = i;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i][0]>a[j][0])
			{
				int data = a[i][0];
				int index = a[i][1];
				a[i][0] = a[j][0];
				a[i][1] = a[j][1];
				a[j][0] = data;
				a[j][1] = index;
			}
		}
	}
	int ans=0;
	int visited[n]; 
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i] || a[i][1]=i) continue;
		int j=i;
		int count=0;
		while(!visited[j])
		{
			visited[j]=1;
			j=a[j][1];
			count++;
		}
		ans = ans + count - 1;
	}
	printf("%d \n",ans);
}