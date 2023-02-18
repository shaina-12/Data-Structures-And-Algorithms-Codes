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

// Another Approach
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> hmap;
        for(int i=0;i<nums.size();i++){
            if(hmap.find(nums[i])==hmap.end()){
                hmap[nums[i]]=i;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
*/
