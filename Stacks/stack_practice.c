// STACKS USING ARRAYS
//  #include<stdio.h>
//  #include<stdlib.h>
//  # define SIZE 4
//  struct stack
//  {
//      int a[SIZE];
//      int sp;
//  };

// int is_full(struct stack s)
// {
//     if(s.sp>=SIZE)
//         return 1;
//     else
//         return 0;
// }

// int is_empty(struct stack s)
// {
//     if(s.sp==0)
//         return 1;
//     else
//         return 0;
// }

// void push(struct stack *s, int n)
// {
//     if(is_full(*s))
//         printf("Stack overflow\n");
//     else
//     {
//         s->a[s->sp]=n;
//         s->sp++;
//     }
// }

// void pop(struct stack *s)
// {
//     if(is_empty(*s))
//         printf("Stack underflow\n");
//     else
//         printf("Poped element is %d \n", s->a[--s->sp]);
// }

// void peep(struct stack *s)
// {
//     if(is_empty(*s))
//         printf("Stack is empty\n");
//     else
//         printf("Top element is %d \n", s->a[s->sp-1]);
// }

// void display(struct stack *s)
// {
//     if(is_empty(*s))
//         printf("Stack is empty\n");
//     else
//     {
//         printf("Elements are : ");
//         struct stack t=*s;
//         while(t.sp!=0)
//             printf("%d ", t.a[--t.sp]);
//         printf("\n\n");
//     }
// }

// void main()
// {
//     struct stack s;
//     s.sp=0;
//     while(1)
//     {
//         printf("****MENU****\n");
//         printf("Select desired option\n");
//         printf("1-Push\n");
//         printf("2-Pop\n");
//         printf("3-Peep\n");
//         printf("4-Display\n");
//         printf("5-Check if the stack is full\n");
//         printf("6-Check if the stack is empty\n");
//         printf("7-Exit\n");
//         int choice;
//         scanf("%d", &choice);
//         switch(choice)
//         {
//             case 1:
//                 printf("Enter a element to be inserted\n");
//                 int n;
//                 scanf("%d", &n);
//                 push(&s, n);
//                 break;

//             case 2:
//                 pop(&s);
//                 break;

//             case 3:
//                 peep(&s);
//                 break;

//             case 4:
//                 display(&s);
//                 break;

//             case 5:
//                 if(is_full(s))
//                     printf("Stack is full\n");
//                 else
//                     printf("Stack is not full, total no. of elements in the stack is %d\n", s.sp);
//                 break;

//             case 6:
//                 if(is_empty(s))
//                     printf("Stack is empty\n");
//                 else
//                     printf("Stack is not empty, total no. of elements in the stack is %d\n", s.sp);
//                 break;

//             case 7:
//                 return;
//                 break;
//         }
//     }
// }

// STACKS USING LINKED LIST
//  #include <stdio.h>
//  #include <stdlib.h>

// struct node
// {
//     int val;
//     struct node *next;
// };

// struct node *create_node(int n)
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     temp->next = NULL;
//     temp->val = n;
//     return temp;
// }

// int is_empty(struct node *h)
// {
//     if (h == NULL)
//         return 1;
//     else
//         return 0;
// }

// struct node *push(struct node *h, int n)
// {
//     struct node *t = create_node(n);
//     if (is_empty(h))
//         return t;
//     else
//     {
//         t->next = h;
//         h = t;
//         return h;
//     }
// }

// void peep(struct node *h)
// {
//     if (is_empty(h))
//         printf("Stack is empty\n");
//     else
//         printf("Element is %d\n", h->val);
// }

// struct node *pop(struct node *h)
// {
//     if (is_empty(h))
//         printf("Stack underflow\n");
//     else
//     {
//         struct node *t = h;
//         h = h->next;
//         free(t);
//     }
//     return h;
// }

// void display(struct node *h)
// {
//     if (is_empty(h))
//         printf("Stack is empty\n");
//     else
//     {
//         struct node *f = h;
//         printf("Elements of stack are: ");
//         while (f != NULL)
//         {
//             printf("%d ", f->val);
//             f = f->next;
//         }
//         printf("\n");
//     }
// }

// void get_index(struct node *h, int n)
// {
//     if (is_empty(h))
//         printf("Stack is empty\n");
//     else
//     {
//         int i = 1;
//         struct node *f = h;
//         while (f != NULL && f->val != n)
//         {
//             f = f->next;
//             i++;
//         }
//         if (f == NULL)
//             printf("Given element doesn't exist\n");
//         else
//             printf("Index of %d is: %d\n", n, i);
//     }
// }

