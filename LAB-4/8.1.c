#include <stdio.h>

int n,k,arr[1000];

int binarysearch(int left,int right)
{
    if(right < left)
        return -1;

    int mid = (left+right)/2 ;
    if(k == arr[mid])
        return mid;
    if(k > arr[mid])
        return binarysearch(mid+1,right);
    else
        return binarysearch(left,mid-1);
}
int find_pivot(int low,int high)
{
    if(high<low) return -1;
    if(high==low) return low;

    int mid = (low+high)/2;
    if(mid<high && arr[mid]>arr[mid+1])
        return mid;
    if(mid>low && arr[mid]<arr[mid-1])
        return mid-1;
    if(arr[low]>=arr[mid])
        //left
        return find_pivot(low,mid-1);
    else
        //right
        return find_pivot(mid+1,high);

}
int new_binarysearch()
{
    int pivot = find_pivot(0,n-1);

    if(pivot==-1)
       return binarysearch(0,n-1);
    if(arr[pivot]==k)
        return pivot;
    if(arr[0]<=k)
        //left sub-array
        return binarysearch(0,pivot-1);
    if(arr[0]>k)
        //right sub-array
        return binarysearch(pivot+1,n-1);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&k);

    printf("%d \n",new_binarysearch());
    return 0;
}
