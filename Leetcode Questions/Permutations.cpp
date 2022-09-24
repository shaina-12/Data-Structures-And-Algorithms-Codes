class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ref;
        for(int i=0;i<nums.size();i++){
            ref.push_back(nums[i]);
        }
        sort(ref.begin(),ref.end());
        do{
            ans.push_back(ref);
        }while(next_permutation(ref.begin(),ref.end()));
        return ans;
    }
};
