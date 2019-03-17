
#include <stdio.h>

int main()
{
    int n,k,s,T;
    scanf("%d %d %d %d",&n,&k,&s,&T);
    int petrol[k];
    for(int i=0;i<k;i++)
        scanf("%d",&petrol[i]);
    int cost=99999;
    while(n--)
    {
        int c,v;
        scanf("%d %d",&c,&v);
        int ip=v;
        int pos1=0;
        int t=0;
        petrol[k]=s;

        for(int i=0;i<=k;i++)
        {
            int f1 = ip - (petrol[i]-pos1);
            if(f1<0)
                continue;
            t = t + ((petrol[i]-pos1)*2);
            if(f1>=(petrol[i]-pos1))
                t = t - (petrol[i]-pos1);
            else
                    t = t-f1;
            pos1 = petrol[i];
        }
        if(t<=T)
            if(c<cost)
            cost=c;
    }
    printf("%d \n",cost);
    return 0;
}
