class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int target_count = k - 1; 
        long long current_sum = 0;
        
        multiset<int> L, R; 
        
        for (int i = 1; i <= dist + 1 && i < n; i++) {
            L.insert(nums[i]);
            current_sum += nums[i];
        }
        
        while (L.size() > target_count) {
            int max_val = *L.rbegin();
            current_sum -= max_val;
            L.erase(prev(L.end()));
            R.insert(max_val);
        }
        
        long long min_cost = current_sum;
        
        for (int i = dist + 2; i < n; i++) {
            int out = nums[i - (dist + 1)];
            int in = nums[i];
            
            auto it_L = L.find(out);
            if (it_L != L.end()) {
                current_sum -= out;
                L.erase(it_L);
            } else {
                auto it_R = R.find(out);
                if (it_R != R.end()) R.erase(it_R);
            }
            
            while (L.size() < target_count && !R.empty()) {
                int min_R = *R.begin();
                current_sum += min_R;
                R.erase(R.begin());
                L.insert(min_R);
            }
            
            if (L.size() < target_count) {
                L.insert(in);
                current_sum += in;
            } else {
                int max_L = *L.rbegin();
                if (in < max_L) {
                    current_sum -= max_L;
                    L.erase(prev(L.end()));
                    L.insert(in);
                    current_sum += in;
                    R.insert(max_L);
                } else {
                    R.insert(in);
                }
            }

            if (L.size() == target_count) {
                min_cost = min(min_cost, current_sum);
            }
        }
        
        return (long long)nums[0] + min_cost;
    }
};