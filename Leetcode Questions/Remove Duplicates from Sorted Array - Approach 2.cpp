class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        //sort(nums.begin(),nums.end());
        int element = nums[0];
        int i=1, ind=1;
        int ctr=0;
        while(i<n){
            if(element==nums[i]){
                ctr++;
            }
            else{
                element = nums[i];
                int tmp = nums[ind];
                nums[ind] = nums[i];
                nums[i] = tmp;
                ind++;
            }
            i++;
        }
        for(int j=0;j<ctr;j++){
            nums.pop_back();
        }
        return nums.size();
    }
};
