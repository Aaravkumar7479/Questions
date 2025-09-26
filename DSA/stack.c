// Stack implementation using linked list
// Stack follows LIFO (Last In First Out) principle
// Basic operations: push, pop, peek, display

#include <stdio.h>
#include <stdlib.h>

typedef struct node //data type is node
{
    float data;
    struct node *next;
} node;

void push(node **top, float data)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = data;
    newnode->next = *top; // in stack newnode contain the address of previous node
    *top = newnode;

    return;
}

void pop(node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow ");
        return;
    }
    node *temp = *top; // Take help of temp for remove the popped node.
    printf("Popped data is : %.2f", temp->data);
    *top = (*top)->next;
    free(temp); // clean garbage
    return;
}
void peek(node *top)
{

    if (top == NULL)
    {
        printf("Stack is empty \n");
        return;
    }
    printf("Top value is %.2f :", top->data);
    return;
}

void display(node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty \n");
        return;
    }

    node *temp = top; // Take help of temp because it might be possible we want to print peek value in future .... therefore we don't disturb top pointer.
    while (temp != NULL)
    {

        printf("%.2f  ", temp->data);
        temp = temp->next;
    }
    return;
}

int main()
{

    node *top = NULL;
    int choice;
    float data;
    do
    {
        printf("\n----------MENU---------------\n");
        printf("\n1.Push the element");
        printf("\n2.Pop the element");
        printf("\n3.Peek element");
        printf("\n4.Display stack");
        printf("\n5.Exit the program\n");
        printf("\nEnter the choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data :");
            scanf("%f", &data);
            push(&top, data);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            display(top);
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
