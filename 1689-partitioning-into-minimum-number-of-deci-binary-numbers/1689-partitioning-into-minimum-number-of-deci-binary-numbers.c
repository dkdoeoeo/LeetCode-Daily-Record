int minPartitions(char* n) {
    int ans = 0;
    for(int i = 0; n[i] != '\0';i++){
        int current_digit = n[i] - '0';
        
        if (current_digit > ans) {
            ans = current_digit;

            if (ans == 9) {
                return 9;
            }
        }
    }
    return ans;
}