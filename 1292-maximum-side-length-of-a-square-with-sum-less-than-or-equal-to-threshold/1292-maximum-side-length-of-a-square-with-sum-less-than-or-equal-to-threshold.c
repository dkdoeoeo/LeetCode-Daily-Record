
int min(int a, int b) {
    return a < b ? a : b;
}

int getRectSum(int** sum, int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
}

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize;
    int n = *matColSize;
    
    int** p = (int**)malloc(sizeof(int*) * (m + 1));
    for(int i = 0; i <= m; i++) {
        p[i] = (int*)calloc(n + 1, sizeof(int));
    }
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            p[i][j] = mat[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
    
    int ans = 0;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            int currentLen = ans + 1;
            
            if (i >= currentLen && j >= currentLen) {
                int r1 = i - currentLen + 1;
                int c1 = j - currentLen + 1;
                int total = getRectSum(p, r1, c1, i, j);

                if (total <= threshold) {
                    ans++;
                }
            }
        }
    }
    
    return ans;
}