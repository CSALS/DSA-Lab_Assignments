/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int myCompare(int x,int y)
{
    int xy = x * pow(10,floor(log10(y)+1)) + y;
    int yx = y * pow(10,floor(log10(x)+1)) + x;
    return (xy>yx) ? 0:1;
}

void sort(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(myCompare(arr[i],arr[j]))
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    sort(n,arr);
    for(int i=0;i<n;i++)
    printf("%d",arr[i]);
    printf("\n");
    return 0;
}
