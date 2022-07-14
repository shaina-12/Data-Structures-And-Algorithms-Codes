class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int element = nums[0];
        for(int i=1;i<nums.size();i++){
            element ^= nums[i];
        }
        return element;
    }
};
