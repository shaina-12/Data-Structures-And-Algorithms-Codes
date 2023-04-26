class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        if(i==m){
            while(j<n){
                v.push_back(nums2[j]);
                j++;
            }
        }
        else{
            while(i<m){
                v.push_back(nums1[i]);
                i++;
            }
        }
        nums1.clear();
        for(int k=0;k<v.size();k++){
            nums1.push_back(v[k]);
        }
    }
};


/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        if(n==0){
            return;
        }
        if(m==0){
            for(int i=0;i<n;i++){
                nums1[i]=nums2[i];
            }
            return;
        }
        int j=0,k=0;
        while(j<m && k<n){
            if(nums1[j]<nums2[k]){
                v.push_back(nums1[j]);
                j++;
            }
            else{
                v.push_back(nums2[k]);
                k++;
            }
        }
        if(j==m){
            while(k<n){
                v.push_back(nums2[k]);
                k++;
            }
        }
        else{
            while(j<m){
                v.push_back(nums1[j]);
                j++;
            }
        }
        for(int i=0;i<m+n;i++){
            nums1[i]=v[i];
        }
    }
};
*/
