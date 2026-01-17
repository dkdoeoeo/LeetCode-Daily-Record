int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}
int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}
long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {
    long long ans = 0;
    for(int i = 0 ;i < bottomLeftSize -1; i++){
        for(int j = i+1; j < bottomLeftSize;j++){
            int a_i = max(bottomLeft[i][0],bottomLeft[j][0]),b_i = max(bottomLeft[i][1],bottomLeft[j][1]);
            int c_i = min(topRight[i][0],topRight[j][0]),d_i = min(topRight[i][1],topRight[j][1]);
            if(a_i >= c_i || b_i >= d_i){
                continue;
            }

            int width = min(c_i-a_i,d_i-b_i);
            long long temp = (long long)width*width;
            if(temp > ans){
                ans = temp;
            }
        }
    }
    return ans;
}