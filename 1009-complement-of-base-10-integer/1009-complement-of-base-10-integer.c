int bitwiseComplement(int n) {
    int ans = 0;
    if(n==0){
        return 1;
    }
    for(int i = 0 ;n>0;i++){
        if(n%2==0){
            ans=ans+(1*pow(2,i));
        }
        n=n/2;
    }

    return ans;
}