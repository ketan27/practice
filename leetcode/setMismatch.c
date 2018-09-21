/*
 * The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of
 * one number and loss of another number.
 *
 * Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the 
 * form of an array.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    int intMap[10000];
    memset((void*)intMap, -1, 10000);
    int i;

    for (i = 0; i < numsSize; ++i) {
        printf("%d\t", intMap[i]);
    }

    return returnSize;
}

int main()
{
    int arr[] = {1,2,3,4};
    int size;

    findErrorNums(arr, 4, &size);

    return 0;
}
