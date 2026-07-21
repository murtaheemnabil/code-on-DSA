#include <stdio.h>
#define MAX 100
int heap[MAX];
int size = 0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int value)
{
    heap[size] = value;
    int index = size;
    size++;
    while (index > 0 && heap[(index - 1) / 2] > heap[index])
    {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
void display()
{
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}
int main()
{
    int values[] = {10, 3, 2, 4, 5, 1};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
    {
        insert(values[i]);
        printf("Inserted %d into the min-heap: ", values[i]);
        display();
    }
    return 0;
}
