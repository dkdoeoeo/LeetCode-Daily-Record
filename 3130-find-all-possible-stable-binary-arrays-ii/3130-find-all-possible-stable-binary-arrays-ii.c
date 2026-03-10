#include <stdlib.h>

int numberOfStableArrays(int zero, int one, int limit) {
    int MOD = 1000000007;
    
    // 向 Heap 要一塊記憶體，並自動初始化為 0 (calloc 的好處)
    // 陣列大小為 1005 x 1005 x 2
    int (*dp)[1005][2] = calloc(1005, sizeof(*dp));
    
    // 1. 初始化 Base Cases
    for (int i = 1; i <= zero && i <= limit; i++) {
        dp[i][0][0] = 1;
    }
    for (int j = 1; j <= one && j <= limit; j++) {
        dp[0][j][1] = 1;
    }

    // 2. 開始填表 (完全沿用昨天的 $O(1)$ 狀態轉移)
    for (int i = 1; i <= zero; i++) {
        for (int j = 1; j <= one; j++) {
            
            // --- 計算以 0 結尾 ---
            long long sum0 = (long long)dp[i-1][j][0] + dp[i-1][j][1];
            if (i > limit) {
                // 扣掉違法組合
                sum0 = sum0 - dp[i - limit - 1][j][1] + MOD;
            }
            dp[i][j][0] = sum0 % MOD;

            // --- 計算以 1 結尾 ---
            long long sum1 = (long long)dp[i][j-1][0] + dp[i][j-1][1];
            if (j > limit) {
                sum1 = sum1 - dp[i][j - limit - 1][0] + MOD;
            }
            dp[i][j][1] = sum1 % MOD;
        }
    }


    int ans = ((long long)dp[zero][one][0] + dp[zero][one][1]) % MOD;

    free(dp);
    
    return ans;
}