#include <stdio.h>
#include <string.h>
int main()
{
    char mainString[] = "Sylhet Engineering College";
    char substring[] = "Engineering";

    int i, j, k;
    int mainLen = strlen(mainString);
    int subLen = strlen(substring);
    int found = 0;
    for (i = 0; i <= mainLen - subLen; i++)
    {
        for (j = 0; j < subLen; j++)
        {
            if (mainString[i + j] != substring[j])
            {
                break;
            }
        }
        if (j == subLen)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        printf("Substring is present.\n");
        printf("Extracted substring: %s\n", substring);
        for (k = i; k <= mainLen - subLen; k++)
        {
            mainString[k] = mainString[k + subLen];
        }
        if (mainString[i] == ' ')
        {
            for (k = i; mainString[k] != '\0'; k++)
            {
                mainString[k] = mainString[k + 1];
            }
        }

        printf("After extraction: %s\n", mainString);
    }
    else
    {
        printf("Substring not present.\n");
    }
    return 0;
}
