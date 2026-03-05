#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minOperations(char * s) {
    int count = 0;
    int n = strlen(s);
    
    for (int i = 0; i < n; i++) {
        if (s[i] - '0' != i % 2) {
            count++;
        }
    }
    return MIN(count, n - count);
}