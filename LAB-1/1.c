#include <stdio.h>

int main()
{
	int n;
	int temp=-1;
	scanf("%d",&n);
	int arr[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		scanf("%d",&arr[i][j]);
		}
	}
	
	for(int i=0;i<n;i++){
	//finding min element in ith row
	int min = arr[i][0];
	int index=0;
		for(int j=1;j<n;j++){
		if(arr[i][j]<min){
		min=arr[i][j];
		index=j;
		}
		}
	//min element index stored in index
	//checking if this min element is max in the column
	
	for(int k=0;k<n;k++){
		if(min < arr[k][index])	
			break;
	}

	if(k == n) {
	temp=0;
	printf("%d , %d ",i,index);
	printf("\n"); 
	}
	
	}
	if(temp==-1)
	printf("No SADDLE point");
	return 0;
}