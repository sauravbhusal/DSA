#include<stdio.h>
#include<stdlib.h>

int n1,n2;
int temp;

void HCF(int x, int y)
{

    if(y!=0)
    {
        temp = x%y;
        HCF(y,temp);
    }

    else
    {
        printf("the required hcf is %d",x);
        return;
    }
    
}

int main()
{
    printf("enter the value of n1 and n2:  ");
    scanf("%d%d",&n1,&n2);
    HCF(n1,n2);
    return 0;
}