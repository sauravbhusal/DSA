#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void Insert_At_Beginning();
void Insert_At_Ending();
void Insert_At_Position();
void Deletion_At_Beginning();
void Deletion_At_Ending();
void Deletion_At_Position();
void Display();


int main()
{
    int choice;

    while(1)
    {
        printf("\n********************MENU********************\n");
        printf("\t 1 -> INSERT AT BEGINNING\n");
        printf("\t 2 -> INSERT AT ENDING\n");
        printf("\t 3 -> INSERT AT SPECIFIC POSITION\n");
        printf("\t 4 -> DELETE AT BEGINNING\n");
        printf("\t 5 -> DELETE AT ENDING\n");
        printf("\t 6 -> DELETE AT SPECIFIC POSITION\n");
        printf("\t 7 -> DISPLAY\n");
        printf("\t 8 -> EXIT\n");

        printf("\t ENTER YOUR CHOICE:  ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                Insert_At_Beginning();
                break;

            case 2:
                Insert_At_Ending();
                break;

            case 3:
                Insert_At_Position();
                break;

            case 4:
                Deletion_At_Beginning();
                break;

            case 5:
                Deletion_At_Ending();
                break;

            case 6:
                Deletion_At_Position();
                break;

            case 7:
                Display();
                break;

            case 8:
                exit(0);

            Default:
                printf("\n INVALID CHOICE!!! \n");
                break;
        }
    }
    return 0;
}


void Insert_At_Beginning()
{
    int value;
    struct node *NewNode;

    printf("\n ENTER THE VALUE TO INSERT:  ");
    scanf("%d",&value);

    NewNode = (struct node *)malloc(sizeof(struct node));

    NewNode -> data = value;
    NewNode -> next = head;
    head = NewNode;
}


void Insert_At_Ending()
{
    int value;
    struct node *NewNode;
    struct node *ptr;

    printf("\n ENTER THE VALUE TO INSERT:  ");
    scanf("%d",&value);

    NewNode = (struct node*)malloc(sizeof(struct node));

    ptr = head;
    NewNode -> data = value;

    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }

    ptr -> next = NewNode;
    NewNode -> next = NULL;
}


void Insert_At_Position()
{
    int value, pos,i;
    struct node *NewNode;
    struct node *ptr;

    printf("\n ENTER THE VALUE TO INSERT:  ");
    scanf("%d",&value);
    printf("\n ENTER THE POSITION TO INSERT:  ");
    scanf("%d",&pos);

    NewNode = (struct node*)malloc(sizeof(struct node));

    ptr = head;

    for(i = 0; i < pos-1; i++)
    {
        ptr = ptr -> next;
        if(ptr == NULL)
        {
            printf("INVALID POSITION!!!");
        }
    }

    NewNode -> next = ptr -> next;
    NewNode -> data = value;
    ptr -> next = NewNode;
}


void Deletion_At_Beginning()
{
    struct node *ptr;
    ptr = head;

    if(head ==  NULL)
    {
        printf("INVALID DELETION!!!");
    }
    printf("\n %d IS DELETED \n", ptr -> data);
    head = ptr -> next;
    free(ptr);
}


void Deletion_At_Ending()
{
    struct node *ptr;
    struct node *temp;
    ptr = head;

    if (head == NULL)
    {
        printf("\nINVALID DELETION!!!\n");
    }

    if (head -> next == NULL)
    {
        head = NULL;
        printf("%d IS DELETED \n",ptr -> data);
        free(ptr);
    }

    else
    {
        while(ptr -> next != NULL)
        {
            temp = ptr;
            ptr = ptr -> next;
        }
        temp -> next = NULL;
        printf("%d IS DELETED \n",ptr -> data);
        free(ptr);
    }    
}


void Deletion_At_Position()
{
    struct node *ptr;
    struct node *temp;
    int pos,i,size;

    printf("\n ENTER THE POSITION WHERE YOU WANT TO DELETE :");
    scanf("%d",&pos);

    ptr = head;
    size = sizeof(struct node);

    if(head == NULL || size < pos)
    {
        printf("\n INVALID DELETION OPERATION");
    }

    if (pos == 0)
    {
        head = head -> next;
        printf("\n %d IS DELETED ", ptr -> data);
        free(ptr);
    }

    else
    {
        for(i = 0; i < pos; i++)
        {
            temp = ptr;
            ptr = ptr -> next;
        }

        temp -> next = ptr -> next;
        printf("\n %d IS DELETED \n",ptr -> data);
        free(ptr);
    }
    
}

void Display()
{
    struct node *ptr;
    int i = 0;

    ptr = head;
    printf("\n THE DATA INSIDE LINKED LIST ARE: \n ");

    while(ptr -> next != NULL)
    {
        printf("\n %d -> %d \n",i++, ptr->data);
        ptr = ptr -> next;
    }
    printf("\n %d -> %d \n",i++, ptr->data);
}
