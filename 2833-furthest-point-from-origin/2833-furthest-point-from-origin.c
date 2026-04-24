int furthestDistanceFromOrigin(char* moves) {
    int ans = 0,a=0;
    for(int i = 0; i < strlen(moves);i++){
        if(moves[i]=='L'){
            ans--;
        }
        else if(moves[i]=='R'){
            ans++;
        }
        else{
            a++;
        }
    }
    if(ans < 0){
        return -1*(ans-a);
    }
    return ans+a;
}