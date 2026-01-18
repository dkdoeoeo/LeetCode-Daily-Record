
int min(int a, int b) {
    return a < b ? a : b;
}

long long getRowSum(long long** rSum, int row, int c1, int c2) {
    return rSum[row][c2 + 1] - rSum[row][c1];
}

long long getColSum(long long** cSum, int col, int r1, int r2) {
    return cSum[r2 + 1][col] - cSum[r1][col];
}

int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;

    long long** rowSum = (long long**)malloc(m * sizeof(long long*));
    for (int i = 0; i < m; i++) {
        rowSum[i] = (long long*)malloc((n + 1) * sizeof(long long));
        rowSum[i][0] = 0;
        for (int j = 0; j < n; j++) {
            rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
        }
    }

    long long** colSum = (long long**)malloc((m + 1) * sizeof(long long*));
    for (int i = 0; i <= m; i++) {
        colSum[i] = (long long*)malloc(n * sizeof(long long));
    }

    for (int j = 0; j < n; j++) colSum[0][j] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            colSum[i + 1][j] = colSum[i][j] + grid[i][j];
        }
    }


    int maxPossibleK = min(m, n);
    for (int k = maxPossibleK; k >= 2; k--) {

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                long long target = getRowSum(rowSum, i, j, j + k - 1);
                bool possible = true;


                for (int r = 1; r < k; r++) {
                    if (getRowSum(rowSum, i + r, j, j + k - 1) != target) {
                        possible = false;
                        break;
                    }
                }
                if (!possible) continue;

                for (int c = 0; c < k; c++) {
                    if (getColSum(colSum, j + c, i, i + k - 1) != target) {
                        possible = false;
                        break;
                    }
                }
                if (!possible) continue;


                long long d1 = 0, d2 = 0;
                for (int d = 0; d < k; d++) {
                    d1 += grid[i + d][j + d];
                    d2 += grid[i + d][j + k - 1 - d];
                }

                if (d1 == target && d2 == target) {

                    for(int x=0; x<m; x++) free(rowSum[x]);
                    free(rowSum);
                    for(int x=0; x<=m; x++) free(colSum[x]);
                    free(colSum);
                    return k;
                }
            }
        }
    }

    for(int x=0; x<m; x++) free(rowSum[x]);
    free(rowSum);
    for(int x=0; x<=m; x++) free(colSum[x]);
    free(colSum);

    return 1;
}