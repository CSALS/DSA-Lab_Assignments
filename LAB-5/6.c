#include <stdio.h>
int inversions=0;

void merge(int arr[],int l,int m,int r)
{
	int n1 = (m-l)+1;
	int n2 = (r-m);
	int i,j,k;
	int left[n1],right[n2];
	for(i=0;i<n1;i++)
		left[i] = arr[l+i];
	for(j=0;j<n2;j++)
		right[j] = arr[m+1+j];

	for(i=0;i<n1;i++) printf("%d ",left[i]); printf("\n");
	for(j=0;j<n2;j++) printf("%d ",right[j]); printf("\n");



	for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(left[i]>right[j])
                inversions++;
        }
    }

}

void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

int main()
{
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++)
			scanf(" %d",&arr[i]);

		mergeSort(arr,0,n-1);
		printf("%d \n",inversions);

		return 0;
}