// void get_val(struct node *h, int n)
// {
//     if (is_empty(h))
//         printf("Stack is empty\n");
//     else
//     {
//         int pos = 1;
//         struct node *t = h;
//         while (t != NULL && pos != n)
//         {
//             t = t->next;
//             pos++;
//         }
//         if (t == NULL)
//             printf("Given index doesn't exist\n");
//         else
//             printf("Value at index %d is %d\n", n, t->val);
//     }
// }

// void main()
// {
//     struct node *head;
//     int n, f = 0;
//     while (1)
//     {
//         printf("****MENU****\n");
//         printf("Enter a option\n");
//         printf("1-Push\n");
//         printf("2-Peep\n");
//         printf("3-Pop\n");
//         printf("4-Display\n");
//         printf("5-To check if the stack is empty\n");
//         printf("6-Get the index of an element\n");
//         printf("7-Get the element at the index\n");
//         printf("8-To exit\n");

//         int choice;
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             printf("Enter the no. to be pushed in the stack\n");
//             scanf("%d", &n);
//             if (head == NULL)
//                 head = create_node(n);
//             else
//                 head = push(head, n);
//             f++;
//             break;

//         case 2:
//             peep(head);
//             break;

//         case 3:
//             head = pop(head);
//             f--;
//             break;

//         case 4:
//             display(head);
//             break;

//         case 5:
//             if (is_empty(head))
//                 printf("Stack is empty\n");
//             else
//                 printf("Stack is not empty, no. of elements present: %d", f);
//             break;

//         case 6:
//             printf("Enter the element\n");
//             scanf("%d", &n);
//             get_index(head, n);
//             break;

//         case 7:
//             printf("Enter the index\n");
//             scanf("%d", &n);
//             get_val(head, n);
//             break;

//         case 8:
//             exit(0);
//             break;

//         default:
//             printf("Enter a valid option\n");
//             break;
//         }
//     }
// }

// CONVERTING DATATYPE OF STRING OF NUMBERS TO INTEGER
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>

// int fun(char *s)
// {
//     int sum = 0;
//     for (int i = 0; i < strlen(s); i++)
//         sum = sum * 10 + (s[i] - 48);
//     return sum;
// };

// int main()
// {
//     char s[100] = "20";
//     char s1[100] = "14";
//     int a = fun(s);
//     int b = fun(s1);
//     printf("The integer value is %d\n", a);
//     printf("The integer value is %d\n", b);
//     printf("The integer value is %d\n", a + b);

//     return 0;
// }

// INFIX TO POSTFIX EVALUTION
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// #define SIZE 10
// struct stack
// {
//     char a[SIZE];
//     int sp;
// };

// int is_full(struct stack s)
// {
//     if (s.sp >= SIZE)
//         return 1;
//     else
//         return 0;
// }

// int is_empty(struct stack s)
// {
//     if (s.sp == 0)
//         return 1;
//     else
//         return 0;
// }

// void push(struct stack *s, char n)
// {
//     if (is_full(*s))
//         printf("Stack overflow\n");
//     else
//         s->a[s->sp++] = n;
// }

// char peep(struct stack s)
// {
//     if (is_empty(s))
//     {
//         printf("Stack is empty\n");
//         exit(0);
//     }
//     else
//         return s.a[s.sp - 1];
// }

// char pop(struct stack *s)
// {
//     if (is_empty(*s))
//     {
//         printf("Stack is empty\n");
//         exit(0);
//     }
//     else
//         return s->a[--s->sp];
// }

// int precedence(char next)
// {
//     if (next == '#')
//         return 0;
//     else if (next == '+' || next == '-')
//         return 1;
//     else if (next == '*' || next == '/' || next == '%')
//         return 2;
//     return -1;
// }

// char *to_postfix(char *infix)
// {
//     char *post = (char *)malloc(sizeof(strlen(infix) + 1));
//     char *temp = post;
//     char next = *infix++;
//     struct stack s;
//     s.sp = 0;
//     push(&s, '#');
//     while (next != '\0')
//     {
//         if (isdigit(next) || isalpha(next))
//         {
//             *post = next;
//             post++;
//             next = *infix++;
//         }
//         else
//         {
//             if (precedence(next) == -1)
//             {
//                 printf("Enter a valid expression\n");
//                 exit(0);
//             }
//             else
//             {
//                 while (precedence(next) <= precedence(peep(s)))
//                 {
//                     *post = pop(&s);
//                     post++;
//                 }
//                 push(&s, next);
//                 next = *infix++;
//             }
//         }
//     }
//     while (is_empty(s) == 0)
//     {
//         next = pop(&s);
//         if (next == '#')
//             break;
//         *post = next;
//         post++;
//     }
//     *post = '\0';
//     return temp;
// }

// int evaluate(char *post)
// {
//     char op;
//     int op1, op2, op3;
//     struct stack s;
//     s.sp = 0;
//     while (*post != '\0')
//     {
//         if (isalpha(*post))
//         {
//             printf("Value cannot be computed\n");
//             exit(0);
//         }
//         else if (isdigit(*post))
//         {
//             *post-=48;
//             push(&s, *post);
//         }
//         else
//         {
//             op1 = pop(&s);
//             op2 = pop(&s);
//             op = *post;
//             switch (op)
//             {
//             case '+':
//                 push(&s, op2 + op1);
//                 break;
//             case '-':
//                 push(&s, op2 - op1);
//                 break;
//             case '*':
//                 push(&s, op2 * op1);
//                 break;
//             case '/':
//                 push(&s, op2 / op1);
//                 break;
//             case '%':
//                 push(&s, op2 % op1);
//                 break;
//             default:
//                 printf("Invalid expression\n");
//                 exit(0);
//             }
//         }
//         post++;
//     }
//     return pop(&s);
// }

// void main()
// {
//     char infix[SIZE];
//     char *postfix;
//     int result;
//     printf("Enter a correct infix expression\n");
//     scanf("%s", infix);
//     postfix = to_postfix(infix);
//     printf("Postfix expression is %s\n", postfix);
//     result = evaluate(postfix);
//     printf("The value of the given infix expression is %d\n", result);
// }

// INFIX TO PREFIX AND PREFIX EVALUTION
//  #include <stdio.h>
//  #include <stdlib.h>
//  #include <string.h>
//  #include <ctype.h>

// #define SIZE 10
// struct stack
// {
//     char a[SIZE];
//     int sp;
// };

// int is_empty(struct stack s)
// {
//     if (s.sp == 0)
//         return 1;
//     else
//         return 0;
// }

// int is_full(struct stack s)
// {
//     if (s.sp >= SIZE)
//         return 1;
//     else
//         return 0;
// }

// void push(struct stack *s, char n)
// {
//     if (is_full(*s))
//     {
//         printf("Stack overflow\n");
//         exit(0);
//     }
//     else
//         s->a[s->sp++] = n;
// }

// char peep(struct stack s)
// {
//     if (is_empty(s))
//     {
//         printf("Stack is empty\n");
//         exit(0);
//     }
//     else
//         return s.a[s.sp - 1];
// }

// char pop(struct stack *s)
// {
//     if (is_empty(*s))
//     {
//         printf("Stack is empty\n");
//         exit(0);
//     }
//     else
//         return s->a[--s->sp];
// }

// int precedence(char n)
// {
//     if (n == '#')
//         return 0;
//     else if (n == '+' || n == '-')
//         return 1;
//     else if (n == '/' || n == '*' || n == '%')
//         return 2;
//     else
//         return -1;
// }

// char *to_postfix(char *infix)
// {
//     struct stack s;
//     s.sp = 0;
//     char *post = (char *)malloc(sizeof(strlen(infix)+1));
//     char *temp = post;
//     char next = *infix++;
//     push(&s, '#');
//     while (next != '\0')
//     {
//         if (isalpha(next) || isdigit(next))
//         {
//             *post = next;
//             post++;
//             next = *infix++;
//         }
//         else
//         {
//             if (precedence(next) == -1)
//             {
//                 printf("Enter valid expression\n");
//                 exit(0);
//             }
//             while (precedence(next) <= precedence(peep(s)))
//             {
//                 *post = pop(&s);
//                 post++;
//             }
//             push(&s, next);
//             next = *infix++;
//         }
//     }
//     while (!is_empty(s))
//     {
//         next = pop(&s);
//         if (next == '#')
//             break;
//         else
//         {
//             *post = next;
//             post++;
//         }
//     }
//     *post = '\0';
//     return temp;
// }

