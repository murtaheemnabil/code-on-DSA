#include <stdio.h>
int isSubstring(const char mainStr[], const char subStr[]) {
    int i, j;

    for (i = 0; mainStr[i] != '\0'; i++) {

        for (j = 0; subStr[j] != '\0'; j++) {
            if (mainStr[i + j] != subStr[j]) {
                break;
            }
        }

        if (subStr[j] == '\0') {
            return i;
        }
    }

    return -1;
}

int main() {
    char mainStr[100], subStr[100];
    printf("Enter the main string: ");
    fgets(mainStr, sizeof(mainStr), stdin);

    printf("Enter the substring to search: ");
    fgets(subStr, sizeof(subStr), stdin);

    for (int k = 0; mainStr[k] != '\0'; k++) {
        if (mainStr[k] == '\n') mainStr[k] = '\0';
    }
    for (int k = 0; subStr[k] != '\0'; k++) {
        if (subStr[k] == '\n') subStr[k] = '\0';
    }

    int result = isSubstring(mainStr, subStr);

    if (result != -1) {
        printf("Success: '%s' found at index %d.\n", subStr, result);
    } else {
        printf("Not found: '%s' is not a substring.\n", subStr);
    }
    return 0;
}
