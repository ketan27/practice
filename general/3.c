#include <stdio.h>

char A[3];

void Binary(int n)
{
    if (n < 1) {
        printf("%s\n", A);
    } else {
#ifdef dbg
        printf("Setting %d to 0\n", (n-1));
#endif
        A[n-1] = '0';
        Binary(n-1);
#ifdef dbg
        printf("Setting %d to 1\n", (n-1));
#endif
        A[n-1] = '1';
        Binary(n-1);
    }
}

int main()
{
    Binary(3);

    return 0;
}
