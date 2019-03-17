#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j]= temp;
			}
		}
	}

	int low=0;
	int high=n-1;
	int count=0;
	while(low<=high)
	{
		if(arr[high]<=(2*arr[low]))
			break;
		int x = arr[low];
		int y = arr[high];
		int countx=0,county=0;
        for(int i=low;i<=high;i++) //NOT i<high why?
		{
			if(arr[i]==x) countx++;
			if(arr[i]==y) county++;
		}

		if(countx<=county)
		{
			count=count+countx;
			low=low+countx;
			count=count+county-1;
			high=high-county+1;
		}
		else
		{
			count=count+county;
			high=high-county;
			count=count+countx-1;
			low=low+countx-1;
		}
	}
	/*int i,j;
	int low=0;
	int high=n-1;
	int count=0;
	while(low<=high)
    {
        if(arr[high]<=(2*arr[low]))
        	break;
        int x=arr[low];
        int y=arr[high];
        int countx=0;
        int county=0;
        for( i=low;i<=high;i++)
        {
        	if(x==arr[i])
        		countx++;
        	if(y==arr[i])
        		county++;
        }
        if(countx<=county)
        {
        	count=count+countx;
        	low=low+countx;
        	count=count+county-1;
        	high=high-county+1;
        }
        else
        {
        	count=count+county;
        	high=high-county;
        	count=count+countx-1;
        	low=low+countx-1;
        }
	}*/
	printf("%d",count);
}
