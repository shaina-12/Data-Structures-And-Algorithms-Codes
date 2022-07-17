class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<=len;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
                return i;
            }
        }
        return -1;
    }
};
