/*
NAME :- VAIBHAV KULKARNI
PRN  :- 1262253985
*/

#include <stdio.h>

/*------terms used------
r -> Rows of the matrix
c -> Columns of the matrix
A -> Original matrix 
B -> Compact matrix
T -> Transpose matrix
*/


/* function declaration */
void accept_matrix(int A[10][10],int r,int c);
void print_matrix(int A[10][10],int r,int c);
void compact_matrix(int A[10][10],int r,int c,int B[100][3]);
void print_compact_matrix(int B[100][3]);
void simple_transpose(int B[100][3],int T[100][3]);
void print_simple_transpose(int T[100][3]);
void fast_transpose(int B[100][3],int T[100][3]);
void print_fast_transpose(int T[100][3]);

int main(){

    /* variable declaration */
    int A[10][10] , r , c , B[100][3] , T[100][3];
    
    /* accepting the number of rows and columns */
    printf("\nEnter number of Rows and Columns:\n");
    scanf("%d%d",&r,&c);

    /* accpting elements of the matrix */
    printf("\nEnter the %d elements of Matrix:\n", r*c);
    accept_matrix(A,r,c);

    /* printing the original matrix */
    printf("\nYour Matrix is:\n");
    print_matrix(A,r,c);

    /* printing compact matrix */
    printf("\nYour Compact Matrix is :\n");
    compact_matrix(A,r,c,B);
    print_compact_matrix(B);

    /* printing the transposed matrix by simple transpose method */
    printf("\nYour Simple Transposed Matrix is :");
    simple_transpose(B,T);
    print_simple_transpose(T);

    /* printing the transposed matrix by fast transpose method */
    printf("\nYour Fast Transposed Matrix is :");
    fast_transpose(B,T);
    print_compact_matrix(T);
    
    return 0;

}

/* function for accepting original matrix */
void accept_matrix(int A[10][10],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for (j=0;j<c;j++){
            scanf("%d",&A[i][j]);
        }
    }
}

/* function for printing original matrix */
void print_matrix(int A[10][10],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}

/* function for compact matrix */
void compact_matrix(int A[10][10],int r,int c,int B[100][3]){
    int i,j,k;
    k=1;
    B[0][0]=r;
    B[0][1]=c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if (A[i][j]!=0){
                B[k][0]=i;
                B[k][1]=j;
                B[k][2]=A[i][j];
                k++;
            }
        }
    }
    B[0][2]=k-1;
}

/* function for printing compact matrix */
void print_compact_matrix(int B[100][3]){
    int i,j,r;
    printf("\nrow\tcolumn\tnonzero\n");
    for(i=0;i<=B[0][2];i++){
        printf("%d\t%d\t%d\n",B[i][0],B[i][1],B[i][2]);
    }
}

/* function for simple transpose of compact matrix */
void simple_transpose(int B[100][3],int T[100][3]){
    int i,j,k;
    T[0][0]=B[0][1];
    T[0][1]=B[0][0];
    T[0][2]=B[0][2];
    k=1;

    for (i=0;i<B[0][1];i++){
        for (j=1;j<=B[0][2];j++){
            if (B[j][1]==i){
                T[k][0]=B[j][1];
                T[k][1]=B[j][0];
                T[k][2]=B[j][2];
                k++;
            }
        }
    }

}

/* function for printing the simple transposed matrix */
void print_simple_transpose(int T[100][3]){
    int i,j,r;
    printf("\nrow\tcolumn\tnonzero\n");
    for(i=0;i<=T[0][2];i++){
        printf("%d\t%d\t%d\n",T[i][0],T[i][1],T[i][2]);
    }
}

/* function for fast transpose of compact matrix */
void fast_transpose(int B[100][3],int T[100][3]){
    int i,j,k;
    int frequency[100],position[100];
    T[0][0]=B[0][1];
    T[0][1]=B[0][0];
    T[0][2]=B[0][2];

    if(B[0][2]>0){
        for (i=0;i<B[0][1];i++)
            frequency[i]=0;

        for(i=1;i<=B[0][2];i++)
            frequency[B[i][1]]++;

        position[0]=1;   
        for (i = 1; i < B[0][1]; i++)
        position[i]=position[i-1]+frequency[i-1];

        for (i = 1; i <= B[0][2]; i++)
        {
            j = position[B[i][1]];

            T[j][0] = B[i][1];
            T[j][1] = B[i][0];
            T[j][2] = B[i][2];

            position[B[i][1]]++;
        }
    }
}

