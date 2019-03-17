#include <stdio.h>
int da[1000];

int min(int x,int y)
{
    if(x>y)
        return y;
    else
        return x;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&da[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(da[i]>da[j])
            {
                int temp = da[j];
                da[j] = da[i];
                da[i] = temp;
            }
        }
    }
    int top=0;
    int sum=0;
    for(int i=1;i<n;i++)
    {
        if(da[i]>top)
            top++;
        sum = sum + da[i]-1;
    }
    sum = sum + min(top,da[n]-1);
    printf("%d \n",sum);
    return 0;
}
