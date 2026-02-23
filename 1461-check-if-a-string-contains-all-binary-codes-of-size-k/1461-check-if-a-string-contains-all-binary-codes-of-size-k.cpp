class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false;
        
        unordered_set<string> seen;
        int target_count = 1 << k;
        
        for (int i = 0; i <= s.length() - k; i++) {
            seen.insert(s.substr(i, k));
            
            if (seen.size() == target_count) {
                return true;
            }
        }
        
        return false;
    }
};