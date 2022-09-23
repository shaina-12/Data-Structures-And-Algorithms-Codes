class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        vector<int> ref;
        for(int i=0;i<nums.size();i++){
            ref.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            int j=(i+1)%ref.size();
            int ele = -1;
            while(j!=i){
                if(nums[i]<ref[j]){
                    ele = ref[j];
                    break;
                }
                j = (j+1)%ref.size();
            }
            ans.push_back(ele);
        }
        return ans;
    }
};