// int evaluate(char *post)
// {
//     struct stack s;
//     s.sp = 0;
//     char op1, op2;
//     while (*post != '\0')
//     {
//         if (isalpha(*post))
//         {
//             printf("Value can't be computer\n");
//             break;
//         }
//         else if (isdigit(*post))
//         {
//             *post -= 48;
//             push(&s, *post);
//             post++;
//         }
//         else
//         {
//             op1 = pop(&s);
//             op2 = pop(&s);
//             switch (*post)
//             {
//             case '+':
//                 push(&s, op1 + op2);
//                 break;
//             case '-':
//                 push(&s, op1 - op2);
//                 break;
//             case '/':
//                 push(&s, op1 / op2);
//                 break;
//             case '*':
//                 push(&s, op1 * op2);
//                 break;
//             case '%':
//                 push(&s, op1 % op2);
//                 break;
//             default:
//                 printf("Enter a valid expression\n");
//                 exit(0);
//             }
//             post++;
//         }
//     }
//     return pop(&s);
// }

// void main()
// {
//     char infix[SIZE];
//     char *postfix;
//     int result;
//     printf("Enter a valid infix expression\n");
//     scanf("%s", infix);
//     int  n1 = strlen(infix);
//     for (int i = 0; i < (n1 / 2); i++)
//     {
//         char temp = infix[i];
//         infix[i] = infix[n1 - 1 - i];
//         infix[n1 - 1 - i] = temp;
//     }
//     postfix = to_postfix(infix);
//     int n2 = strlen(postfix);
//     printf("Prefix expression is: ");
//     for(int i=n2-1; i>=0; i--)
//         printf("%c", postfix[i]);
//     result = evaluate(postfix);
//     printf("\n");
//     printf("Value of the infix is %d\n", result);
// }

// BALANCED PARANTHESIS(BY USING ARRAYS)
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define SIZE 10

// struct stack
// {
//     int sp;
//     char a[SIZE];
// };

// int is_empty(struct stack s)
// {
//     if (s.sp == 0)
//         return 1;
//     else
//         return 0;
// }

// int is_full(struct stack s)
// {
//     if (s.sp >= SIZE)
//         return 1;
//     else
//         return 0;
// }

// void push(struct stack *s, char n)
// {
//     if (is_full(*s))
//         return;
//     else
//         s->a[s->sp++] = n;
// }

// void pop(struct stack *s)
// {
//     if (is_empty(*s))
//         return;
//     else
//         s->sp--;
// }

// char peep(struct stack *s)
// {
//     if (is_empty(*s))
//         return 'e';
//     else
//         return s->a[s->sp - 1];
// }

// void check_balancing(char *str)
// {
//     struct stack s;
//     s.sp = 0;
//     for (int i = 0; i < strlen(str); i++)
//     {
//         if (str[i] == '(' || str[i] == '{' || str[i] == '[')
//         {
//             if (is_full(s))
//             {
//                 printf("Size exceeded\n");
//                 return;
//             }
//             else
//                 push(&s, str[i]);
//         }
//         else if ((str[i] == ')' && peep(&s) == '(') || (str[i] == '}' && peep(&s) == '{') || (str[i] == ']' && peep(&s) == '['))
//             pop(&s);
//         else if (str[i] != '(' && str[i] != ')' && str[i] != '{' && str[i] != '}' && str[i] != '[' && str[i] != ']')
//         {
//             printf("Enter a valid sequence of paranthesis\n");
//             return;
//         }
//         else
//         {
//             printf("Not balanced\n");
//             return;
//         }
//     }
//     if (is_empty(s))
//         printf("Balanced\n");
//     else
//         printf("Not Balanced\n");
// }
// void main()
// {
//     char str[SIZE];
//     char choice;
//     while (1)
//     {
//         printf("Want to check balance paranthesis [Y/N]\n");
//         scanf("%c", &choice);
//         if (choice == 'y' || choice == 'Y')
//         {
//             printf("Enter a sequence of paranthesis\n");
//             scanf("%s", str);
//             check_balancing(str);
//         }
//         else
//             return;
//     }
// }

// BALANCING PARANTHESIS(USING LINKED LIST)
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define SIZE 20
// struct node
// {
//     char val;
//     struct node *next;
// };

// int is_empty(struct node *h)
// {
//     if (h == NULL)
//         return 1;
//     else
//         return 0;
// }

// struct node *create_node(char n)
// {
//     struct node *t = (struct node *)malloc(sizeof(struct node));
//     t->val = n;
//     t->next = NULL;
//     return t;
// }

