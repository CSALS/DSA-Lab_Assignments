#include <stdio.h>

int count(int dsu[],int e)
{
    int ct=0;

    for(int i=0;i<e;i++)
    {
        int j;
        for(j=0;j<i;j++)
        {
            if(dsu[i]==dsu[j])
                break;
        }
        if(i==j)
            ct++;
    }
}



int main()
{
	int v,e;
	scanf("%d %d",&v,&e);
	int arr_G[v][v],aoe_G[e][2];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		scanf(" %d",&arr_G[i][j]);
	}

	int ct=0,flag;
	for(int i=0;i<v;i++)
	{
        for(int j=0;j<v;j++)
	    {
	        flag=0;
            if(arr_G[i][j]==1)
            {
                for(int k=0;k<ct;k++)
                {
                    if( (aoe_G[k][0]==i && aoe_G[k][1]==j) || (aoe_G[k][0]==j && aoe_G[k][1]==i) )
                    { flag=1; break;}
                }
                if(flag==0)
                {
                    aoe_G[ct][0]=i;
                    aoe_G[ct][1]=j;
                    ct++;
                }
            }
	    }
	}


	for(int i=0;i<ct;i++) printf("%d %d \n",aoe_G[i][0],aoe_G[i][1]);
	int new_arr[e][e];
	for(int i=0;i<e;i++)
    {
        for(int j=0;j<e;j++)
            new_arr[i][j]=0;
    }

    for(int i=0;i<e;i++)
    {
        int a=aoe_G[i][0];
        int b=aoe_G[i][1];
        for(int j=i+1;j<e;j++)
        {
            int c=aoe_G[j][0];
            int d=aoe_G[j][1];
            if(a==c || a==d || b==c || b==d)
            {
                new_arr[i][j]=1;
                new_arr[j][i]=1;
            }
        }
    }

    for(int i=0;i<e;i++)
    {
        for(int j=0;j<e;j++)
            printf("%d ",new_arr[i][j]);
        printf("\n");
    }

    int dsu[e];
    for(int i=0;i<e;i++)
    {
        // i node we remove
        for(int j=0;j<e;j++)
        {
            if(i!=j) dsu[j]=j;
            else dsu[j]=-1;
        }

        for(int j=0;j<e;j++)
        {
            for(int k=0;k<e;k++)
            {
                if(new_arr[j][k]==1 && (j!=i || k!=i) )
                {
                    int temp = dsu[k];
                    for(int x=0;x<e;x++)
                    {
                        if(dsu[x]==temp)
                            dsu[x] = dsu[j];
                    }
		    new_arr[k][j]==0;
                }
            }
        }

        int ct = count(dsu,e);
        if(ct-1>=2) printf("connected componenet");

    }

	return 0;
}
/*
5 5
0 1 1 1 0
1 0 1 0 0
1 1 0 0 0
1 0 0 0 1
0 0 0 1 0

*/
