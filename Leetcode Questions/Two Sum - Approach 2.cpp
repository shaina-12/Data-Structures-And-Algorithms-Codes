class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num;
        for(int i=0;i<nums.size();i++){
            num.push_back(target-nums[i]);
        }
        vector<int> ans;
        int i;
        for(i=0;i<nums.size();i++){
            if(find(num.begin(),num.end(),nums[i])!=num.end()){
                int ind = find(num.begin(),num.end(),nums[i])-num.begin();
                if(ind!=i){
                    ans.push_back(i);
                    ans.push_back(ind);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
