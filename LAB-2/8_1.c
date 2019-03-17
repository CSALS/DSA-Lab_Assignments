#include<stdio.h>

int a[100][100],visit[100];

int main()
{
    int n,m,z,x;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&z,&x);
        a[z][x]=1;
        a[x][z]=1;
    }
    int t;
    scanf("%d",&t);

    int mark[n],visited[n],c[n];

    for(int l=0;l<n;l++)
    {
        for(int i=0;i<n;i++)
        {
            mark[i]=0;visited[i]=0;c[i]=0;
        }
        int count=0;
    int temp=1;
    visited[l]=1;
    
    mark[l]=0;
    c[count]=l;
    while(count!=temp)
    {
        
        

        for(int i=0;i<n;i++)
        {
            if(a[c[count]][i]==1&&visited[i]==0)
             {
                 c[temp]=i;
                 temp++;
                 mark[i]=mark[c[count]]+1;
                 visited[i]=1;
              //   printf("%d %d\n",c[count],i);
             }
        }
        visited[c[count]]=1;
        
     count++;
    }

    for(int i=0;i<n;i++)
      if((mark[l]-mark[i]==t||mark[l]-mark[i]==-t)&&visit[i]==0)
             printf("%d %d\n",l,i);

             visit[l]=1;

    }
}