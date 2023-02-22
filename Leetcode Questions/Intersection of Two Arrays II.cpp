class Solution {
public: 
    /*
    int find(vector<int> a, int b){
        int si=0,ei=a.size()-1, mid;
        while(si<=ei){
            mid=(si+ei)/2;
            if(b==a[mid]){
                return mid;
            }
            else if(b<a[mid]){
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        return -1;
    }*/
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //sort(nums1.begin(),nums1.end());
        //sort(nums2.begin(),nums2.end());
        set<pair<int,int>> ctr;
        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            if(find(nums2.begin(),nums2.end(),nums1[i])!=nums2.end()){
                int m=count(nums1.begin(),nums1.end(),nums1[i]);
                int n=count(nums2.begin(),nums2.end(),nums1[i]);
                pair<int,int> p;
                if(m<n){
                    p.first=nums1[i];
                    p.second=m;
                }
                else{
                    p.first=nums1[i];
                    p.second=n;
                }
                ctr.insert(p);
            }
        }
        for(auto i: ctr){
            for(int j=0;j<i.second;j++){
                result.push_back(i.first);
            }
        }
        return result;
    }
};
