#include <stdio.h>
#include <process.h>
#define size 4
struct stack
{
	int arr[size];
	int sp;
};

int isFull(struct stack s)
{
	if (s.sp >= size)
		return 1;
	else
		return 0;
}

int isEmpty(struct stack s)
{
	if (s.sp == 0)
		return 1;
	else
		return 0;
}

void push(struct stack *s, int v)
{
	if (isFull(*s))
		printf("Stack overflow\n");
	else
	{
		s->arr[s->sp] = v;
		s->sp++;
	}
}
void pop(struct stack *s)
{
	if (isEmpty(*s))
		printf("Stack Underflow\n");
	else
		printf("Poped element is %d\n",s->arr[--s->sp]);
}
int peep(struct stack *s)
{
	if (isEmpty(*s))
		return 1;
	else
		return s->arr[s->sp - 1];
}

void display(struct stack *s)
{
	if (isEmpty(*s))
		printf("No elements to display\n");
	else
	{
		int a=s->sp;
		printf("Elements are: ");
		for (--s->sp; s->sp >= 0; s->sp--)
			printf("%d ", s->arr[s->sp]);
		s->sp=a;
		printf("\n");
	}
}

void main()
{
	int a, b, c;
	struct stack s;
	s.sp = 0;
	while (1)
	{
		printf("\n****STACK MENU****:");
		printf("\nPress desired option");
		printf("\n1-Push\n2-Peep\n3-Pop\n4-Display\n5-To check if the stack is full\n6-To check if the stack is empty\n7-To exit\n\n");
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter a no. to be pushed\n");
			scanf("%d", &a);
			push(&s, a);
			break;
		case 2:
			b = peep(&s);
			if (b == 1)
				printf("\nStack is empty");
			else
				printf("Top most element is %d\n", b);
			break;
		case 3:
			pop(&s);
			break;
		case 4:
			display(&s);
			break;
		case 5:
			if (isFull(s))
				printf("Stack is full, total no. of elements in the stack is %d\n", size);
			else
				printf("Stack is not full, no. of elements present = %d",s.sp);
			break;
		case 6:
			if (isEmpty(s))
				printf("Stack is empty\n");
			else
				printf("Stack is not empty, no. of elements present = %d",s.sp);
			break;
		case 7:
			exit(0);
		default:
			printf("Enter a valid choice\n");
		}
	}
}

