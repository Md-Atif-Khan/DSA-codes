#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <process.h>
#include <string.h>
#define size 10
struct stack
{
    char arr[size];
    int sp;
};
int isempty(struct stack s)
{
    if (s.sp == 0)
        return 1;
    else
        return 0;
}
void push(struct stack *s, char v)
{
    if (s->sp < size)
    {
        s->arr[s->sp] = v;
        s->sp++;
    }
    else
    {
        printf("\nStack Overflow...");
        exit(0);
    }
}
char pop(struct stack *s)
{
    if (s->sp == 0)
    {
        printf("\n Stack Underflow...");
        exit(0);
    }
    else
    {
        --s->sp;
        return s->arr[s->sp];
    }
}
char peep(struct stack s)
{
    if (s.sp == 0)
    {
        printf("\n Stack Underflow...");
        exit(0);
    }
    else
    {
        return s.arr[s.sp - 1];
    }
}
int precedence(char ch)
{
    if (ch == '#')
        return 0;
    else if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 3;
    else if (ch == '^')
        return 4;
    else
    {
        printf("\n Invalid operator....");
        return -1;
    }
}

char *convert(char *infix) // OR (char infix[])
{
    struct stack s;
    char next, *temp;
    char *post = (char *)malloc(strlen(infix) + 2);
    int i;
    temp = post;
    s.sp = 0;
    push(&s, '#');
    next = *infix++;
    while (next != '\0')
    {
        if (isdigit(next) || isalpha(next))
        {
            *post = next;
            post++;
        }
        else
        {
            if (precedence(next) != -1)
            {
                while (precedence(next) <= precedence(peep(s)))
                {
                    *post = pop(&s);
                    post++;
                }
                push(&s, next);
            }
        }
        next = *infix++;
    }
    while (!isempty(s))
    {
        next = pop(&s);
        if (next == '#')
            break;
        *post = next;
        post++;
    }
    *post = '\0';
    return temp;
}

int evaluate(char *post)
{
    int op1, op2, op3;
    char op;
    struct stack s;
    s.sp = 0;
    op = *post++;
    while (op != '\0')
    {
        if (op >= 48 && op <= 57)
        {
            op3 = op - '0';
            push(&s, op3);
        }
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);
            switch (op)
            {
            case '+':
                op3 = op2 + op1;
                break;
            case '-':
                op3 = op2 - op1;
                break;
            case '*':
                op3 = op2 * op1;
                break;
            case '/':
                op3 = op2 / op1;
                break;
            case '%':
                op3 = op2 % op1;
                break;
            default:
                printf("\n Invalid operator %c", op);
            }
            push(&s, op3);
        }
        op = *post++;
    }
    return pop(&s);
}
void main()
{
    char infix[20];
    char *postfix;
    int result;
    printf("\n Enter any valid infix: ");
    scanf("%s", infix);
    postfix = convert(infix);
    printf("\n Postfix  =  %s", postfix);
    result = evaluate(postfix);
    printf("\nResult of %s  = %d", infix, result);
}

