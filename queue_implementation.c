#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
void enqueue();
void dequeue();
void show();
//int SIZE = 50;
int queue_array[SIZE];
int rear = -1;
int front = -1;

int main()
{
    int choice;
    while (1)
    {
        printf("\n 1 -> Enqueue \n");
        printf("\n 2 -> Dequeue \n");
        printf("\n 3 -> Display \n");
        printf("\n 4 -> Exit \n");

        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {

            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                show();
                break;

            case 4:
                exit(0);

            default:
                printf("\ninvalid entered choice!!!\n");        
        }
    }
}

void enqueue()
{
    int element;
    if (rear == SIZE-1)
    {
        printf("queue overflow!!! \n");
    }
    else
    {
        if(front == -1)
        {
            front =0;
        }
        printf("Enter the element:  ");
        scanf("%d",&element);
        rear++;
        queue_array[rear]=element; 
    }
}

void dequeue()
{
    if(front == -1 || front>rear)
    {
        printf("\n Underflow!!!");
    }

    else
    {
        printf("\n Dequeued element is: %d",queue_array[front]);
        front++;
    }
}

void show()
{
    int i;
    if(front == -1)
    {
        printf("\n Queue is empty");
    }

    else
    {
        printf("Elements in Queue: ");
        for(i=front; i<=rear; i++)
        {
            printf("\t%d\t",queue_array[i]);
        }
    }

}
