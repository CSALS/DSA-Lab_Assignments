#include <stdio.h>
#include <math.h>
#include <string.h>
int n,k;
char seen[1000][1000];
int end_seen=0;
int edges[1000];
int end_edges=0;
void dfs(char node[],int k,char arr[])
{
    //printf("Node %s \n",node);
    for(int i=0;i<k;i++)
    {
        char str[1000];
        strcpy(str,node);
        //str = node + arr[i]
        int len = strlen(str);
        str[len]=arr[i];
        str[len+1]='\0';
        //printf("Node %s \n",str);
        int flag=0;
        for(int j=0;j<end_seen;j++)
        {
            if(strcmp(str,seen[j])==0)
             {
                 flag=1;
                 break;
             }
        }
        if(flag!=1) //if string not stored
        {
            strcpy(seen[end_seen],str);
            end_seen++;
            char substr[1000];
            int k1=0;
            for(int i=1;i<strlen(str);i++)
                substr[k1++] = str[i];
            substr[k1] = '\0';
            //printf("substring %s \n",substr);
            dfs(substr,k,arr);
            edges[end_edges++] = i;
        }

    }
}

void deBruijn(int n,int k,char arr[])
{
  int len_of_node = n-1;
  char startingNode[1000];
  for(int i=0;i<n-1;i++)
        startingNode[i] = arr[0];
        startingNode[n-1] = '\0';
  //get the starting node and do dfs on it
  //printf("starting node %s \n",startingNode);
  dfs(startingNode,k,arr);

  //for(int i=0;i<end_edges;i++)
   // printf("%d ",edges[i]);
 // printf("\n");
  char s[1000];
  int l = pow(k,n);
 // printf("%d \n",l);
  int ending=0;
  for(int i=0;i<l;i++)
  {
     s[ending++]=arr[edges[i]];
  }
  s[ending]='\0';
  strcat(s,startingNode);
  printf("%s \n",s);
}

int main()
{
    scanf("%d %d",&n,&k);
    char arr[k];
    for(int i=0;i<k;i++)
        scanf(" %c",&arr[i]);
    deBruijn(n,k,arr);
    return 0;
}
