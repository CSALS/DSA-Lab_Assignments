#include<stdio.h>

int a[1000][1000];

void dfs(int n,int visited[n][2],int i)
{

    printf("%d",visited[i][0]);
    visited[i][1]=1;

    for(int j=0;j<100;j++)
    {
        if(a[visited[i][0]][j]==1)
        {
            for(int k=0;k<n;k++)
              if(visited[k][0]==j&&visited[k][1]==0)
                 dfs(n,visited,k);
        }
    }

}


int main()
{
    for(int i=0;i<100;i++)
      for(int j=0;j<100;j++)
        a[i][j]=0;
    int n;
    scanf("%d",&n);
    int b[n][2],visited[n][2];
    for(int i=0;i<n;i++)
      visited[i][1]=0;
    for(int i=0;i<n;i++)
      {scanf("%d",&b[i][0]);visited[i][0]=b[i][0];}
    for(int i=0;i<n;i++)
      scanf("%d",&b[i][1]);

    int delta;
    scanf("%d",&delta);
    printf("%d\n",delta);
    for(int i=0;i<n;i++)
      printf("%d %d \n",b[i][0],b[i][1]);

    for(int i=0;i<n-1;i++)
      for(int j=i+1;j<n;j++)
      {
          if(b[i][1]-b[j][1]>=delta||b[j][1]-b[i][1]>=delta){
            a[b[i][0]][b[j][0]]=1;
            a[b[j][0]][b[i][0]]=1;}
      }

      for(int i=0;i<4;i++){
       for(int j=0;j<4;j++)
           printf("%d ",a[i][j]);
           printf("\n");}

      
      visited[0][1]=1;
      dfs(n,visited,0);

      int cnt=0;
      int p=0;
      while(p==0)
      {  
          printf("\n");
          cnt++;
          int k=0;
          for(int i=0;i<n;i++)
            if(visited[i][1]==0)
              k=i;

           if(k!=0)
             dfs(n,visited,k);
           else
             p=1;   
      }

printf("\n%d",cnt);

}
