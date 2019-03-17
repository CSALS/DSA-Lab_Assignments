#include <stdio.h>
#include <string.h>
int main()
{
	int n,len;
	char s[100];
	char store[100][100];
	//scanf("%[^\n]%*c",s);
	//scanf("%[^\n]s",s);
	//printf("enter string");
	gets(s);
	for(int i=0;i<100;i++){
		if(s[i]=='\0')
		{ len=i; break; }
	}
	int alt=2;
	//correct third successor
	for(int i=0;i<len;i++){
		if(alt%2==0){
            if(s[i]!=' '){
                if(s[i]<120)
                s[i]=s[i]+3;
                else
                s[i]=s[i]-23;
                alt++;
            }
	   }
	   else
       alt++;

	}
	printf("%s ",s);

	int k=0,j=0;
	for(int i=0;i<len;i++){
		if(s[i]==' ')
		{
			store[k][j]='\0';
			k++;
			j=0;
		}
		else
		{
			store[k][j]=s[i];
			j++;
		}
	}
	store[k][j]='\0';
	k=k+1; //'k' no. of rows
	int l;
	char temp;
	for(int i=0;i<k;i++){
		l = strlen(store[i]);
	for (int j=0,x = l-1;j<x;j++,x--)
        	{
            	temp = store[i][j];
            	store[i][j] = store[i][x];
            	store[i][x] = temp;
        	}
	}

	for(int i=0;i<k;i++)
	printf("%s ",store[i]);

	return 0;
}





