/*
NAME :- VAIBHAV KULKARNI
PRN  :- 1262253985
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct
{
    int data[MAX];
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

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        exit(1);
    }

    s->data[++s->top] = value;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    return s->data[s->top--];
}

int evaluatePostfix(char postfix[])
{
    Stack s;
    int i = 0, op1, op2, value;
    char *token;

    initialize(&s);

    token = strtok(postfix, " ");

    while (token != NULL)
    {
        if (isdigit((unsigned char)token[0]) ||
            (token[0] == '-' && isdigit((unsigned char)token[1])))
        {
            push(&s, atoi(token));
        }
        else if (strlen(token) == 1 &&
                 (token[0] == '+' || token[0] == '-' ||
                  token[0] == '*' || token[0] == '/' ||
                  token[0] == '%' || token[0] == '^'))
        {
            if (s.top < 1)
            {
                printf("Invalid postfix expression\n");
                exit(1);
            }

            op2 = pop(&s);
            op1 = pop(&s);

            switch (token[0])
            {
                case '+':
                    value = op1 + op2;
                    break;

                case '-':
                    value = op1 - op2;
                    break;

                case '*':
                    value = op1 * op2;
                    break;

                case '/':
                    if (op2 == 0)
                    {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    value = op1 / op2;
                    break;

                case '%':
                    if (op2 == 0)
                    {
                        printf("Modulo by zero error\n");
                        exit(1);
                    }
                    value = op1 % op2;
                    break;

                case '^':
                {
                    int j;

                    if (op2 < 0)
                    {
                        printf("Negative exponent not supported\n");
                        exit(1);
                    }

                    value = 1;

                    for (j = 0; j < op2; j++)
                    {
                        value *= op1;
                    }

                    break;
                }

                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(&s, value);
        }
        else
        {
            printf("Invalid token: %s\n", token);
            exit(1);
        }

        token = strtok(NULL, " ");
    }

    if (s.top != 0)
    {
        printf("Invalid postfix expression\n");
        exit(1);
    }

    return pop(&s);
}

int main()
{
    char postfix[MAX];
    int result;

    printf("Enter postfix expression with spaces between operands and operators:\n");
    fgets(postfix, MAX, stdin);

    postfix[strcspn(postfix, "\n")] = '\0';

    result = evaluatePostfix(postfix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Result: %d\n", result);

    return 0;
}