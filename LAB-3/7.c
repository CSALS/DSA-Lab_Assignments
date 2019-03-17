

#include <stdio.h>

int main()
{
    
        char s[1000];
	scanf("%[^\n]%*c", s);
	for(int i=0;i<1000;i++)
	{
		if(s[i]=='\0')
			break;

		s[i] = (int)((s[i]-97+3)%26) + 97;
	}
	printf("%s\n",s );

    


	return 0;
}
