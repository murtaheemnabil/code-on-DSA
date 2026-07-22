#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insert(int value)
{
    int i = size;

    heap[i] = value;
    size++;

    while (i != 0 && heap[(i - 1) / 2] < heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}
void deleteMax()
{
    if (size == 0)
    {
        printf("Heap is empty!\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i)
        {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;

            i = largest;
        }
        else
            break;
    }
}

void display()
{
    if (size == 0)
    {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Max Heap Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete Max\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            deleteMax();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

