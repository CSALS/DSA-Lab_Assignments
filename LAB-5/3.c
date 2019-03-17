#include <stdio.h>
int arr[10000],len=0;

void print()
{
	for(int i=0;i<len;i++)
		printf(" %d ",arr[i]);
	printf("\n");
}

void delete()
{
	int x,i;
	scanf("%d",&x);
	for(i=0;i<len;i++)
		if(arr[i]==x)
			break;
	for(int j=i;j<len-1;j++)
		arr[j]=arr[j+1];
	len--;
}

void sort()
{
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

void swap()
{
	int a,b;
	scanf("%d %d",&a,&b);

	int i1=0,i2=0;
	while(arr[i1]!=a)
		i1++;
	while(arr[i2]!=b)
		i2++;
	arr[i1]=b;
	arr[i2]=a;
}

void insert()
{
	int x,i;
	scanf("%d",&x);
	for(i=0;i<len;i++)
		if(arr[i]>x)
			break;
	len++;
	for(int j=len-1;j!=i;j--)
		arr[j] = arr[j-1];
	arr[i]=x;
}

int main()
{

	char c;
	do {
		scanf("%d%c",&arr[len++],&c);
	}while(c!='\n');

	int n; //no of instructions
	scanf("%d",&n);

	while(n--) {

		char op;
		scanf(" %c",&op);

		if(op=='I')
			insert();
		if(op=='D')
			delete();
		if(op=='S') {

			char op2; scanf("%c",&op2);
			if(op2=='W')
				swap();
			else
				sort();

		}

		print();

	}

}
