class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = nums[0], cur_index = 0, len = nums.size(), k = 1, temp;
        for(int i = 1; i < len; i++){
            if(cur != nums[i]){
                cur = nums[i];
                k++;
                cur_index++;
                temp = nums[i];
                nums[i] = nums[cur_index];
                nums[cur_index] = temp;
            }
        }
        return k;
    }
};