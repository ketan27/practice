#include <stdio.h>
#include <stdlib.h>

char A[100];

void k_string(int n, int k)
{
    if (n < 1) {
        printf("%s\n", A);

    } else {
        int i;

        for (i = 0; i < k; ++i) {

            A[n-1] = i;
            k_string(n-1, k);

        }
    }
}

int main()
{
    int n, k;

    n = 5;
    k = 3;

    k_string(n, k);

    return 0;
}
