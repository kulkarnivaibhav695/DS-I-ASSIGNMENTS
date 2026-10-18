/*
NAME :- VAIBHAV KULKARNI
PRN  :- 1262253985
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
}node;

node* create_node(int coeff, int exp)
{
    node *newnode=(node*)malloc(sizeof(node));

    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newnode->coeff=coeff;
    newnode->exp=exp;
    newnode->next=newnode;

    return newnode;
}

void insert_term(node *head, int coeff, int exp)
{
    node *temp=head;
    node *prev=head;

    if(coeff==0)
        return;

    if(head->next==head)
    {
        node *newnode=create_node(coeff,exp);
        head->next=newnode;
        newnode->next=head;
        return;
    }

    temp=head->next;

    while(temp!=head && temp->exp>exp)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp!=head && temp->exp==exp)
    {
        temp->coeff+=coeff;

        if(temp->coeff==0)
        {
            prev->next=temp->next;
            free(temp);
        }

        return;
    }

    node *newnode=create_node(coeff,exp);

    if(temp==head)
    {
        prev->next=newnode;
        newnode->next=head;
    }
    else
    {
        prev->next=newnode;
        newnode->next=temp;
    }
}

node* create_polynomial()
{
    node *head=create_node(0,-1);
    int n,coeff,exp,i;

    printf("Enter number of terms: ");
    scanf("%d",&n);

    if(n<0)
    {
        printf("Invalid number of terms\n");
        return head;
    }

    for(i=0;i<n;i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d",&coeff,&exp);

        if(exp<0)
        {
            printf("Exponent must be non-negative\n");
            i--;
            continue;
        }

        insert_term(head,coeff,exp);
    }

    return head;
}

void display_polynomial(node *head)
{
    node *temp=head->next;
    int first=1;

    if(temp==head)
    {
        printf("0\n");
        return;
    }

    while(temp!=head)
    {
        if(temp->coeff>0 && !first)
            printf(" + ");
        else if(temp->coeff<0)
        {
            if(!first)
                printf(" - ");
            else
                printf("-");
        }

        int c=abs(temp->coeff);

        if(temp->exp==0)
            printf("%d",c);
        else
        {
            if(c!=1)
                printf("%d",c);

            printf("x");

            if(temp->exp!=1)
                printf("^%d",temp->exp);
        }

        first=0;
        temp=temp->next;
    }

    printf("\n");
}

node* addPolynomial(node *p1, node *p2)
{
    node *result=create_node(0,-1);
    node *t1=p1->next;
    node *t2=p2->next;

    while(t1!=p1 && t2!=p2)
    {
        if(t1->exp==t2->exp)
        {
            insert_term(result,t1->coeff+t2->coeff,t1->exp);
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->exp>t2->exp)
        {
            insert_term(result,t1->coeff,t1->exp);
            t1=t1->next;
        }
        else
        {
            insert_term(result,t2->coeff,t2->exp);
            t2=t2->next;
        }
    }

    while(t1!=p1)
    {
        insert_term(result,t1->coeff,t1->exp);
        t1=t1->next;
    }

    while(t2!=p2)
    {
        insert_term(result,t2->coeff,t2->exp);
        t2=t2->next;
    }

    return result;
}

void free_polynomial(node *head)
{
    node *temp=head->next;
    node *next;

    while(temp!=head)
    {
        next=temp->next;
        free(temp);
        temp=next;
    }

    free(head);
}

int main()
{
    node *p1,*p2,*result;
    int choice;

    do
    {
        printf("\nPolynomial Operations Using Circular Linked List\n");
        printf("1. Create Polynomial 1\n");
        printf("2. Create Polynomial 2\n");
        printf("3. Display Polynomials\n");
        printf("4. Add Polynomials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                p1=create_polynomial();
                printf("Polynomial 1: ");
                display_polynomial(p1);
                break;

            case 2:
                p2=create_polynomial();
                printf("Polynomial 2: ");
                display_polynomial(p2);
                break;

            case 3:
                printf("Polynomial 1: ");
                if(p1!=NULL)
                    display_polynomial(p1);
                else
                    printf("Not created\n");

                printf("Polynomial 2: ");
                if(p2!=NULL)
                    display_polynomial(p2);
                else
                    printf("Not created\n");
                break;

            case 4:
                if(p1==NULL || p2==NULL)
                {
                    printf("Create both polynomials first\n");
                }
                else
                {
                    result=addPolynomial(p1,p2);
                    printf("Resultant Polynomial: ");
                    display_polynomial(result);
                    free_polynomial(result);
                }
                break;

            case 5:
                printf("Exiting Program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice!=5);

    return 0;
}