class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int k = 0;
        set <int> val;
        for(int i=0;i<nums.size();i++){
            val.insert(nums[i]);
        }
        for(auto i=val.begin();i!=val.end();i++){
            nums[k]=*i;
            k++;
        }
        return k;
    }
};
