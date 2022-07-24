class Solution {
public:
    double myPow(double x, int n) {
         if(n == 0)
            return 1;
        if(n == INT_MIN){
            return myPow(x*x, n/2);
        }
        if(n < 0){
            x = 1/x;
            n = -n;
        }
        if(n%2 == 1) 
            return myPow(x*x, n/2)*x;
        else
            return myPow(x*x, n/2);
        //return pow(x,n);
    }
};
