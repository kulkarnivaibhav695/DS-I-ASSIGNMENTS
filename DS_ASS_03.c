/*
NAME :- VAIBHAV KULKARNI
PRN  :- 1262253985
*/

//header files
#include <stdio.h>
#include <string.h>

//structure for storing students data
struct student
{
    int rollno;
    char name[30];
    float marks;
};

//prototypes for functions
typedef struct student student;

//function to display student data
void Display_data(student s[], int n)
{
    printf("Roll No\t\tName\t\tMarks\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t\t%-15s\t%.2f\n",
               s[i].rollno,
               s[i].name,
               s[i].marks);
    }

}

//function to perform linear search
int Linear_search(student s[], int n, int key)
{
    int comparisons = 0;

    for(int i = 0; i < n; i++)
    {
        comparisons++;

        if(s[i].rollno == key)
        {
            printf("\nStudent Found!");
            printf("\nNumber of comparisons = %d\n", comparisons);

            return i;
        }
    }

    printf("\nStudent Not Found!");
    printf("\nNumber of comparisons = %d\n", comparisons);

    return -1;
}

//function to perform binary search
int Binary_search(student s[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int comparisons = 0;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        comparisons++;

        if(s[mid].rollno == key)
        {
            printf("\nStudent Found!");
            printf("\nNumber of comparisons = %d\n", comparisons);

            return mid;
        }

        else if(key < s[mid].rollno)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    printf("\nStudent Not Found!");
    printf("\nNumber of comparisons = %d\n", comparisons);

    return -1;
}

//function to perform selection sort
void Selection(student s[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;

        for(int j = i + 1; j < n; j++)
        {
            if(s[j].rollno < s[min].rollno)
            {
                min = j;
            }
        }

        if(min != i)
        {
            student temp = s[i];
            s[i] = s[min];
            s[min] = temp;
        }

        printf("\nAfter Pass %d:\n", i + 1);
        Display_data(s, n);
    }

    printf("\nFinal Sorted Data - Roll Number Wise:\n");
    Display_data(s, n);
}

//function to perform shell sort
void Shellsort(student s[], int n)
{
    for(int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for(int i = gap; i < n; i++)
        {
            student temp = s[i];

            int j;

            for(j = i;
                j >= gap && s[j - gap].marks > temp.marks;
                j = j - gap)
            {
                s[j] = s[j - gap];
            }

            s[j] = temp;
        }

        printf("\nAfter Gap = %d:\n", gap);
        Display_data(s, n);
    }

    printf("\nFinal Sorted Data - Marks Wise (Ascending):\n");
    Display_data(s, n);

    printf("\nStudent with Minimum Marks:\n");
    printf("Roll No : %d\n", s[0].rollno);
    printf("Name    : %s\n", s[0].name);
    printf("Marks   : %.2f\n", s[0].marks);
}

//function to perform insertion sort
void Insertion(student s[], int n)
{
    for(int i = 1; i < n; i++)
    {
        student key = s[i];

        int j = i - 1;

        while(j >= 0 && s[j].marks < key.marks)
        {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = key;

        printf("\nAfter Pass %d:\n", i);
        Display_data(s, n);
    }

    printf("\nFinal Sorted Data - Marks Wise (Descending):\n");
    Display_data(s, n);

    printf("\nTopper's Data:\n");
    printf("Roll No : %d\n", s[0].rollno);
    printf("Name    : %s\n", s[0].name);
    printf("Marks   : %.2f\n", s[0].marks);
}

//main function
int main()
{
    student s[10];

    int n;
    int choice;
    int key;
    int pos;

    printf("Enter number of students (maximum 10): ");
    scanf("%d", &n);

    if(n <= 0 || n > 10)
    {
        printf("\nInvalid number of students!");
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &s[i].rollno);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    //do while loop is used to display the menu of operations to be performed 
    do
    {
    
        printf("\n MENU\n");
    
        printf("\n1. Display Student Data");
        printf("\n2. Linear Search");
        printf("\n3. Binary Search");
        printf("\n4. Selection Sort - Roll Number Wise");
        printf("\n5. Shell Sort - Marks Wise");
        printf("\n6. Insertion Sort - Marks Descending\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch(choice)
        {

            case 1:

                Display_data(s, n);

                break;

            case 2:

                printf("\nEnter Roll No to search: ");
                scanf("%d", &key);

                pos = Linear_search(s, n, key);

                if(pos != -1)
                {
                    printf("\nStudent Details:");
                    printf("\nRoll No : %d", s[pos].rollno);
                    printf("\nName    : %s", s[pos].name);
                    printf("\nMarks   : %.2f\n", s[pos].marks);
                }

                break;

            case 3:

                Selection(s, n);

                printf("\nEnter Roll No to search: ");
                scanf("%d", &key);

                pos = Binary_search(s, n, key);

                if(pos != -1)
                {
                    printf("\nStudent Details:");
                    printf("\nRoll No : %d", s[pos].rollno);
                    printf("\nName    : %s", s[pos].name);
                    printf("\nMarks   : %.2f\n", s[pos].marks);
                }

                break;

            case 4:

                Selection(s, n);

                break;

            case 5:

                Shellsort(s, n);

                break;

            case 6:

                Insertion(s, n);

                break;

            default:

                printf("\nInvalid Choice!");
        }

    } while(choice != 6);

    /*  printf("\nMENU\n");

        printf("\n1. Display Student Data");
        printf("\n2. Linear Search");
        printf("\n3. Binary Search");
        printf("\n4. Selection Sort - Roll Number Wise");
        printf("\n5. Shell Sort - Marks Wise");
        printf("\n6. Insertion Sort - Marks Descending\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                Display_data(s, n);

                break;


            case 2:

                printf("\nEnter Roll No to search: ");
                scanf("%d", &key);

                pos = Linear_search(s, n, key);

                if(pos != -1)
                {
                    printf("\nStudent Details:");
                    printf("\nRoll No : %d", s[pos].rollno);
                    printf("\nName    : %s", s[pos].name);
                    printf("\nMarks   : %.2f\n", s[pos].marks);
                }

                break;


            case 3:

                Selection(s, n);

                printf("\nEnter Roll No to search: ");
                scanf("%d", &key);

                pos = Binary_search(s, n, key);

                if(pos != -1)
                {
                    printf("\nStudent Details:");
                    printf("\nRoll No : %d", s[pos].rollno);
                    printf("\nName    : %s", s[pos].name);
                    printf("\nMarks   : %.2f\n", s[pos].marks);
                }

                break;


            case 4:

                Selection(s, n);

                break;


            case 5:

                Shellsort(s, n);

                break;


            case 6:

                Insertion(s, n);

                break;


            default:

                printf("\nInvalid Choice!");
        }
    */

    return 0;
}