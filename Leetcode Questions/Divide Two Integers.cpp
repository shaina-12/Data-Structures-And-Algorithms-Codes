class Solution {
public:
    int divide(int dividend, int divisor) {
       if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
       int sign = 1;
       if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
           sign=-1;
       }
       long dive = labs(dividend);
       long divi = labs(divisor);
       long ctr=0;
       while(dive>=divi){
           long temp = divi;
           long m = 1;
           while (temp << 1 <= dive) {
                temp <<= 1;
                m <<= 1;
            }
           dive -= temp;
           ctr+= m;
       }
       return sign*ctr;
    }
};
        /*
        int sign = 1;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
            sign=-1;
        }
        return sign*(dividend>>divisor);*/
