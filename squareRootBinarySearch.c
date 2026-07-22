#include <stdio.h>
int integerSqrt(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return n;

    long long low = 1, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == n) {
            return mid;
        }
        else if (square < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int number;
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    int result = integerSqrt(number);

    if (result == -1) {
        printf("Square root of negative numbers is not defined in real numbers.\n");
    } else {
        printf("Integer square root of %d is: %d\n", number, result);
    }

    return 0;
}

