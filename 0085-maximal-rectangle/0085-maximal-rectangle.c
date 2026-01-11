int findMax(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int countRowSum(int* ansMatrix, int lens){
    int* tempMatrix = (int*)malloc(sizeof(int) * 200),temp,tempMax = 0;
    for(int i = 0; i < 200; i++){
        tempMatrix[i] = 0;
    }

    int sum = 0;
    for(int i = 0; i < lens;i++){
        if(ansMatrix[i] != 0){
            if(tempMax < ansMatrix[i]){
                tempMax = ansMatrix[i];
            }

            for(int j = ansMatrix[i]; j < tempMax; j++){
                temp = tempMatrix[j]*(j+1);
                if(temp > sum){
                    sum = temp;
                }
                tempMatrix[j] = 0;
            }

            for(int j = ansMatrix[i]-1; j > -1; j--){
                tempMatrix[j]++;
            }
        }

        if(ansMatrix[i] == 0){
            for(int i = 0; i < tempMax; i++){
                temp = tempMatrix[i]*(i+1);
                if(temp > sum){
                    sum = temp;
                }
                tempMatrix[i] = 0;
            }
            tempMax = 0;
        }
    }
    for(int i = 0; i < tempMax; i++){
        temp = tempMatrix[i]*(i+1);
        if(temp > sum){
            sum = temp;
        }
        tempMatrix[i] = 0;
    }
    tempMax = 0;
    free(tempMatrix);
    return sum;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int** rowCount = (int**)malloc(sizeof(int*)*matrixSize);
    int* ansMatrix = (int*)malloc(sizeof(int)*matrixSize);
    int tempMax = 0,ans = 0;
    for(int i = 0; i < matrixSize;i++){
        rowCount[i] = (int*)malloc(sizeof(int)*(*matrixColSize));
        ansMatrix[i] = 0; 
    }

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < *matrixColSize; j++){
            if(matrix[i][j]=='0'){
                rowCount[i][j]=0;
            }
            else if(i > 0){
                rowCount[i][j] = rowCount[i-1][j] + 1;
            }
            else{
                rowCount[i][j] = 1;
            }
        }
    }

    for(int j = 0; j < *matrixColSize; j++){
        for(int i = 0; i < matrixSize; i++){
            if(rowCount[i][j]==0){
                ansMatrix[i]=0;
            }
            else{
                if(rowCount[i][j] > tempMax){
                    tempMax = rowCount[i][j];
                }
                ansMatrix[i] += 1;
            }
        }
        ans = findMax(findMax(countRowSum(ansMatrix,matrixSize),tempMax),ans);
        tempMax = 0;
    }
    return ans;
}