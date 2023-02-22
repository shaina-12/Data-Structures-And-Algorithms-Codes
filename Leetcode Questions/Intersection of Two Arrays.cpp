class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        if(nums1.size()<nums2.size()){
            for(int i=0;i<nums1.size();i++){
                if(find(nums2.begin(),nums2.end(),nums1[i])!=nums2.end()){
                    s.insert(nums1[i]);
                }
            }
        }
        else{
            for(int i=0;i<nums2.size();i++){
                if(find(nums1.begin(),nums1.end(),nums2[i])!=nums1.end()){
                    s.insert(nums2[i]);
                }
            }
        }
        vector<int> result;
        for(auto i: s){
            result.push_back(i);
        }
        return result;
    }
};
