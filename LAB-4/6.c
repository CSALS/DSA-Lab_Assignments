#include <stdio.h>
int main()
{
    int n,d;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    scanf("%d",&d);
    //sorting
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]); printf("\n");
     //traversing every element
    int left=0,right=n-1,mid,flag=0,sum=-1;
    for(int i=0;i<n;i++)
    {
        //binary search
        left = 0; right =n-1;
        while(left<=right)
        {
            mid = left + ((right-left)/2) ;
            if(arr[mid]==(arr[i]+d))
            {
                sum = arr[mid] + arr[i];
                flag=1;
                break;
            }
            else if(arr[mid]>(arr[i]+d))
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        if(flag==1) break;
    }
    printf("%d \n",sum);
    return 0;
}
/*
6
5 1 101 205 36 19
104
*/
