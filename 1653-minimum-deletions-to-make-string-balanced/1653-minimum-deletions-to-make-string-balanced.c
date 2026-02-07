#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumDeletions(char * s) {
    int count_b = 0;
    int ans = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'b') {
            count_b++;
        } else {
            ans = MIN(ans + 1, count_b);
        }
    }
    
    return ans;
}