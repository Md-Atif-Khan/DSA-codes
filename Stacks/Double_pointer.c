#include <stdio.h>
#include <stdlib.h>
#include <process.h>
struct node
{
   int val;
   struct node *next;
};

struct node *create_node(int v)
{
   struct node *temp;
   temp = (struct node *)malloc(sizeof(struct node));
   temp->val = v;
   temp->next = NULL;
   return temp;
}

void push(struct node **h, int v)
{
   struct node *t;
   t = create_node(v);
   if (*h == NULL)
      *h = t;
   else
   {
      t->next = *h;
      *h = t;
   }
}

int pop(struct node **h)
{
   int val;
   struct node *t;
   if (*h == NULL)
      return 0;
   else
      val = (*h)->val;
   t = *h;
   *h = (*h)->next;
   free(t);
   return val;
}

int top(struct node **h)
{
   int val;
   struct node *t;
   if (*h == NULL)
      return 0;
   else
      val = (*h)->val;
   t = *h;
   *h = (*h)->next;
   free(t);
   return val;
}

void display_list(struct node *h)
{
   while (h != NULL)
   {
      printf("%d->", h->val);
      h = h->next;
   }
}

void main()
{
   struct node *stack = NULL;
   int n, pos;
   push(&stack, 5);
   push(&stack, 10);
   push(&stack, 7);
   push(&stack, 15);
   n = pop(&stack);
   printf("\n");
   printf("\n Deleted value = %d\n", n);
   n = pop(&stack);
   printf("\n");
   printf("\n Deleted value = %d\n", n);
}