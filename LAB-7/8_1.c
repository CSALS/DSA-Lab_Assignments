#include<stdio.h>
int i,j;
int abs(int m)
{
    return m>0 ? m : -1*m;
}
int check_steppingnumber(int n)
{
    int prevdigit=-1;
    while(n)
    {
        int currdigit=n%10;
        if(prevdigit==-1)
        {
            prevdigit=currdigit;
        }
        else
        {
            if(abs(currdigit-prevdigit)!=1)
            {
                return 0;
            }
        }
        prevdigit=currdigit;
        n=n/10;
    }
    return 1;
}
void display_steppingnumbers(int n,int m)
{
    for(i=n;i<=m;i++)
    {
        if(check_steppingnumber(i))
        {
            printf("%d  ",i);
        }
    }
}
int main()
{
    int n,start=0;
    scanf("%d",&n);
    display_steppingnumbers(start,n);
}

