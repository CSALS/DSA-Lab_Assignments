#include <stdio.h>
int adj[100][100],d1[100],dx[100];

void dfs(int i,int p,int d[])
{
    d[i] = d[p]+1;
    for(int j=1;j<=n;j++)
        if(arr[i][j] && j!=p)
            dfs(j,i,d);

}
int main()
{
    int n,x;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a][b] = adj[b][a] = 1;
    }
    d1[0] = dx[0] = -1;
    dfs(1,0,d1);
    dfs(x,0,dx);

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dx[i]<d1[i])
        {
            if(ans<(2*d1[i]))
                ans=(2*d1[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
