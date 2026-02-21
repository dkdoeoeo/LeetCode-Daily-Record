int count1(int a){
    int b = 0;
    for(int i = 0; i < 32; i++){
        if(a&1){
            b++;
        }
        a = a >> 1;
    }
    return b;
}
int countPrimeSetBits(int left, int right) {
    int ans = 0,b;
    for(int i = left; i <= right; i++){
        b=count1(i);
        if(b==2||b==3||b==5||b==7||b==11||b==13||b==17||b==19||b==23||b==29){
            ans++;
        }
    }
    return ans;
}