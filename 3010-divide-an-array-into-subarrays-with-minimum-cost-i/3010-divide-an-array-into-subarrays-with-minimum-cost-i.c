int minimumCost(int* nums, int numsSize) {
    int min1 = 100,min2 = 100;
    for(int i = 1; i < numsSize;i++){
        if(nums[i] < min1){
            if(nums[i]  < min2){
                min1 = min2;
                min2 = nums[i];
            }
            else{
                min1 = nums[i];
            }
        }
    }
    return min1+min2+nums[0];
}