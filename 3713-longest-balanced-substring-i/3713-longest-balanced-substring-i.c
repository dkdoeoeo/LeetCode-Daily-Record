

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestBalanced(char* s) {
    int n = strlen(s);
    int maxLen = 0;

    // 外層迴圈：枚舉起點
    for (int i = 0; i < n; i++) {
        
        int freq[26] = {0}; // 頻率表
        int maxFreq = 0;    // 當前視窗內某個字母出現最多次的次數
        int distinct = 0;   // 當前視窗內有幾種不同的字母

        // 內層迴圈：枚舉終點
        for (int j = i; j < n; j++) {
            int idx = s[j] - 'a';
            
            // 如果這個字母第一次出現，distinct + 1
            if (freq[idx] == 0) {
                distinct++;
            }
            
            freq[idx]++;
            // 更新最高頻率
            maxFreq = MAX(maxFreq, freq[idx]);
            
            // 數學檢驗：
            // 如果 (最高頻率 * 不同字母數) == 當前總長度
            // 代表所有出現過的字母，頻率都剛好等於 maxFreq
            int currentLen = j - i + 1;
            if (maxFreq * distinct == currentLen) {
                maxLen = MAX(maxLen, currentLen);
            }
        }
    }
    
    return maxLen;
}