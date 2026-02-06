int cmp(const void* a, const void* b) {
    if (*(int*)a < *(int*)b) return -1;
    return 1;
}

int minRemoval(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int max_keep = 0;
    int left = 0;

    for (int right = 0; right < numsSize; right++) {
        while ((long long)nums[right] > (long long)nums[left] * k) {
            left++;
        }

        int current_len = right - left + 1;
        if (current_len > max_keep) {
            max_keep = current_len;
        }
    }

    return numsSize - max_keep;
}