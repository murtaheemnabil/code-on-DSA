#include <stdio.h>
int binarySearch(int a[], int l, int r, int x)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (a[mid] == x)
        return mid;
    else if (x < a[mid])
        return binarySearch(a, l, mid - 1, x);
    else
        return binarySearch(a, mid + 1, r, x);
}
int main()
{
    int a[100], n, x, i, pos;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &x);
    pos = binarySearch(a, 0, n - 1, x);
    if (pos == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", pos + 1);
    return 0;
}
