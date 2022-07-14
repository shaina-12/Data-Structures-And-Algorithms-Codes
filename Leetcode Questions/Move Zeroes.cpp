class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nz;
        vector<int> z;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                z.push_back(nums[i]);
            }
            else{
                nz.push_back(nums[i]);
            }
        }
        int l=0;
        for(int i=0;i<nz.size();i++){
            nums[l]=nz[i];
            l++;
        }
        for(int i=0;i<z.size();i++){
            nums[l]=z[i];
            l++;
        }
    }
};
