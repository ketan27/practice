#include <stdio.h>

int isSubString(char *str1, char *str2)
{
    int i = 0, j = 0, found = 1;

    while (str1[j] && str2[i]) {
        if (str2[i] == str1[j]) {
            found = 1;
            i++;
        } else {
            found = 0;
            i = 0;
        }
        j++;
    }

    if (found)
        return 1;
    else
        return 0;
}

int main()
{
    int ret = isSubString("ketan", "keba");

    printf("%d\n", ret);

    return 0;
}
