#include <stdio.h>

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int arr[n][m];
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf(" %d",&arr[i][j]);
    }
    printf("\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    if(!k)
    {
        for(i=0;i<m-1;i++)
        {
            for(j=i+1;j<m;j++)
            {
                printf(" %d %d \n",i,j);
            }
        }
    }
    else
    {
         for(i=0;i<m-1;i++)
         {
            for(j=i+1;j<m;j++)
            {
                printf(" %d %d \n",j,i);
            }
         }
    }

    for(int x=0;x<n;x++)
    {
        for(int y=0;y<m;y++)
            printf("%d ",arr[x][y]);
        printf("\n");
    }
    return 0;
}
