// Queue implementation using linked list in C
//  Basic operations: enqueue, dequeue, peek, display
// Queue follows FIFO(first in first out) principle

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    float data;
    struct node *next;
} node;

void enqueue(node **front, node **rear, float data)
{ // Adding element at the end

    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    if (*front == NULL && *rear == NULL)
    {
        *front = newnode;
        *rear = newnode;
        return;
    }
    (*rear)->next = newnode;
    *rear = newnode;

    return;
}

void dequeue(node **front, node **rear)
{ // Removing element from the front
    if (*front == NULL && *rear == NULL)
    {
        printf("Queue underflow\n");
        return;
    }
    node *temp = *front;
    printf("Dequeued element is : %.2f\n", temp->data);
    *front = (*front)->next;
    free(temp);

    return;
}

void peek(node *front)
{ // Getting the front element;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front elememtis %.2f :", front->data);
    return;
}

void display(node *front)
{ // Displaying the queue
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    node *temp = front;
    printf("Queue elements are : ");
    while (temp != NULL)
    {
        printf("%.2f  ", temp->data);
        temp = temp->next;
    }
    return;
}

int main()
{

    node *front = NULL;
    node *rear = NULL;
    int choice;
    float data;
    do
    {
        printf("\n----------MENU---------------\n");
        printf("\n1.Enqueue the element");
        printf("\n2.Dequeue the element");
        printf("\n3.Peek element");
        printf("\n4.Display Queue");
        printf("\n5.Exit the program\n");
        printf("\nEnter the choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data :");
            scanf("%f", &data);
            enqueue(&front, &rear, data);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            peek(front);
            break;
        case 4:
            display(front);
            break;
        case 5:
            printf("Exit the program \n");

            break;
        default:
            printf("Invalid choice");

            break;
        }

    } while (choice != 5);

    return 0;
}
