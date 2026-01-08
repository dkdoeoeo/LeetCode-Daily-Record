
int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int** DP = (int**)malloc(nums1Size*sizeof(int*));
    for(int i = 0; i < nums1Size;i++){
        DP[i] = (int*)malloc(nums2Size*sizeof(int));
    }

    for(int i = 0; i < nums1Size;i++){
        for(int j = 0; j < nums2Size;j++){
            DP[i][j] = nums1[i] * nums2[j];

            if(i > 0 && j > 0){
                if(DP[i-1][j-1] > 0){
                    DP[i][j] = DP[i][j] + DP[i-1][j-1];
                }
            }

            if (i > 0) {
                if(DP[i-1][j] > DP[i][j]){
                    DP[i][j] = DP[i-1][j];
                }
            }

            if (j > 0) {
                if(DP[i][j-1] > DP[i][j]){
                    DP[i][j] = DP[i][j-1];
                }
            }
        }
    }
    
    return DP[nums1Size - 1][nums2Size - 1];
}