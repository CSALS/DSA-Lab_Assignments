
#include <stdio.h>
#include <stdlib.h>
#define REP(i,n) for(int i=0;i<n;i++)

int distinct(int *arr , int n)
{
    int ct=0;
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0; j<i ; j++)
        {
            if(arr[i]==arr[j])
                break;
        }
        if(i==j)
        ct++;

    }
    return ct;
}
int main()
{
    int n,m;
    printf("enter");
    scanf("%d",&n);
    scanf("%d",&m);

    int dsu[n];

    int aoe[m][2];
    //printf("%d",n);
    REP(i,m){
        int a,b;
        scanf("%d",&a); scanf("%d",&b);

        aoe[i][0]=a;
        aoe[i][1]=b;
    }
    printf("\n");
    REP(i,n) {
        // i is our node which we remove
        REP(j,n) {
        if(i!=j)
        dsu[j]=j;
        else
            dsu[j]=-1;
        }

        REP(j,m) {
            if(!(aoe[j][0]==i || aoe[j][1]==i))
            {

                int temp=dsu[aoe[j][1]];
                REP(k,n) {
                if(dsu[k]==temp)
                    dsu[k]=dsu[aoe[j][0]];
                }

            }
        }


      int ct = distinct(dsu,n);



        if((ct-1)>=2)
        printf("%d ",i);
    }
    return 0;
}
