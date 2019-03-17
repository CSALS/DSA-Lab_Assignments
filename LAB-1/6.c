#include <stdio.h>

int main()
{
	int a,b,flag;
	scanf("%d %d",&a,&b);
	
	for(int i=a;i<=b;i++)
	{
		if(i==1) continue;
		flag=1;
		for(int j=2;j<=i/2;j++){
			if(i%j==0)
			{ flag=-1; break;}
		}
	//flag = -1 then not prime
	//flag = 1 then prime
	
		if(flag==1)
		printf("%d ",i);
	}
	
	return 0;
}