class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0,pro = 1,temp,t = n;
        while(n != 0){
            temp = n % 10;
            n = n / 10;
            sum += temp;
            pro *= temp;
        }
        return (t % (sum+pro) == 0);
    }
};