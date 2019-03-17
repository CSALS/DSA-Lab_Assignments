#include <stdio.h>
#include <stdbool.h>
int n,m,t,len;

int rowNbr[4] = {-1,0,1,0};
int colNbr[4] = {0,1,0,-1};

//int visited[1000][1000]; // 0 -> not visited , 1 -> visited

/*void flush()
{
    for(int a=0;a<1000;a++)
    {
        for(int b=0;b<1000;b++)
            visited[a][b]=0;
    }
}*/

bool dfs(char input[],char arr[][m],int row,int col,int k)
{
    if(input[k]!=arr[row][col])
        return false;

    if(k>=len-1)
        return true;



    /*char t = arr[row][col];
    arr[row][col] = '#';*/
 //   visited[row][col] = 1;

    for(int d=0;d<4;d++)
    {
        int new_row = row + rowNbr[d];
        int new_col = col + colNbr[d];
        if(new_row>=0 && new_row<n && new_col>=0 && new_col<m)
        {
            if(dfs(input,arr,new_row,new_col,k+1))
                return true;
        }
    }
    return false;
}

bool search(char input[],char arr[][m])
{
    for(int i=0;i<n;i++)
    {
        //flush();
        for(int j=0;j<m;j++)
        {
            if(dfs(input,arr,i,j,0))
                return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d %d",&n,&m);
    char arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf(" %c",&arr[i][j]);
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        char input[10000];
        int lennn;
        scanf("%s",&input);
        for(lennn=0;lennn<10000;lennn++)
            if(input[lennn]=='\0')
                break;
        // i - has length
        len = lennn;
        if(search(input,arr))
            printf("YES \n");
        else
            printf("NO \n");
    }
    return 0;
}
