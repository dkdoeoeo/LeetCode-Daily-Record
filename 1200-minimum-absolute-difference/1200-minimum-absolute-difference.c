/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), cmp);

    int minDiff = 2e9;
    for (int i = 0; i < arrSize - 1; i++) {
        int diff = arr[i+1] - arr[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    
    int count = 0;
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i+1] - arr[i] == minDiff) {
            count++;
        }
    }
    
    *returnSize = count;
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    int** res = (int**)malloc(count * sizeof(int*));
    
    int idx = 0;
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i+1] - arr[i] == minDiff) {
            res[idx] = (int*)malloc(2 * sizeof(int));
            res[idx][0] = arr[i];
            res[idx][1] = arr[i+1];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }
    
    return res;
}