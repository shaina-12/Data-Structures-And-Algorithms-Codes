class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {   
        int n=digits.size();
        int i=n-2,carry;
        int ans = digits[n-1]+1;
        if(ans>9){
            carry=1;
        }
        else{
            carry=0;
        }
        digits[n-1] = ans%10;
        while(i>=0){
            int ans = digits[i]+carry;
            if(ans>9){
                carry=1;
            }
            else{
                carry=0;
            }
            digits[i]=ans%10;
            i--;
        }
        if(carry==1){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};
