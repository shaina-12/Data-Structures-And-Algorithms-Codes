class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxPow = (int)(pow(3,(int)(log(INT_MAX)/log(3))));
        return (n > 0 && maxPow % n == 0);
    }
};
