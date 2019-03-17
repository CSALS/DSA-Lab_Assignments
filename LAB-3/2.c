#include <stdio.h>

int main()
{
	char s[1000];
	int len=0;
	scanf("%[^\n]%*c", s);
	for(int i=0;i<1000;i++)
	{
		if(s[i]=='\0')
			len++;
	}
	int m;
	scanf(" %d",&m);
	while(m--)
	{
		int f,r,k;
		scanf(" %d %d %d",&f,&r,&k);
		f--; r--;
		while(k--)
		{
			char c;
			char temp = s[f];
			for(int i=f+1;i<=r;i++)
			{
				c = s[i];
				s[i] = temp;
				temp = c;
			}
			s[f] = temp;
		}

	}
	printf("%s\n",s);
}
