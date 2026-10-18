/*
NAME :- VAIBHAV KULKARNI
PRN  :- 1262253985
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    int reg_no;
    char name[25];
    struct student *next;
}student;


int count(student *head);
void add(student *head);
void delete(student *head);
void sorting(student *head);
void display(student *head);
void reverse(student *head);

void add(student *head)
{
    student *s=(student*)malloc(sizeof(student));
    student *temp=head;

    if(s==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    s->next=NULL;

    printf("Enter the reg no of student:");
    scanf("%d",&s->reg_no);

    printf("Enter the name of student:");
    scanf("%24s",s->name);

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=s;
}


void delete(student *head)
{
    int pos, i=1;
    student *temp=head->next;
    student *prev=head;

    if(temp==NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter the reg no of student to delete from list:");
    scanf("%d",&pos);

    while(temp!=NULL && temp->reg_no!=pos)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("Student not found\n");
    }
    else
    {
        prev->next=temp->next;
        free(temp);
        printf("Student deleted successfully\n");
    }
}

void sorting(student *head)
{
    student *prev;
    student *curr;
    student *temp;
    int i, j, l=count(head)-1;

    for(i=0;i<l-1;i++)
    {
        prev=head;
        curr=head->next;

        for(j=0;j<l-i-1;j++)
        {
            temp=curr->next;

            if(curr->reg_no > temp->reg_no)
            {
                prev->next=temp;
                curr->next=temp->next;
                temp->next=curr;
                prev=temp;
            }
            else
            {
                prev=curr;
                curr=temp;
            }
        }
    }

    printf("List sorted successfully\n");
}

void display(student *head)
{
    student *temp=head->next;

    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Reg_no\tName\n");

        while(temp!=NULL)
        {
            printf("%d\t%s\n",temp->reg_no,temp->name);
            temp=temp->next;
        }
    }
}

int count(student *head)
{
    student *temp=head->next;
    int i=0;

    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }

    return i;
}

void reverse(student *head)
{
    student *prev=NULL;
    student *curr=head->next;
    student *temp;

    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }

    head->next=prev;

    printf("List reversed successfully\n");
}

int main()
{
    student *head=(student*)malloc(sizeof(student));
    int choice;

    if(head==NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    head->next=NULL;

    do
    {
        printf("\nStudent menu:\n");
        printf("1.Add\n2.Delete\n3.Reverse\n4.Sort\n5.Display\n6.Count\n7.Exit\n");

        printf("Enter your choice:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                add(head);
                break;

            case 2:
                delete(head);
                break;

            case 3:
                reverse(head);
                break;

            case 4:
                sorting(head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("No of students are %d\n",count(head));
                break;

            case 7:
                printf("Exiting Program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice!=7);

    student *temp;

    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }

    return 0;
}