class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int odd = 0, even = 0;
            unordered_set<int> seen;

            for (int j = i; j < n; j++) {
                if (seen.find(nums[j]) == seen.end()) {
                    seen.insert(nums[j]);
                    if (nums[j] % 2 != 0) odd++;
                    else even++;
                }

                if (odd == even) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};