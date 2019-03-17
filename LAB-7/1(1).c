#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000
int n,x;
int adj[N][N], d1[N], dx[N];

int dfs(int i, int p, int d[])
{
    int j;
    d[i] = d[p]+1;
    for(j=1; j<=n; j++)
    {
        if((adj[i][j] || adj[j][i]) && j!=p)
          dfs(j, i, d);
    }
}

int main()
{
    int i;
    scanf("%d %d", &n,&x);
    for(i=0; i<n-1; i++)
    {
        int a,b;
        scanf("%d %d", &a,&b);
        adj[a][b] = adj[a][b] = 1;
    }

    d1[0]=dx[0]=-1;
    dfs(1, 0, d1);
    dfs(x, 0, dx);

    int ans = 0;
    for(i=1; i<=n; i++)
    {
        if(dx[i]<d1[i])
        {
            if(ans<2*d1[i])
               ans = 2*d1[i];
        }
    }

    printf("\nAns: %d", ans);
    return 0;
}

