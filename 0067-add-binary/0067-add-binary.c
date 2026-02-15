size_t len(char* a){
    size_t count = 0;
    while(*a != '\0'){
        count += 1;
        a++;
    }
    return count;
}

char* reverse_binary(char* a){
    size_t index = len(a);

    for(size_t i = 0; i < index/2; i++){
        int temp = a[i];
        a[i] = a[index-i-1];
        a[index-i-1] = temp;
    }
    return a;
}

char* addBinary(char* a, char* b) {
    a = reverse_binary(a);
    b = reverse_binary(b);
    if(len(a) < len(b)){
        char* temp = a;
        a=b;
        b=temp;
    }
    char* ans = (char*)malloc((len(a)+1+1)*sizeof(char));
    int add = 0,index = 0;
    while(index < len(b)){
        add = add + a[index] + b[index] - '0' - '0';
        if(add == 0){
            ans[index] = '0';
        }
        else if(add == 1){
            ans[index] = '1';
            add = 0;
        }
        else if(add == 2){
            ans[index] = '0';
            add = 1;
        }else{
            ans[index] = '1';
            add = 1;
        }
        index++;
    }
    while(index < len(a)){
        add = add + a[index] - '0';
        if(add == 0){
            ans[index] = '0';
        }
        else if(add == 1){
            ans[index] = '1';
            add = 0;
        }
        else if(add == 2){
            ans[index] = '0';
            add = 1;
        }else{
            ans[index] = '1';
            add = 1;
        }
        index++;
    }
    if(add == 1){
        ans[index] = '1';
        index++;
    }
    ans[index]='\0';
    return reverse_binary(ans);
}