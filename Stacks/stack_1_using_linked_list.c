#include <stdio.h>
#include <stdlib.h>

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

int isEmpty(struct node *h)
{
   if (h == NULL)
      return 1;
   else
      return 0;
}

struct node *push(struct node *h, int v) // insert at begining
{
   struct node *t;
   t = create_node(v);
   if (isEmpty(h))
      return t;
   else
   {
      t->next = h;
      h = t;
      return h;
   }
}

struct node *pop(struct node *h) // delete first
{
   if (isEmpty(h))
   {
      printf("\nStack underflow");
      return NULL;
   }
   else
   {
      struct node *t;
      t = h;
      h = h->next;
      free(t);
      return h;
   }
}

void peep(struct node *h)
{
   if (isEmpty(h))
      printf("\nStack underflow\n");
   else
      printf("%d\n", h->val);
}

void display_stack(struct node *h)
{
   if (isEmpty(h))
      printf("No elements to display\n");
   else
   {
      struct node *first = h;
      while (first != NULL)
      {
         printf("%d ", first->val);
         first = first->next;
      }
      printf("\n");
   }
}

void get_index(struct node *h, int n)
{
   struct node *f = h;
   if (isEmpty(f))
      printf("Stack is empty\n");
   else
   {
      int pos = 1;
      while (f != NULL && f->val != n)
      {
         f = f->next;
         pos++;
      }
      if (f == NULL)
         printf("Given element is not present\n");
      else
         printf("%d is present at index %d\n", n, pos);
   }
}

void get_element(struct node *h, int pos)
{
   struct node *f = h;
   if (isEmpty(f))
      printf("Stack is empty\n");
   else
   {
      int i = 1;
      while (f != NULL && pos != i)
      {
         f = f->next;
         i++;
      }
      if (f == NULL)
         printf("Given index doesn't exist\n");
      else
         printf("Element at %d index is %d \n", pos, f->val);
   }
}

void main()
{
   struct node *head = NULL;
   int n, f = 0;

   while (1)
   {
      printf("****STACK MENU****\n");
      printf("Press desired option\n");
      printf("1-Push\n");
      printf("2-Peep\n");
      printf("3-Pop\n");
      printf("4-Display\n");
      printf("5-To check if the stack is empty\n");
      printf("6-Get the index of an element\n");
      printf("7-Get the element at the index\n");
      printf("8-To exit\n");
      int choice;
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         printf(" Enter the integer to be inserted in the stack:");
         scanf("%d", &n);
         if (head == NULL)
         {
            head = create_node(n);
            f++;
         }
         else
         {
            head = push(head, n);
            f++;
         }
         break;

      case 2:
         peep(head);
         break;

      case 3:
         head = pop(head);
         f--;
         break;

      case 4:
         display_stack(head);
         break;

      case 5:
         if (isEmpty(head))
         {
            printf("\nStack is empty");
            break;
         }
         else
         {
            printf("\nStack is not empty: Filled entries are %d\n", f);
            break;
         }

      case 6:
         printf("Enter the element\n");
         scanf("%d", &n);
         get_index(head, n);
         break;

      case 7:
         printf("Enter the index\n");
         scanf("%d", &n);
         get_element(head, n);
         break;

      case 8:
         return;
         break;
         
      default:
         printf("Enter a valid option\n");
         break;
      }
   }
}

// #include<stdio.h>
// #include<stdlib.h>

// typedef int data;
// struct stack
// {
//     data d;
//     struct stack *next;
// };

// void push_back();
// void pop_front();
// void show();
// void isempty();
// void find_node();
// void find_data();
// void count();

// struct stack *head=NULL;
// int top=0;

// int main()
// {
//     int choice;
//     while(1)
//     {
//         printf("MENU CHOICE\n");
//         printf("1. ADD AN ELEMENT IN THE STACK\n");
//         printf("2. REMOVE AN ELEMENT FROM THE TOP OF THE STACK\n");
//         printf("3. SHOW THE STACK\n");
//         printf("4. CHECK THAT STACK IS EMPTY\n");
//         printf("5. FIND THE INDEX OF THE ELEMENT IN THE STACK\n");
//         printf("6. FIND THE ELEMENT OF THE INDEX IN THE STACK\n");
//         printf("7. NUMBER OF ELEMENTS IN A STACK\n");
//         printf("8. EXIT\n");
//         printf("PLEASE ENTER THE CHOICE\n");
//         scanf("%d", &choice);
//         switch(choice)
//         {
//             case 1:
//                 push_back();
//                 break;
//             case 2:
//                 pop_front();
//                 break;
//             case 3:
//                 show();
//                 break;
//             case 4:
//                 isempty();
//                 break;
//             case 5:
//                 find_node();
//                 break;
//             case 6:
//                 find_data();
//                 break;
//             case 7:
//                 count();
//                 break;
//             default:
//                 exit(0);
//                 break;
//         }
//     }
// }

