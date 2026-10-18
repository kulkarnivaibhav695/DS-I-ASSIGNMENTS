/*
NAME :- VAIBHAV KULKARNI
PRN  :- 1262253985
*/

#include <stdio.h>

//function for accepting the 1st matrix
void accept_matrix01(int a[10][10],int r,int c)
{
    int i,j;
    for (i=0;i<r;i++)
        for (j=0;j<c;j++)
        scanf("%d", &a[i][j]);

}

//function for printing the 1st matrix
void print_matrix01(int a[10][10],int r,int c)
{
    int i,j;
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

}

//function for accepting the 2nd matrix
void accept_matrix02(int b[10][10],int r,int c)
{
    int i,j;
    for (i=0;i<r;i++)
        for (j=0;j<c;j++)
        scanf("%d", &b[i][j]);

}

//function for printing the 2nd matrix
void print_matrix02(int b[10][10],int r,int c)
{
    int i,j;
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

}

//function for performing addition of two matrix
void addition( int a[10][10], int b[10][10], int t[10][10], int r, int c )
{
    int i,j;
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            t[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("\nAddition matrix :\n");
    print_matrix02(t,r,c);

}

//function for performing substraction of two matrix
void substraction( int a[10][10], int b[10][10], int t[10][10], int r, int c )
{
    int i,j;
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            t[i][j]=b[i][j]-a[i][j];
        }
    }
    printf("\nsubstraction matrix :\n");
    print_matrix02(t,r,c);

}

//function for performing transpose of matrix
void transpose( int a[10][10], int r, int c )
{
    int temp,i,j;
    for (i=0;i<r;i++){
        for (j=1;j<c;j++){
            temp=a[i][j];
           a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }
    printf("\ntranspose matrix :\n");
    print_matrix01(a,r,c);

}

//function for performing multiplication of two matrix
void multiplication( int a[10][10], int b[10][10], int t[10][10], int r, int c )
{
    int i,j,k;

    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            t[i][j]=0;
        }
    }

    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            for (k=0;k<c;k++){
            t[i][j]=t[i][j]+a[i][j]*b[i][j];
            }
        }
    }
    printf("\nmultiplication matrix :\n");
    print_matrix02(t,r,c);

}

//main function
int main ()
{
    int a[10][10],b[10][10],t[10][10],r,c,choice;

    printf("----printing and performing operations on matrix using functions----\n");

    //Matrix 01
    printf("\nEnter rows and columns for  matrix  01 :\n");
    scanf("%d%d",&r,&c);

    printf("Enter the elements  of matrix 01 :\n");
    accept_matrix01(a,r,c);

    printf("Your matrix 01 is :\n");
    print_matrix01(a,r,c);

    //Matrix 02
    printf("Enter rows and columns for  matrix  02 :\n");
    scanf("%d%d",&r,&c);

    printf("Enter the elements  of matrix 02 :\n");
    accept_matrix02(b,r,c);

    printf("Your matrix 02 is :\n");
    print_matrix02(b,r,c);

    //Menu for user
    printf("Enter your choice :\n");
    printf("Enter 1 for addition :\n");
    printf("Enter 2 for substraction :\n");
    printf("Enter 3 for transpose :\n");
    printf("Enter 4 for multiplication :\n");
    scanf("%d",&choice);

    //operation cases
    switch (choice)
    {
    case 1:

        addition(a,b,t,r,c);
        break;

    case 2:

        substraction(a,b,t,r,c);
        break;

    case 3:

        transpose(a,r,c);
        break;

    case 4:

        multiplication(a,b,t,r,c);
        break;

    default:
        printf("Invalid choice:");
    
    }
    return 0;
}