/*
NAME :- VAIBHAV KULKARNI
PRN  :- 1262253985
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    char data[MAX][MAX];
    int top;
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s, char value[])
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        exit(1);
    }

    s->top++;
    strcpy(s->data[s->top], value);
}

char *pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    return s->data[s->top--];
}

void display(Stack *s)
{
    int i;

    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    for (i = s->top; i >= 0; i--)
    {
        printf("%s\n", s->data[i]);
    }
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' ||
           ch == '^';
}

void makeExpression(char result[], char op1[], char op2[], char operator)
{
    snprintf(result, MAX, "%c%s%s", operator, op1, op2);
}

void makeInfix(char result[], char op1[], char op2[], char operator)
{
    snprintf(result, MAX, "(%s%c%s)", op1, operator, op2);
}

void postfixToPrefix(char postfix[], char prefix[])
{
    Stack s;
    char op1[MAX], op2[MAX], temp[MAX];
    int i;

    initialize(&s);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum((unsigned char)postfix[i]))
        {
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(&s, temp);
        }
        else if (isOperator(postfix[i]))
        {
            if (s.top < 1)
            {
                printf("Invalid postfix expression\n");
                exit(1);
            }

            strcpy(op2, pop(&s));
            strcpy(op1, pop(&s));

            makeExpression(temp, op1, op2, postfix[i]);
            push(&s, temp);
        }
        else
        {
            printf("Invalid character in expression\n");
            exit(1);
        }
    }

    if (s.top != 0)
    {
        printf("Invalid postfix expression\n");
        exit(1);
    }

    strcpy(prefix, pop(&s));
}

void postfixToInfix(char postfix[], char infix[])
{
    Stack s;
    char op1[MAX], op2[MAX], temp[MAX];
    int i;

    initialize(&s);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum((unsigned char)postfix[i]))
        {
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(&s, temp);
        }
        else if (isOperator(postfix[i]))
        {
            if (s.top < 1)
            {
                printf("Invalid postfix expression\n");
                exit(1);
            }

            strcpy(op2, pop(&s));
            strcpy(op1, pop(&s));

            makeInfix(temp, op1, op2, postfix[i]);
            push(&s, temp);
        }
        else
        {
            printf("Invalid character in expression\n");
            exit(1);
        }
    }

    if (s.top != 0)
    {
        printf("Invalid postfix expression\n");
        exit(1);
    }

    strcpy(infix, pop(&s));
}

void prefixToInfix(char prefix[], char infix[])
{
    Stack s;
    char op1[MAX], op2[MAX], temp[MAX];
    int i;

    initialize(&s);

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        if (isalnum((unsigned char)prefix[i]))
        {
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(&s, temp);
        }
        else if (isOperator(prefix[i]))
        {
            if (s.top < 1)
            {
                printf("Invalid prefix expression\n");
                exit(1);
            }

            strcpy(op1, pop(&s));
            strcpy(op2, pop(&s));

            makeInfix(temp, op1, op2, prefix[i]);
            push(&s, temp);
        }
        else
        {
            printf("Invalid character in expression\n");
            exit(1);
        }
    }

    if (s.top != 0)
    {
        printf("Invalid prefix expression\n");
        exit(1);
    }

    strcpy(infix, pop(&s));
}

int main()
{
    char postfix[MAX];
    char prefix[MAX];
    char infix[MAX];

    int choice;

    do
    {
        printf("\nExpression Conversion Using Stack\n");
        printf("1. Postfix to Prefix\n");
        printf("2. Postfix to Infix\n");
        printf("3. Prefix to Infix\n");
        printf("4. Display Stack Operations\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%99s", postfix);

                postfixToPrefix(postfix, prefix);
                printf("Prefix expression: %s\n", prefix);
                break;

            case 2:
                printf("Enter postfix expression: ");
                scanf("%99s", postfix);

                postfixToInfix(postfix, infix);
                printf("Infix expression: %s\n", infix);
                break;

            case 3:
                printf("Enter prefix expression: ");
                scanf("%99s", prefix);

                prefixToInfix(prefix, infix);
                printf("Infix expression: %s\n", infix);
                break;

            case 4:
            {
                Stack s;
                char value[MAX];

                initialize(&s);

                printf("Enter number of elements to push: ");
                int n, i;
                scanf("%d", &n);

                if (n < 0 || n > MAX)
                {
                    printf("Invalid number of elements\n");
                    break;
                }

                for (i = 0; i < n; i++)
                {
                    printf("Enter element: ");
                    scanf("%99s", value);
                    push(&s, value);
                }

                display(&s);
                break;
            }

            case 5:
                printf("Exiting Program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}