// struct node *push(struct node *h, char n)
// {
//     struct node *t = create_node(n);
//     if (is_empty(h))
//         return t;
//     else
//     {
//         t->next = h;
//         h = t;
//         return h;
//     }
// }

// struct node *pop(struct node *h)
// {
//     if (is_empty(h))
//         return NULL;
//     else
//     {
//         struct node *t = h;
//         h = h->next;
//         free(t);
//         return h;
//     }
// }

// char peep(struct node *h)
// {
//     if (is_empty(h))
//         return 'e';
//     else
//         return h->val;
// }

// void check_balancing(struct node *h, char *s)
// {
//     for (int i = 0; i < strlen(s); i++)
//     {
//         if (s[i] == '(' || s[i] == '{' || s[i] == '[')
//             h = push(h, s[i]);
//         else if ((s[i] == ')' && peep(h) == '(') || (s[i] == '}' && peep(h) == '{') || (s[i] == ']' && peep(h) == '['))
//             h = pop(h);
//         else if (s[i] != '(' && s[i] != ')' && s[i] != '{' && s[i] != '}' && s[i] != '[' && s[i] != ']')
//         {
//             printf("Enter a valid sequence of paranthesis\n");
//             return;
//         }
//         else
//         {
//             printf("Not balanced\n");
//             return;
//         }
//     }
//     if (is_empty(h))
//         printf("Balanced\n");
//     else
//         printf("Not Balanced\n");
// }

// void main()
// {
//     struct node *head = NULL;
//     char choice;
//     char s[SIZE];
//     while (1)
//     {
//         printf("Want to check balance paranthesis [y/n]\n");
//         scanf("%c", &choice);
//         if (choice == 'Y' || choice == 'y')
//         {
//             printf("Enter a sequence of paranthesis\n");
//             scanf("%s", s);
//             check_balancing(head, s);
//         }
//         else
//             exit(0);
//     }
// }

// REVERSE STRING
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// struct node
// {
//     char val;
//     struct node *next;
// };

// struct node *create_node(char v)
// {
//     struct node *t;
//     t = (struct node *)malloc(sizeof(struct node));
//     t->val = v;
//     t->next = NULL;
//     return t;
// }

// int isempty(struct node *h)
// {
//     struct node *t;
//     if (h == NULL)
//         return 1;
//     else
//         return 0;
// }

// struct node *push(struct node *h, char v)
// {
//     struct node *t;
//     t = create_node(v);
//     if (isempty(h))
//         return t;
//     else
//     {
//         t->next = h;
//         h = t;
//         return h;
//     }
// }

// struct node *pop(struct node *h)
// {
//     struct node *t;
//     if (isempty(h))
//         exit(0);
//     else
//     {
//         t = h;
//         h = h->next;
//         free(t);
//         return h;
//     }
// }

// void rev_display(struct node **h)
// {
//     if (isempty(*h))
//         printf("Stack is empty\n");
//     else
//     {
//         printf("Reverse string: ");
//         while (*h != NULL)
//         {
//             printf("%c", (*h)->val);
//             *h = pop(*h);
//         }
//         printf("\n");
//     }
// }

// void main()
// {
//     struct node *head = NULL;
//     char str[100];
//     printf("enter the string\n");
//     scanf(" %[^\n]s", str);
//     for (int i = 0; i < strlen(str); i++)
//         head = push(head, str[i]);
//     rev_display(&head);
//     if (isempty(head))
//         printf("YES");
//     else
//         printf("NO");
// }

// #include<stdio.h>
// #include<stdlib.h>
// #include<ctype.h>
// #include<string.h>
// #include<math.h>
// #define size 20

// struct stack
// {
//     char arr[size];
//     int sp;
// };

// void push(struct stack *s,char h)
// {
//     if(s->sp<size)
//     {
//         (s->sp)++;
//         s->arr[s->sp]=h;
//         return;
//     }
//     else
//     {
//         printf("STACK IS OVERFLOW\n");
//         return;
//     }
// }

// char pop(struct stack *s)
// {
//     char temp;
//     if(s->sp>=0)
//     {
//         temp=s->arr[s->sp];
//         (s->sp)--;
//         return temp;
//     }
//     else
//     {
//         printf("STACK IS UNDERFLOW\n");
//         exit(0);
//     }
// }

