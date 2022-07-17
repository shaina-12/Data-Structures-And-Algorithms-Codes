class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        uint32_t a = n;
        while(a>0){
            if(a%2==1){
                ans++;
            }
            a = a/2;
        }
        return ans;
    }
};
