#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    
    int *beg = nums;
    int *end = nums + numsSize;

    int *iter = NULL;
    int count = 0;
    while (beg < end){
        iter = beg + 1;
        printf("Iterate: %d\n", *iter);
        printf("beg: %d\n", *beg);
        if (*iter == *beg){
            beg++;
            continue;
        }
        if ((iter < end) && (*iter != *beg)) {
            printf("wtf");
            count++;
            *beg = *iter;
        }
        beg++;
    }
    return count;
}

int main()
{
    // int a[] = {-1,1,1,2,2,2,3,3,4,4,4,4,4};
    int b[] = {2,3,3,3,4,5,6,7};
    int count = removeDuplicates(b, 8);
    printf("count = %d\n", count);
    
}