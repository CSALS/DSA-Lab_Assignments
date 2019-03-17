

#include <stdio.h>

int main()
{
	char s[1000];
	int count[200];

	
	for(int i=97;i<123;i++) count[i]=0;
	scanf("%[^\n]%*c", s);
	for(int i=0;i<1000;i++)
	{
		if(s[i]=='\0')
			break;
		count[s[i]]++;
	}
	int odd=0,flag=0;
	for(int i=97;i<123;i++)
	{
	
		if(count[i]%2!=0 && count[i]!=0)
			odd++;
		if(odd>1)
		{
			flag=1;
			break;
		}

	}
	if(flag==1) printf("NO\n");
    else printf("YES\n");

	
	return 0;
}
