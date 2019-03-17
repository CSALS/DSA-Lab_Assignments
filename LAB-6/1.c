#include<stdio.h>
void sort(int n,int arr[n])
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main()
{
    while(1)
    {
        int n;
    scanf("%d",&n);
    int arr[n],connection[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        connection[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            scanf("%d",&a);
            if(j>i)
            continue;
            if(a==1)
            {
                for(int k=0;k<n;k++)
                {
                    if(connection[k]==connection[j])
                        connection[k] = connection[i];
                }
                //connection[j] = connection[i];
            }
        }
    }
    int stack[100][100]={};
    int ptr[100]={}; //length of each row in stack
    int ptr2[100]={};
    for(int i=0;i<n;i++)
    {
        int a=connection[i];
        int b=ptr[a];
        stack[a][b]=arr[i];
        ptr[a]=ptr[a]+1;
    }
     printf("\n");
    for(int i=0;i<n;i++)
        printf(" %d ",connection[i]);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        sort(ptr[i],stack[i]);
    }
    for(int i=0;i<n;i++)
    {
        int a =connection[i];
        int b = ptr2[a];
        printf("%d",stack[a][b]);
        ptr2[a]=ptr2[a]+1;
    }
    printf("\n");
    }

    return 0;
}
