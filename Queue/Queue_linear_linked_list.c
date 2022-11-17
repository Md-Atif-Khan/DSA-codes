/* C Program to Implement Queue  using Linked List */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int val;
    struct node *next;
};

// Function to create a new node

struct node *createnode(int v)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = v;
    temp->next = NULL;
    return temp;
}

// Function to insert in a queue

struct node *insertqueue(struct node *rear, int v)
{
    struct node *temp = createnode(v);
    if (rear == NULL)
        rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
    return rear;
}

// Function to delete from a queue
// please note we have taken front pointer as double pointer because
// when we delete element the front will move to next node and
// the change should be reflected to calling program also

int deletequeue(struct node **front)
{
    struct node *temp;
    int val;
    if (*front == NULL)
    {
        printf("\nQueue is empty ...");
        exit(0);
    }
    else
    {
        val = (*front)->val;
        // printf("%s", val);
        temp = *front;
        *front = (*front)->next;
        free(temp);
        return val;
    }
}

/* Display if queue is empty or not */
int emptyqueue(struct node *front, struct node *rear)
{
    if ((front == NULL) && (rear == NULL))
        return 1;
    else
        return 0;
}

// Note: the rear and front pointers should be created in main program

void main()
{
    struct node *rear, *front;
    int val;
    rear = front = NULL;
    if (rear == NULL)
    {
        rear = insertqueue(rear, 10);
        front = rear; // Initailly the front will be same as rear
    }

    rear = insertqueue(rear, 30);
    rear = insertqueue(rear, 20);
    rear = insertqueue(rear, 70);

    while (!emptyqueue(front, rear))
    {
        val = deletequeue(&front); // please note address of front so double pointer at receiving end
        printf("%4d", val);
    }
    printf("\n");
    val = deletequeue(&front); // at this point queue is empty so
}