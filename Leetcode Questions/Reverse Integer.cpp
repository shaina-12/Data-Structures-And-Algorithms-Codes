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

// Another Apporach
/*
#include <cmath>
class Solution {
public:
    int reverse(int x) {
        int sign = 0;
        long long int max = pow(2,31)-1, min = -1*pow(2,31);
        long long int val;
        // 0 is for positive and 1 is for negative (Following 2's Complement Form)
        if(x<0){
            sign = 1;
            val  = abs(x);
        }
        else{
            val = x;
        }
        //cout<<val<<" "<<sign<<endl;
        long long int r = 0;
        while(val>0){
            r = (r*10) + (val%10);
            val = val/10;
        }
        if(r>max || r<min){
            return 0;
        }
        if(sign==1){
            r = -1*r;
        }
        return r;
    }
};
*/
