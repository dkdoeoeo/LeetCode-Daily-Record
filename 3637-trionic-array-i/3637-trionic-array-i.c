bool isTrionic(int* nums, int numsSize) {
    int flag = 0,next;
    for(int i = 0; i < numsSize - 1;i++){
        if(nums[i] < nums[i+1]){
            if(flag%2==0){
                flag++;
            }
        }
        else if(nums[i] > nums[i+1]){
            if(flag%2==1){
                flag++;
            }
            if(i==0){
                return false;
            }
        }
        else{
            return false;
        }
    }
    return flag==3;
}