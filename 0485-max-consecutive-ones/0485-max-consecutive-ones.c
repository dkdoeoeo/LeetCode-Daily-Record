int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int ans = 0,c=0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i]==1){
            c++;
        }
        else{
            if(c>ans){
                ans=c;
            }
            c=0;
        }
    }
    if(c>ans){
        ans=c;
    }
    return ans;
}