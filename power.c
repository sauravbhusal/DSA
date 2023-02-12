#include<stdio.h>
#include<stdlib.h>



int power2(int x, int n)
{
    if(n>0)
    {
        return(x*power2(x,n-1));
    }

    else
    {
        return 1;
    }

}

int main()
{   int x,n,temp;
    printf("enter the value of x and n to calculate x^n:  ");
    scanf("%d%d",&x,&n);
    temp = power2(x,n);
    printf("%d",temp);
    return 0;

}