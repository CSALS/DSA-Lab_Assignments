#include <stdio.h>

int findOptimal(int n)
{
    if(n<=6)
        return n;

    int max=0;
    int b;
    for(b=n-3;b>=1;b--)
    {
        int curr = (n-b-1)*findOptimal(b);
        if(curr > max)
            max = curr;
    }
    return max;
}

int main()
{
    int n; // no of key strokes

    printf("%d\n",findOptimal(n));
}
