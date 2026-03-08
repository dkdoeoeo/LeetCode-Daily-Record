char* findDifferentBinaryString(char** nums, int numsSize) {
    char* ans = (char*)malloc(sizeof(char)*(numsSize+1));
    for(int i = 0; i < numsSize;i++){
        if(nums[i][i]=='1'){
            ans[i] = '0';
        }
        else{
            ans[i] = '1';
        }
    }
    ans[numsSize]='\0';
    return ans;
}