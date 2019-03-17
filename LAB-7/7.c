
#include <stdio.h>


int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}


int main()
{
    int arr[100],n=0;
    while(1)
    {
        int x;
        scanf("%d",&x);
        if(x==-1) break;
        arr[n++]=x;
    }
    printf("\n%d\n",n);
    printf("%d\n",getInvCount(arr, n));
    return 0;
}
