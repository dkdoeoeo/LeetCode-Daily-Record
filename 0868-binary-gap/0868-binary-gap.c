int binaryGap(int n) {
    int cur = -1,ans=0;
    while(n){
        if(n%2==1){
            cur++;
            if(cur > ans){
                ans = cur;
            }
            cur = 0;
        }
        else if(cur == -1){
            
        }
        else{
            cur++;
        }
        n=n/2;
    }
    return ans;
}