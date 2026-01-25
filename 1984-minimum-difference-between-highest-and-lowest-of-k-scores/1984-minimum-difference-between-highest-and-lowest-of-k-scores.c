int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimumDifference(int* nums, int numsSize, int k) {
    if (k == 1) return 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    int minDiff = 2147483647;

    for (int i = 0; i <= numsSize - k; i++) {
        int currentDiff = nums[i + k - 1] - nums[i];
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
        }
    }

    return minDiff;
}