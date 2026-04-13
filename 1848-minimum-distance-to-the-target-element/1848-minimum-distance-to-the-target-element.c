int getMinDistance(int* nums, int numsSize, int target, int start) {
    int ans = 10000,temp = 0;
    
    for(int i = start;i < numsSize;i++){
        if(nums[i] == target){
            ans = temp;
            break;
        }
        temp++;
    }
    temp = 0;
    for(int i = start;i >= 0;i--){
        if(nums[i] == target){
            if(temp < ans){
                ans = temp;
            }
            break;
        }
        temp++;
    }
    return ans;
}