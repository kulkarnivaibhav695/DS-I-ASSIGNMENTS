/*
NAME :- VAIBHAV KULKARNI
PRN  :- 1262253985
*/

#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct
{
    int job_id;
    char title[100];
} PrintJob;

typedef struct
{
    PrintJob jobs[MAX];
    int front;
    int rear;
    int count;
} CircularQueue;

void initialize(CircularQueue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;

    printf("Circular Queue initialized successfully.\n");
}

int isEmpty(CircularQueue *q)
{
    return q->count == 0;
}

int isFull(CircularQueue *q)
{
    return q->count == MAX;
}

void enqueue(CircularQueue *q)
{
    PrintJob job;

    if (isFull(q))
    {
        printf("Queue Overflow! Print queue is full.\n");
        return;
    }

    printf("Enter Job ID: ");
    scanf("%d", &job.job_id);

    printf("Enter Document Title: ");
    scanf(" %99[^\n]", job.title);

    q->rear = (q->rear + 1) % MAX;
    q->jobs[q->rear] = job;
    q->count++;

    printf("Print job is added successfully to the queue.\n");
}

void dequeue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow! No print jobs available.\n");
        return;
    }

    printf("Processing Print Job:\n");
    printf("Job ID: %d\n", q->jobs[q->front].job_id);
    printf("Document Title: %s\n", q->jobs[q->front].title);

    q->front = (q->front + 1) % MAX;
    q->count--;

    if (q->count == 0)
    {
        q->front = 0;
        q->rear = -1;
    }

    printf("Print job processed successfully.\n");
}

void display(CircularQueue *q)
{
    int i, index;

    if (isEmpty(q))
    {
        printf("Print queue is empty.\n");
        return;
    }

    printf("\nPending Print Jobs:\n");
    printf("Job ID\tDocument Title\n");

    for (i = 0; i < q->count; i++)
    {
        index = (q->front + i) % MAX;

        printf("%d\t%s\n",
               q->jobs[index].job_id,
               q->jobs[index].title);
    }
}

int main()
{
    CircularQueue q;
    int choice;

    initialize(&q);

    do
    {
        printf("\nCircular Queue - Printer Management System\n");
        printf("1. Enqueue Print Job\n");
        printf("2. Dequeue Print Job\n");
        printf("3. Display Print Queue\n");
        printf("4. Check Queue Status\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue(&q);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                if (isEmpty(&q))
                    printf("Print queue is empty.\n");
                else if (isFull(&q))
                    printf("Print queue is full.\n");
                else
                    printf("Print queue has %d vacant positions.\n",
                           MAX - q.count);
                break;

            case 5:
                printf("Exiting Printer Management System.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}