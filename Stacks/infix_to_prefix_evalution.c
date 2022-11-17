// INFIX TO PREFIX AND PREFIX EVALUTION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10
struct stack
{
    char a[SIZE];
    int sp;
};

int is_empty(struct stack s)
{
    if (s.sp == 0)
        return 1;
    else
        return 0;
}

int is_full(struct stack s)
{
    if (s.sp >= SIZE)
        return 1;
    else
        return 0;
}

void push(struct stack *s, char n)
{
    if (is_full(*s))
    {
        printf("Stack overflow\n");
        exit(0);
    }
    else
        s->a[s->sp++] = n;
}

char peep(struct stack s)
{
    if (is_empty(s))
    {
        printf("Stack is empty\n");
        exit(0);
    }
    else
        return s.a[s.sp - 1];
}

char pop(struct stack *s)
{
    if (is_empty(*s))
    {
        printf("Stack is empty\n");
        exit(0);
    }
    else
        return s->a[--s->sp];
}

int precedence(char n)
{
    if (n == '#')
        return 0;
    else if (n == '+' || n == '-')
        return 1;
    else if (n == '/' || n == '*' || n == '%')
        return 2;
    else
        return -1;
}

char *to_postfix(char *infix)
{
    struct stack s;
    s.sp = 0;
    char *post = (char *)malloc(sizeof(strlen(infix) + 1));
    char *temp = post;
    char next = *infix++;
    push(&s, '#');
    while (next != '\0')
    {
        if (isalpha(next) || isdigit(next))
        {
            *post = next;
            post++;
            next = *infix++;
        }
        else
        {
            if (precedence(next) == -1)
            {
                printf("Enter valid expression\n");
                exit(0);
            }
            while (precedence(next) <= precedence(peep(s)))
            {
                *post = pop(&s);
                post++;
            }
            push(&s, next);
            next = *infix++;
        }
    }
    while (!is_empty(s))
    {
        next = pop(&s);
        if (next == '#')
            break;
        else
        {
            *post = next;
            post++;
        }
    }
    *post = '\0';
    return temp;
}

int evaluate(char *post)
{
    struct stack s;
    s.sp = 0;
    char op1, op2;
    while (*post != '\0')
    {
        if (isalpha(*post))
        {
            printf("Value can't be computed\n");
            break;
        }
        else if (isdigit(*post))
        {
            *post -= 48;
            push(&s, *post);
            post++;
        }
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);
            switch (*post)
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '/':
                push(&s, op1 * op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '%':
                push(&s, op1 % op2);
                break;
            default:
                printf("Enter a valid expression\n");
                exit(0);
            }
            post++;
        }
    }
    return pop(&s);
}

void main()
{
    char infix[SIZE];
    char *postfix;
    int result;
    printf("Enter a valid infix expression\n");
    scanf("%s", infix);
    int n1 = strlen(infix);
    for (int i = 0; i <= (n1 / 2); i++)
    {
        char temp = infix[i];
        infix[i] = infix[n1 - 1 - i];
        infix[n1 - 1 - i] = temp;
    }
    postfix = to_postfix(infix);
    int n2 = strlen(postfix);
    printf("Prefix expression is: ");
    for (int i = n2 - 1; i >= 0; i--)
        printf("%c", postfix[i]);
    result = evaluate(postfix);
    printf("\n");
    printf("Value of the infix is %d\n", result);
}
