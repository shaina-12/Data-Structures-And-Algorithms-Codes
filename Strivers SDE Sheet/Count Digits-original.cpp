class Solution{
public:
    vector<int> getDigits(int N){
        int a=N;
        vector<int> nums;
        while(a>0){
            nums.push_back(a%10);
            a = a/10;
        }
        return nums;
    }
    int evenlyDivides(int N){
        //code here
        vector<int> digits = getDigits(N);
        int count=0;
        for(int i=0;i<digits.size();i++){
            if(digits[i]!=0){
                if(N % digits[i] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};
