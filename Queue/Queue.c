#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void enqueue(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted.\n", value);
}
void dequeue()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    temp = front;
    printf("%d removed.\n", front->data);
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
}
void display()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    temp = front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
