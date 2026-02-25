/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    
    int bitCount1 = __builtin_popcount(num1);
    int bitCount2 = __builtin_popcount(num2);
    
    if (bitCount1 != bitCount2) {
        return bitCount1 - bitCount2;
    }
    
    return num1 - num2;
}
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    qsort(arr, arrSize, sizeof(int), compare);
    
    *returnSize = arrSize;
    return arr;
}