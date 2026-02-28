int concatenatedBinary(int n) {
    long long ans = 0;
    int MOD = 1000000007;
    int len = 0;

    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0) {
            len++;
        }

        ans = ((ans << len) + i) % MOD;
    }
    
    return ans;
}