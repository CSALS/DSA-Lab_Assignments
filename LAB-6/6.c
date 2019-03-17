#include<stdio.h>
#include<string.h>


int main() {

while(1)
{
    char str[100];
   scanf("%s", str);
   char max_substr[100];
   max_substr[0]='\0';
   int l = strlen(str);

    for(int i=0;i<l;i++)
    {
        for(int j=i+2;j<l;j++)
        {
            int flag=0;
            char t = 'a';
            for(int k=i;k<=(i+j)/2;k++)
            {
                if(str[k]>=t && str[k]==str[(i+j)-k])
                {
                    t = str[k];
                }
                else
                {
                    flag=1;
                }
            }
            int start=0;
            if(flag==0)
            {
                if((j-i+1)>strlen(max_substr))
                {
                    for(int k=i;k<=j;k++)
                        max_substr[start++]=str[k];
                    max_substr[start]='\0';
                }
                else if((j-i+1)==strlen(max_substr))
                {
                    for(int k=i;k<=j;k++)
                    {
                        if(max_substr[start]>str[k])
                        {
                                max_substr[start]=str[k];
                        }
                        start++;
                    }
                }
            }
        }
    }
    if(strlen(max_substr)==0) printf("-1 \n");
    else
    printf("%s\n",max_substr);
}




    return 0;
}
