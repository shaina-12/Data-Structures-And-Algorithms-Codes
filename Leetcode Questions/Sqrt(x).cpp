class Solution {
public:
    int mySqrt(int x) {
        
        //int result = sqrt(x);
        //return result;
        int next = 1;
        int ctr=0;
        int a=x;
        while(a>=next){
            a=a-next;
            ctr++;
            next+=2;
        }
        return ctr;
    }
};
