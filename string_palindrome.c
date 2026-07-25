#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int left = 0;
    int right;
    int isPalindrome = 1;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {

        str[strcspn(str, "\n")] = '\0';

        right = strlen(str) - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                isPalindrome = 0;
                break;
            }
            left++;
            right--;
        }

        if (isPalindrome == 1) {
            printf("\"%s\" is a palindrome.\n", str);
        } else {
            printf("\"%s\" is NOT a palindrome.\n", str);
        }
    }

    return 0;
}
