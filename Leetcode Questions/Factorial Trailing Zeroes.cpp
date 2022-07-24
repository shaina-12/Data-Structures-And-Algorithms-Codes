class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int a = n;
        int quotient = a/5;
        while(quotient>0){
            ans+=quotient;
            quotient = quotient/5;
        }
        return ans;
    }
};
