class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1 || n==k){
            return;
        }
        if(n>(k%n)){
            reverse(nums.begin(),nums.begin() + n);
            reverse(nums.begin(),nums.begin()+ (k%n));
            reverse(nums.begin() + (k%n), nums.begin() + n);
        }
        
    }
};
