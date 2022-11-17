// //QUEUE USING LINEAR LINKED LIST
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// struct queue
// {
//     struct queue *next;
//     int val;
// };

// struct queue *creat_queue(int n)
// {
//     struct queue *t = (struct queue *)malloc(sizeof(struct queue));
//     t->val = n;
//     t->next = NULL;
//     return t;
// }

// int is_empty(struct queue *front)
// {
//     if (front == NULL)
//         return 1;
//     else
//         return 0;
// }

// struct queue *insert_queue(struct queue *rear, int n)
// {
//     struct queue *t = creat_queue(n);
//     if (rear == NULL)
//         rear = t;
//     else
//     {
//         rear->next = t;
//         rear = t;
//     }
//     return rear;
// }

// int delete_queue(struct queue **front)
// {
//     int n;
//     struct queue *t;
//     t = *front;
//     n = (*front)->val;
//     *front = (*front)->next;
//     free(t);
//     return n;
// }

// void display(struct queue *front)
// {
//     if (is_empty(front))
//         printf("Queue is empty\n");
//     else
//     {
//         struct queue *f = front;
//         printf("Elements of queue are: ");
//         while (f != NULL)
//         {
//             printf("%d ", f->val);
//             f = f->next;
//         }
//         printf("\n");
//     }
// }

// void main()
// {
//     struct queue *front = NULL, *rear = NULL;
//     int choice, n, del;
//     while (1)
//     {
//         printf("***MENU***\n");
//         printf("Choose a option\n");
//         printf("1-Insert element\n");
//         printf("2-Delete element\n");
//         printf("3-Check if queue is empty\n");
//         printf("4-Display queue\n");
//         printf("5-Exit\n");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             printf("Enter a element\n");
//             scanf("%d", &n);
//             if (rear == NULL)
//             {
//                 rear = creat_queue(n);
//                 front = rear;
//             }
//             else
//                 rear = insert_queue(rear, n);
//             break;

//         case 2:
//             if (is_empty(front))
//                 printf("Queue is empty\n");
//             else
//             {
//                 del = delete_queue(&front);
//                 printf("Deleted element is %d\n", del);
//             }
//             break;

//         case 3:
//             if (is_empty(front))
//                 printf("Queue is empty\n");
//             else
//                 printf("Queue is not empty\n");
//             break;

//         case 4:
//             display(front);
//             break;

//         case 5:
//             exit(0);
//         }
//     }
// }

//QUEUE USING CIRCULAR ARRAY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
struct queue
{
    int a[SIZE];
    int front, rear;
};

int is_full(struct queue *q)
{
    if ((q->rear + 1) % SIZE == q->front)
        return 1;
    else
        return 0;
}

int is_empty(struct queue *q)
{
    if (q->rear == q->front)
        return 1;
    else
        return 0;
}

void insert_queue(struct queue *q, int n)
{
    if (is_full(q))
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        q->a[(++q->rear) % SIZE] = n;
    }
}

int delete_queue(struct queue *q)
{
    return q->a[(++q->front) % SIZE];
}

void display(struct queue *q)
{
    if (is_empty(q))
        printf("Queue is empty\n");
    else
    {
        int r = (q->front + 1) % SIZE;
        printf("Elements are: ");
        while (r != (q->rear + 1) % SIZE)
        {
            printf("%d ", q->a[r]);
            r++;
        }
        printf("\n");
    }
}

void main()
{
    struct queue q;
    q.front = SIZE - 1;
    q.rear = SIZE - 1;
    int choice, n, del;
    while (1)
    {
        printf("***MENU***\n");
        printf("Choose a option\n");
        printf("1-Insert element\n");
        printf("2-Delete element\n");
        printf("3-Check if queue is empty\n");
        printf("4-Check if queue is full\n");
        printf("5-Display queue\n");
        printf("6-Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a element\n");
            scanf("%d", &n);
            insert_queue(&q, n);
            break;

        case 2:
            if (is_empty(&q))
                printf("Queue is empty\n");
            else
            {
                del = delete_queue(&q);
                printf("Deleted element is %d\n", del);
            }
            break;

        case 3:
            if (is_empty(&q))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;

        case 4:
            if (is_full(&q))
                printf("Queue is full\n");
            else
                printf("Queue is not full\n");
            break;

        case 5:
            display(&q);
            break;

        case 6:
            exit(0);
        }
    }
}

