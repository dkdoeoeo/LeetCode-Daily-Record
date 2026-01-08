#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 輔助函式：求最大值
long long max(long long a, long long b) {
    return a > b ? a : b;
}

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // 1. 動態配置二維 DP 陣列
    // 因為這題可能會有負負得正累積出很大的數，雖然題目說是int範圍，
    // 但為了保險運算過程，有些變體可能需要 long long，不過這題 int 其實夠用。
    // 這裡我們直接用 int 即可，因為題目 output 也是 int。
    
    int** dp = (int**)malloc(nums1Size * sizeof(int*));
    for (int i = 0; i < nums1Size; i++) {
        dp[i] = (int*)malloc(nums2Size * sizeof(int));
    }

    // 2. 開始填表
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            // 計算當前這一對的乘積
            int product = nums1[i] * nums2[j];
            
            // 情況 A: 只取當前這一對 (作為新的子序列起點)
            dp[i][j] = product;

            // 情況 B: 接續前面的子序列 (左上角 dp[i-1][j-1])
            if (i > 0 && j > 0) {
                // 取 max 是為了決定：是要「加上前面的」比較大，還是「只取現在這個」比較大
                // 例如前面累積是 -100，現在是 5，那當然只取 5 (相當於拋棄前面的)
                // 但如果前面累積是 100，現在是 5，那就變成 105
                dp[i][j] = max(dp[i][j], product + dp[i-1][j-1]);
            }

            // 情況 C: 不用 nums1[i] (繼承「上方」 dp[i-1][j])
            if (i > 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }

            // 情況 D: 不用 nums2[j] (繼承「左方」 dp[i][j-1])
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }

    // 3. 答案就在右下角
    int result = dp[nums1Size - 1][nums2Size - 1];

    // 釋放記憶體
    for (int i = 0; i < nums1Size; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}