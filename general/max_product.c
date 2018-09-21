#include <stdio.h>
#include <stdlib.h>

/*
 * Returns 0 for failure or invalid inputs
 */
int maxProduct(int ar[], int size)
{
    int maxNeg = 0, maxPos = 0, anyPositive = 0;
    int max[8] = {0};
    /*
     * Store elements in this way: - are lowest -ve numbers and + are largest +ve numbers
     * _________________
     * |-|-|+|+|+|-|-|-|
     * -----------------
     */
    int i, maxProduct = 0;

    if (size > 2) {
        for(i = 0; i < size; i++) {
            // Find largest +ve numbers
            if (ar[i] > max[4]) {
                max[2] = max[3];
                max[3] = max[4];
                max[4] = ar[i];
            } else if (ar[i] > max[3]) {
                max[2] = max[3];
                max[3] = ar[i];
            } else if (ar[i] > max[2]) {
                max[2] = ar[i];
            }

            // Find biggest -ve numbers
            if (ar[i] < max[0]) {
                max[1] = max[0];
                max[0] = ar[i];
            } else if (ar[i] < max[1]) {
                max[1] = ar[i];
            }

            // Also keep track of smallest 3 -ve numbers, in case if all numbers are negative
            if (ar[i] < 0 && ar[i] > max[7]) {
                max[5] = max[6];
                max[6] = max[7];
                max[7] = ar[i];
            } else if (ar[i] < max[6]) {
                max[5] = max[6];
                max[6] = ar[i];
            } else if (ar[i] < max[5]) {
                max[5] = ar[i];
            }

            if (!anyPositive && ar[i] > 0)
                anyPositive = 1;
        }

        if (max[0] == 0 && max[1] == 0) {
            // if we have not found atleast 2 -ve numbers, so only +ve nos
            maxProduct = max[4] * max[3] * max[2];
        } else if (!anyPositive) {
            maxProduct = max[7] * max[6] * max[5];
        } else {
            // now we might have either -ve * -ve * +ve
            maxNeg = max[0] * max[1] * max[4];
            maxPos = max[4] * max[3] * max[2];
            maxProduct = maxPos > maxNeg ? maxPos : maxNeg;
        }
    }

    return maxProduct;
}

int main()
{
    int arr[7] = {-10,-4,-54,-86,-45,-9,-3};

    printf("Max product is %d\n", maxProduct(arr, 7));

    return 0;
}
