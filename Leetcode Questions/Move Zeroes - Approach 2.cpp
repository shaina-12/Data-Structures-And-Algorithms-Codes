class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nz=0, z=1;
        while(nz<n && z<n){
            if(nums[z]==0){
                if(nums[nz]!=0){
                    nz++;
                }
                z++;
            }
            else{
                if(nums[nz]==0){
                    int temp=nums[nz];
                    nums[nz]=nums[z];
                    nums[z]=temp;
                }
                z++;
                nz++;
            }
        }
    }
};
