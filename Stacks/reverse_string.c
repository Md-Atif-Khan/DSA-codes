#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10
struct stack
{
    char a[size];
    int sp;
};

int is_full(struct stack s)
{
    if(s.sp >= size)
        return 1;
    else
        return 0;
}

void push(struct stack *s, char x)
{
    if(is_full(*s))
        printf("Stack overflow\n");
    else
        s->a[s->sp++] = x;
}

char pop(struct stack *s)
{
    return s->a[--s->sp];
}

void reverse_string(struct stack *s, char a[])
{
    int n = strlen(a);
    for(int i=0; i<n; i++)
        push(s, a[i]);
    for(int i=0; i<n; i++)
        a[i] = pop(s);
}

void main()
{
    struct stack s;
    s.sp = 0;
    char a[size];
    printf("Enter the string\n");
    scanf("%s", a);
    reverse_string(&s, a);
    printf("%s", a);
}