#include <stdio.h>
int n,k;

void sum(int matrix[n][n])
{
    if(k > n)
    {
        printf("K > N .. invalid input \n");
        return;
    }
    int max = 0;
    for(int i=0;i<n-k+1;i++)
    {
        for(int j=0;j<n-k+1;j++)
        {
            int sum=0;
            for(int p=i;p<k+i;p++)
                for(int q=j;q<k+j;q++)
                    sum += matrix[p][q];
            if(sum > max)
                max = sum;
        }
    }
    printf("Maximum is : %d \n",max);
}

int main()
{
   printf("enter 'n' \n");
   scanf(" %d",&n);

   printf("enter 'k' \n");
   scanf(" %d",&k);

   int matrix[n][n];
   printf("enter elements \n");
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           scanf(" %d",&matrix[i][j]);
       }
   }
   printf("done");
   sum(matrix);

   return 0;
}
