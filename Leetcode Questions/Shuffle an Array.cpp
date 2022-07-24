class Solution {
    vector<int> num;
public:
    Solution(vector<int>& nums) {
        this->num=nums;
    }
    
    vector<int> reset() {
        return num;
    }
    
    vector<int> shuffle() {
        vector<int> ans;
        for(int i=0;i<num.size();i++){
            ans.push_back(num[i]);
        }
        random_shuffle(ans.begin(),ans.end());
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