// void push_back()
// {
//     struct stack *temp=NULL;
//     struct stack *ptr=NULL;
//     temp=(struct stack *)malloc(sizeof(struct stack));
//     if(temp==NULL)
//     {
//         printf("STACK IS EMPTY\n");
//         return;
//     }
//     printf("PLEASE ENTER THE NUMBER NEEDED TO BE ADDED\n");
//     scanf("%d", &temp->d);
//     temp->next=NULL;
//     top++;
//     if(head==NULL)
//     {
//         head=temp;
//     }
//     else
//     {
//         ptr=head;
//         while(ptr->next!=NULL)
//         {
//             ptr=ptr->next;
//         }
//         ptr->next=temp;
//     }
// }

// void pop_front()
// {
//     struct stack *temp=NULL;
//     struct stack *ptr=NULL;
//     if(head==NULL)
//     {
//         printf("STACK IS EMPTY\n");
//     }
//     else
//     {
//         ptr=head;
//         while(ptr->next!=NULL)
//         {
//             temp=ptr;
//             ptr=ptr->next;
//         }
//         temp->next=NULL;
//         printf("THE ELEMENT THAT IS DELETED IS %d\n", temp->d);
//         free(ptr);
//     }
// }

// void show()
// {
//     struct stack *temp=NULL;
//     struct stack *ptr=NULL;
//     if(head==NULL)
//     {
//         printf("STACK IS EMPTY\n");
//     }
//     else
//     {
//         while(ptr!=NULL)
//         {
//             printf("%d\n", ptr->d);
//             ptr=ptr->next;
//         }
//         return;
//     }
// }

// void isempty()
// {
//     if(head==NULL)
//     {
//         printf("STACK IS EMPTY\n");
//     }
//     else
//     {
//         printf("STACK IS NOT EMPTY\n");
//     }
//     return;
// }

// void find_node()
// {
//     struct stack *temp=NULL;
//     struct stack *ptr=NULL;
//     if(head==NULL)
//     {
//         printf("STACK IS EMPTY\n");
//     }
//     else
//     {
//         ptr=head;
//         int n;
//         printf("PLEASE ENTER THE VALUE WHOSE INDEX IS NEED TO BE FIND\n");
//         scanf("%d", &n);
//         for(int i=0;ptr!=NULL;i++)
//         {
//             if(ptr->d==n)
//             {
//                 printf("%d\n", top-i);
//                 return;
//             }
//             ptr=ptr->next;
//         }
//         printf("STACK IS OVERFLOW\n");
//     }
// }

// void find_data()
// {
//     struct stack *temp=NULL;
//     struct stack *ptr=NULL;
//     if(head==NULL)
//     {
//         printf("STACK IS EMPTY\n");
//     }
//     else
//     {
//         ptr=head;
//         int n;
//         printf("PLEASE ENTER THE INDEX WHOSE DATA IS NEED TO BE FIND\n");
//         scanf("%d", &n);
//         for(int i=0;i<n-1;i++)
//         {
//             ptr=ptr->next;
//         }
//         if(ptr!=NULL)
//         {
//             printf("%d\n", ptr->d);
//         }
//         else
//         {
//             printf("STACK IS OVERFLOW\n");
//         }
//         printf("%d", ptr->d);
//     }
// }

// void count()
// {
//     top=0;
//     struct stack *temp=NULL;
//     struct stack *ptr=NULL;
//     if(head==NULL)
//     {
//         printf("STACK IS EMPTY\n");
//     }
//     else
//     {
//         ptr=head;
//         while(ptr!=NULL)
//         {
//             ptr=ptr->next;
//             top++;
//         }
//         printf("%d/n", top);
//     }
// }