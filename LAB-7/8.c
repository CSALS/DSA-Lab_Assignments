#include <stdio.h>

int check_Number(int n)
{
    int prev_digit=-1;
    while(n)
    {
        int curr_digit = n%10;
        if(prev_digit==-1)
        {
            prev_digit=curr_digit;
        }
        else
        {
            if(!((curr_digit-prev_digit)==1 || (curr_digit-prev_digit)==-1))
            {
                return 0;
            }
        }
        prev_digit=curr_digit;
        n=n/10;
    }
    return 1;
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        if(i<10)
            printf("%d ",i);
        else
        {
            if(check_Number(i))
                printf("%d ",i);
        }
    }
    return 0;
}
