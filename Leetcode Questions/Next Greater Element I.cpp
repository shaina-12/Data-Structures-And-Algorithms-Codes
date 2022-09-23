class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int ind = find(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            if(ind==nums2.size()-1){
                ans.push_back(-1);
            }
            else{
                int ele = -1;
                for(int j=ind+1;j<nums2.size();j++){
                    if(nums1[i]<nums2[j]){
                        ele = nums2[j];
                        break;
                    }
                }
                ans.push_back(ele);
            }
        }
        return ans;
    }
};
