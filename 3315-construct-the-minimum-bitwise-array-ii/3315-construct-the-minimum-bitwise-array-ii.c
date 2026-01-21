/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize*sizeof(int));
    for(int i = 0 ; i < numsSize;i++){
        if(nums[i] % 2 == 1){
            ans[i] = ~((~nums[i] & (nums[i]+1)) >> 1) & nums[i];
        }
        else{
            ans[i] = -1;
        }
    }
    * returnSize = numsSize;
    return ans;
}