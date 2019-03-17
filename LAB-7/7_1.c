#include<stdio.h>
int a=0,ans=0,i,j;
void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}
void bubblesort(int e[])
{
    int done=1;
    while(done!=0)
    {
        done=0;
        for(i=0;i<a-1;i++)
        {
            if(e[i]>e[i+1])
            {
                swap(&e[i],&e[i+1]);
                done++;
            }
        }
    }
}
int find(int p,int e[])
{
    for(i=0;i<a;i++)
    {
        if(e[i]==p)
        {
            return i;
        }
    }
}
int main()
{
    int A[1000];
    char c='c';
    while(c!='\n')
    {
        scanf("%d%c",&A[a],&c);
        a++;
    }
    int B[a];
    for(i=0;i<a;i++)
    {
        B[i]=A[i];
    }
    bubblesort(B);
    int q=0;
    while(q!=a)
    {
        int p=find(B[q],A);
        for(i=0;i<=p;i++)
        {
            if(A[i]>B[q])
            {
                ans++;
            }
        }
        q++;
    }
    printf("%d\n",ans);
    return 0;
}
