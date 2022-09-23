/{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        /*
        sort(arr,arr+n);
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(0-arr[i]);
        }*/
        /*
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }*/
        //cout<<endl;
        /*
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                int sum = arr[i]+arr[j];
                //cout<<sum<<" ";
                if(find(v.begin(),v.end(),sum)!=v.end()){
                    return true;
                }
            }
        }
        return false;*/
        sort(arr,arr+n);
        for(int i=0;i<n-2;i++){
            int sum=0-arr[i];
            int l=i+1;
            int h=n-1;
            while(l<h){
                if(arr[l]+arr[h]==sum){
                    return true;
                }
                else if(arr[l]+arr[h]>sum){
                    h--;
                }
                else{
                    l++;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends
