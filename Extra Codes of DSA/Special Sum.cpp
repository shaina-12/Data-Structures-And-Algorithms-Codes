#include <algorithm>
/*int firstSum(vector<int> &arr,int ind){
    int sum=0;
    for(int i=0;i<=ind;i++){
        sum+=arr[i];
    }
    return sum;
}
int lastSum(vector<int> &arr,int ind){
    int sum=0;
    for(int i=ind;i<=arr.size()-1;i++){
        sum+=arr[i];
    }
    return sum;
}*/
int specialSum(vector<int> &arr, int n)
{
	// Write your code here. 
    vector<int> v;
    int fs=0;
    int ls=0;
    for(int i=0;i<arr.size();i++){
        fs += arr[i];
        ls += arr[n-i-1];
        v.push_back(fs+ls);
    }
    return *min_element(v.begin(),v.end());
}
