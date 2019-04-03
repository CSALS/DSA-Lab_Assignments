
#include <stdio.h>
#include <stdlib.h>
int n,m;
int max_cities; int count_of_cities=0;
int price[1000][1000] = {0}; int maxCost=100000; int cost=0;
int visited[1000] = {0};
void rec(int src,int dest) {
	visited[src] = 1; count_of_cities++;
	if(src == dest) {
		if((count_of_cities-2) <= max_cities && cost < maxCost) {
			maxCost = cost;
		}
	}
	else {
		for(int i=0;i<n;i++) {
			if(visited[i] == 0 && price[src][i]!=0) {
				cost = cost + price[src][i];
				rec(i,dest);
				cost = cost - price[src][i];
			}
		}
	}
	visited[src] = 0; count_of_cities--;
}
int main() {
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			price[i][j]=0;
	int x,y,cost;
	for(int i=0;i<m;i++) {
		scanf("%d %d %d",&x,&y,&cost);
		price[x][y] = cost;
	}
	int t; scanf("%d",&t);
	int src,dest;
	while(t--) {
		scanf("%d %d %d",&src,&dest,&max_cities);
		rec(src,dest);
	}
	return 0;
}

