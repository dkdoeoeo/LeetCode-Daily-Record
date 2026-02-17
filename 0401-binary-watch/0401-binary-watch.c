/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count1(int a){
    int count = 0;
    while(a != 0){
        a = a & (a-1);
        count++;
    }
    return count;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** ans = (char**)malloc(720*sizeof(char*));
    int index = 0;

    for(int h = 0; h <= 11; h++){
        for(int m = 0; m <= 59; m++){
            if(count1(h) + count1(m) == turnedOn){
                ans[index] = (char*)malloc(6*sizeof(char));
                snprintf(ans[index],sizeof(ans[index]),"%d:%02d",h,m);
                index++;
            }
        }
    }
    *returnSize = index;
    return ans;
}