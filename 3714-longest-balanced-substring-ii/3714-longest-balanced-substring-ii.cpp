
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        // --- Case 1: 只有 1 種字母 (尋找最長連續字元) ---
        // 這是最簡單的，直接掃一遍
        int currentLen = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i-1]) currentLen++;
            else currentLen = 1;
            maxLen = max(maxLen, currentLen);
        }

        // --- Case 2: 只有 2 種字母 (ab, ac, bc) ---
        // 技巧：使用 "History" 記錄修改過的位置，避免 memset 的 O(N) 開銷
        vector<int> pos(2 * n + 1, -2); // -2 代表沒看過
        vector<int> history; // 記錄這一輪改了哪些位置，方便快速回滾

        auto solveTwo = [&](char c1, char c2, char forbidden) {
            // 初始化狀態
            // 為了不 memset 整個 pos 陣列，我們只清空 "上一輪碰過的地方"
            for (int idx : history) pos[idx] = -2;
            history.clear();
            
            pos[0 + n] = -1; // 初始狀態 diff=0 在 index -1
            history.push_back(0 + n);

            int diff = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == forbidden) {
                    // 遇到牆壁，不需要 memset，只要把 history 裡的位置復原即可
                    for (int idx : history) pos[idx] = -2;
                    history.clear();
                    
                    // 重置起點
                    diff = 0;
                    pos[0 + n] = i; 
                    history.push_back(0 + n);
                } else {
                    if (s[i] == c1) diff++;
                    else if (s[i] == c2) diff--;
                    
                    int key = diff + n;
                    if (pos[key] != -2) {
                        maxLen = max(maxLen, i - pos[key]);
                    } else {
                        pos[key] = i;
                        history.push_back(key);
                    }
                }
            }
        };

        solveTwo('a', 'b', 'c');
        solveTwo('a', 'c', 'b');
        solveTwo('b', 'c', 'a');

        // --- Case 3: 包含 3 種字母 (abc) ---
        // 條件：count(a) == count(b) == count(c)
        // 這裡沒有 forbidden char，所以不需要 reset 機制，直接用 unordered_map
        unordered_map<long long, int> mp;
        long long initialKey = (0LL + n) << 32 | (0LL + n); // 壓縮 Key
        mp[initialKey] = -1;
        
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else if (s[i] == 'c') c++;
            
            // 我們關注的是相對差值
            int diff1 = a - b; // 範圍 -N ~ N
            int diff2 = b - c; // 範圍 -N ~ N
            
            // 將兩個 int 壓縮成一個 long long 當作 Key，比 pair 快
            long long key = ((long long)(diff1 + n) << 32) | (long long)(diff2 + n);
            
            if (mp.find(key) != mp.end()) {
                maxLen = max(maxLen, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return maxLen;
    }
};