#include<stdio.h>
#include<stdlib.h>

int top = -1;
int n=30;
int input_array[30];
void push();
void pop();
void show();

int main()
{
    int choice;
    
    while (1)
    {
    printf("enter perform the following operations in stack:  ");
    printf(" \n 1.push \n 2.pop \n 3.show \n 4.exit \n");
    scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                show();
                break;

            case 4:
                exit(0);

            default:            
                printf("invalid choice !!!");
        }
    }
    return 0;
}


void push()
{
    int x;

    if (top == n-1)
    {
        printf("\nstack overflow !!!\n");
    }

    else
    {
        printf("Enter the element to insert onto the stack: ");
        scanf("%d",&x);
        top = top + 1;
        input_array[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nstack underflow!!!\n");
    }

    else
    {
        printf("\n popped element is %d\n", input_array[top]);
        top = top - 1;
    }

}

void show()
{
    if(top == -1)
    {
        printf("\nstack underflow!!!\n");
    }
    else
    {
        printf("\n Elements in the stack are:  \n");
        for(int i = top; i>=0; --i)
        {
            printf("\t\t\n|| %d ||\n",input_array[i]);
        }
        printf("________\n"); 
        printf("________\n");
    }

}
