class Solution {
public:
    int reverse(int x) {
        long long int d = 0;
        long long int a = abs(x);
        while(a>0){
            d = d*10 + (a%10);
            a = a/10;
        }
        if(x<0)
            d = -d;
        if(d>=INT_MIN && d<=INT_MAX)
            return d;
        else
            return 0;
    }
};
