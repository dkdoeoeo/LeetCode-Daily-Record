int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int zeros[200] = {0}; 
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == 0) {
                count++;
            } else {
                break;
            }
        }
        zeros[i] = count;
    }
    
    int swaps = 0;
    
    for (int i = 0; i < n; i++) {
        int target = n - 1 - i;
        int j = i;

        while (j < n && zeros[j] < target) {
            j++;
        }

        if (j == n) return -1;

        swaps += (j - i);

        int temp = zeros[j];
        for (int k = j; k > i; k--) {
            zeros[k] = zeros[k - 1];
        }
        zeros[i] = temp;
    }
    
    return swaps;
}