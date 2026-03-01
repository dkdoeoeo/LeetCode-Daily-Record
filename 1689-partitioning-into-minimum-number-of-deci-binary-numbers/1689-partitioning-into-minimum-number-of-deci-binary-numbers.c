int minPartitions(char* n) {
    int ans = 0;
    for(int i = 0; i < strlen(n);i++){
        if(n[i] - '0' > ans){
            ans = n[i] - '0';
        }
    }
    return ans;
}