int min(int a, int b){
    if(a>b)
    return b;
    return a;
}
int countBinarySubstrings(char* s) {
    int ans = 0,cur = 0,curSym = '-1',count0=0,count1=0;
    while(s[cur] != '\0'){
        if(s[cur] != curSym){
            if(s[cur]=='1'){
                ans += min(count0,count1);
                count1 = 1;
                curSym = '1';
            }
            else{
                ans += min(count0,count1);
                count0 = 1;
                curSym = '0';
            }
        }
        else{
            if(s[cur]=='1'){
                count1++;
            }
            else{
                count0++;
            }
        }
        cur++;
    }
    ans+=min(count1,count0);
    return ans;
}