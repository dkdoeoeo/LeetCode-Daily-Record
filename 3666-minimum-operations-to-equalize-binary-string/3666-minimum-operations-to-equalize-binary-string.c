
int minOperations(char* s, int k) {
    int n = strlen(s);
    int z = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') z++;
    }
    int o = n - z;
    
    if (z == 0) return 0;
    
    if (k % 2 == 0 && z % 2 != 0) return -1;
    
    if (n == k) {
        return (z == n) ? 1 : -1;
    }
    
    for (int i = 1; i <= n + 5; i++) {
        long long total_flips = (long long)i * k;
        
        if (total_flips < z) continue;
        
        if ((total_flips - z) % 2 != 0) continue;

        long long max_odd = (i % 2 != 0) ? i : i - 1;
        long long max_even = (i % 2 != 0) ? i - 1 : i;
        
        long long max_capacity = (long long)z * max_odd + (long long)o * max_even;
        
        if (total_flips <= max_capacity) {
            return i;
        }
    }
    
    return -1;
}