bool isSorted(int* nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (nums[i] > nums[i+1]) return false;
    }
    return true;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int ans = 0;
    while (!isSorted(nums, numsSize)) {
        int minSum = 2000000000;
        int bestIndex = -1;
        for (int i = 0; i < numsSize - 1; i++) {
            int currentSum = nums[i] + nums[i+1];
            
            if (currentSum < minSum) {
                minSum = currentSum;
                bestIndex = i;
            }
        }
        
        if (bestIndex != -1) {
            nums[bestIndex] = minSum;
            
            for (int k = bestIndex + 1; k < numsSize - 1; k++) {
                nums[k] = nums[k+1];
            }
            
            numsSize--;
            ans++;
        }
    }
    
    return ans;
}