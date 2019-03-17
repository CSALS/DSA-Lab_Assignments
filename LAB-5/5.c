https://www.geeksforgeeks.org/find-largest-multiple-3-array-digits-set-2-time-o1-space/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int sum=0;
void printArray(int arr[],int n)
{
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]!=-1)
		printf("%d",arr[i]);
	}
	printf("\n");
}

bool largestPoss(int arr[],int n)
{
	if(sum%3==0)
	{
		printArray(arr,n);
		return true;
	}

	else if(sum%3==1)
	{
		// checking 1 smallest digit whose remainder is 1
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]%3==1)
			{
				flag=1;
				arr[i]=-1;
				break;
			}
		}
		if(flag==1)
		{
		}
		else
		{
			//check 2 digits whose remainder is 2 and remove them
			int count=0;
			for(int i=0;i<n;i++)
			{
				if(arr[i]%3==2)
				{
					if(count==2) break;
					else
					{
						arr[i]=-1;
						count++;
					}

				}
			}
		}
		printArray(arr,n);
		return true;
	}
	else if(sum%3==2)
	{
		// checking 1 smallest digit whose remainder is 2
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]%3==2)
			{
				flag=1;
				arr[i]=-1;
				break;
			}
		}
		if(flag==1)
		{
		}
		else
		{
			//check 2 digits whose remainder is 1 and remove them
			int count=0;
			for(int i=0;i<n;i++)
			{
				if(arr[i]%3==1)
				{
					if(count==2) break;
						arr[i]=-1;

				}
			}
		}
		printArray(arr,n);
		return true;
	}

	printf("NOT POSSIBLE \n");
	return false;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{	scanf("%d",&arr[i]); sum = sum + arr[i]; }

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	largestPoss(arr,n);

	return 0;
}
