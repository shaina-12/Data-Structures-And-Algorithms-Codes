class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        long next=n;
        while(next){
            v.push_back(next%10);
            next/=10;
        }
        reverse(v.begin(), v.end());
        next_permutation(v.begin(), v.end());
        next=0;
        for(auto a:v) next=(next*10)+a;
        if(next<=n or next>INT_MAX) return -1;
        return next;
    }
};