// char ctop(struct stack *s)
// {
//     char temp;
//     if(s->sp>=0)
//     {
//         temp=s->arr[s->sp];
//         return temp;
//     }
//     else
//     {
//         printf("STACK IS UNDERFLOW\n");
//         exit(0);
//     }
// }

// int prec(char h)
// {
//     if(h=='+'||h=='-')
//     {
//         return 2;
//     }
//     if(h=='*'||h=='/')
//     {
//         return 5;
//     }
//     if(h=='^')
//     {
//         return 1;
//     }
//     return 0;
// }

// char *convert(char infix[])
// {
//     struct stack s;
//     char *post=(char *)malloc(strlen(infix)+1);
//     char *temp;
//     temp=post;
//     char next;
//     next=infix[0];
//     int i=0;
//     s.sp=-1;
//     push(&s,'#');
//     while(next!='\0')
//     {
//         if(isdigit(next))
//         {
//             *post=next;
//             post++;
//         }
//         else
//         {
//             while(prec(next)<prec(ctop(&s)))
//             {
//                 *post=pop(&s);
//                 post++;
//             }
//             push(&s,next);
//         }
//         next=infix[++i];
//     }
//     next=pop(&s);
//     while(next!='#')
//     {
//         *post=next;
//         post++;
//         next=pop(&s);
//     }
//     *post='\0';
//     return temp;
// }

// struct	cstack
// {
// int	arr[size];
// int sp;
// };
// void cpush(struct cstack *s,int val)
// {
//    if(s->sp<size)
//      {
//         (s->sp)++;
//         s->arr[s->sp] = val;

//      }
//    else
//      {  printf("\n Stack Overflow");
//         exit(0);
//      }
// }
// int cpop(struct cstack *s)
// {
//    int temp;
//    if(s->sp>=0)
//      {
//         temp=   s->arr[s->sp];
//          (s->sp)--;return temp;
//      }
//    else
//      {  printf("\n Stack underflow");
//         exit(0);
//      }

// }

// int evaluate(char post[])
// {
// 	struct cstack s;
// 	int op1,op2,op3,i;
// 	char next;
// 	s.sp=-1;
// 	i=0;
// 	while(post[i]!='\0')
// 	{
// 		next = post[i];
// 		if(isdigit(next))
// 		   cpush(&s,next-'0');
// 		else
// 		 {
// 		 	op1= cpop(&s);
// 		 	op2 = cpop(&s);
// 		 	switch(next)
// 		 	{
// 		 		case '+': op3 = op1+op2; break;
// 		 		case '-': op3 = op1-op2; break;
// 		 		case '*': op3 = op1*op2; break;
// 		 		case '/': op3 = op1/op2; break;
// 		 		case '%': op3 = op1%op2; break;
// 		 		default: printf("\n Invalid Operator");
// 			 }
// 			 cpush(&s,op3);
// 		}
// 		i++;
// 	}
// 	return cpop(&s);
// }

// int main()
// {
//     char choice;
//     char *post;
//     char infix[100];
//     char temp;
//     int n;
//     int eva;
//     while(1)
//     {
//    //FOR CONVERTING INFIX TO PREFIX-->REVERSE THE GIVEN INFIX AND WRITE ITS POSTFIX EXPRESSION AND REVERSE IT
//    //FOR EVALUATING THE PREFIX EXPRESSION-->IN THE POSTFIX EVALUTION SWAP ALL OP2 WITH OP1 AND VICE-VERSA(WITH POSTFIX EXPRESSION OF THE)
//    //                                                                                            (REVERSED INFIX AS THE INPUT)
//         printf("\nDO YOU WANT TO CONVERT[Y:N]\n");
//         scanf("%c", &choice);
//         switch(choice)
//         {
//             case 'Y':
//                 printf("PLEASE ENTER THE INFIX\n");
//                 scanf("%s", infix);
//                 n=strlen(infix);
//                 for(int i=0;i<n/2;i++)
//                 {
//                     temp=infix[i];
//                     infix[i]=infix[n-1-i];
//                     infix[n-1-i]=temp;
//                 }
//                 //printf("%s", infix);
//                 post=convert(infix);
//                 printf("PREFIX-->");
//                 for(int i=strlen(infix);i>=0;i--)
//                 {
//                     printf("%c", post[i]);
//                 }
//                 //printf("%s", post);
//                 eva=evaluate(post);
//                 printf("\n RESULT-->%d", eva);
//                 break;
//             case 'N':
//                 exit(0);
//                 break;
//         }
//         choice=getchar();
//     }
// }
