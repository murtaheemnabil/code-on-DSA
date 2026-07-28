#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
int main() {
    char str[MAX_SIZE];
    int freq[256] = {0};
    int i;

    printf("Enter a word or string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    printf("\nCharacter Frequencies:\n");
    for (i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] != 0) {
            printf("'%c' : %d\n", str[i], freq[(unsigned char)str[i]]);
            freq[(unsigned char)str[i]] = 0;
        }
    }
    return 0;
}
