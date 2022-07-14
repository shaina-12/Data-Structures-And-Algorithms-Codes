class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ele = nums[0];
        for(int i=1;i<nums.size();i++){
            if(ele==nums[i]){
                return true;
            }
            ele=nums[i];
        }
        return false;
    }
};
