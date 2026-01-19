int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int** PF = (int **) malloc(matSize*sizeof(int*));
    for(int i = 0; i < matSize;i++) PF[i] = (int*)malloc(sizeof(int)*(*matColSize));

    for(int i = 0; i < matSize;i++){
        for(int j = 0; j < * matColSize;j++){
            if(i>0 && j>0){
                PF[i][j] = mat[i][j] + PF[i-1][j] + PF[i][j-1] - PF[i-1][j-1];
            }
            else if(i == 0 && j > 0){
                PF[i][j] = mat[i][j] + PF[i][j-1];
            }
            else if(j == 0 && i > 0){
                PF[i][j] = mat[i][j] + PF[i-1][j];
            }
            else{
                PF[i][j] = mat[i][j];
            }
        }
    }

    int ans = max(matSize,* matColSize);
    for(int size = ans;size>0;size--){
        for(int i = 0; i <= matSize - size;i++){
            for(int j = 0; j <= * matColSize - size;j++){
                int temp = 1e5;
                if(i>0 && j>0){
                    temp = PF[i-1][j-1] + PF[i+size - 1][j+size-1] - PF[i - 1][j+size-1] - PF[i+size - 1][j-1];
                }
                else if(j==0 && i > 0){
                    temp = PF[i+size-1][j+size-1] - PF[i-1][j+size-1];
                }
                else if(i == 0 && j > 0){
                    temp = PF[i+size-1][j+size-1] - PF[i+size-1][j-1];
                }
                else{
                    temp = PF[i+size - 1][j+size-1];
                }

                if(threshold >= temp){
                    return size;
                }
            }
        }
    }
    return 0;
}