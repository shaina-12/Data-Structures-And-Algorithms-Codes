class Solution {
public:
    int reverse(int x) {
        long int y = 0;
        int sign = 1;
        if(x==INT_MIN){
            return 0;
        }
        int z = x;
        if(x<0){
            sign=-1; 
            z=z*(-1);
        }
        while(z>0){
            y = (y*10) + (z%10);
            z = z/10;
        }
        if(y>INT_MAX){
            return 0;
        }
        return sign*(int)y;
    }
};
