int ads(int a){
    if(a < 0){
        return -a;
    }
    return a;
}

int t(int x,int y){
    if(x > y){
        return x;
    }
    return y;
}
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int ans = 0,x,y;
    for(int i = 0; i < (pointsSize - 1);i++){
        x = ads(points[i][0] - points[i+1][0]);
        y = ads(points[i][1] - points[i+1][1]);
        ans += t(x,y);
    }
    return ans;
}