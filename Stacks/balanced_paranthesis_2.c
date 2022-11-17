#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};
struct node *head;

struct node *create_node(char n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}

struct node *push(char p)
{
    struct node *temp;
    temp = create_node(p);
    if (head == NULL)
        return temp;
    temp->next = head;
    head = temp;
    return temp;
}

struct node *pop()
{
    if (head == NULL)
    {
        printf("\nstack is empty");
        return 0;
    }
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

void checkbalanced_paranthesis(char s[])
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            head = push(s[i]);
        else if (head->data == '(' && s[i] == ')' || head->data == '{' && s[i] == '}' || head->data == '[' && s[i] == ']')
            head = pop();
        else
        {
            printf("Not Balanced\n");
            exit(0);
        }
    }
    if (head == NULL)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return;
}

int main()
{
    char exp[50];
    printf("Enter exression\n");
    scanf("%s", exp);
    checkbalanced_paranthesis(exp);
    return 0;
}

