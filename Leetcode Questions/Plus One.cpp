class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            ans.push_back(0);
        }
        for(int i=digits.size()-1;i>=0;i--){
            int num=digits[i] + carry;
            if(num>=10){
                ans[i] = num-10;
                carry = 1;
            }
            else{
                ans[i] = num;
                carry=0;
            }
        }
        if(carry==1){
            ans.insert(ans.begin(),carry);
        }
        return ans;
    }
};
