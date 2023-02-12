#include<stdio.h>
#include<stdlib.h>

char A,B,C;
int n;

void toh(int n,char A,char B,char C)
{
    if(n==1)
    {
        printf("\nmove %d disk from %c to %c\n",n,A,C);
        return;
    }

    else if(n>1)
    {
        toh(n-1,A,C,B);
        printf("\nmove %d disk from %c to %c \n",n,A,C);
        toh(n-1,B,A,C);
    }
}


int main()
{
    printf("how many disk you want to transfer to the destination tower? \n");
    scanf("%d",&n);
    toh(n,'A','B','C');
    return 0;
}