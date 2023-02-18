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

// Another Approach
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1||n==k){ // to deal with the case when (1) n=1 and n>=k (2) n=k
            return;
        }
        reverse(nums.begin(),nums.begin()+n);
        reverse(nums.begin(),nums.begin()+(k%n)); // k%n is done to deal with the condition when n>k. 
        reverse(nums.begin()+(k%n),nums.end()); // Test case: Input: nums=[1,2] k=3 Correct Output: [2,1]
    }
};
*/
