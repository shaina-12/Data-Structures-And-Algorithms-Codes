//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    int ctrp=0,ctrn=0;
	    for(int i=0;i<n;i++){
            if(arr[i]>=0){
                ctrp++;
            }
            else{
                ctrn++;
            }
        }
        int *positive = new int[ctrp];
        int *negative = new int[ctrn];
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                positive[j]=arr[i];
                j++;
            }
            else{
                negative[k]=arr[i];
                k++;
            }
        }
        j=0;
        k=0;
        int l=0;
        while(j<ctrp && k<ctrn){
            if(l%2==0){
                arr[l]=positive[j];
                j++;
                l++;
            }
            else{
                arr[l]=negative[k];
                k++;
                l++;
            }
        }
        if(j==ctrp){
            while(k<ctrn){
                arr[l]=negative[k];
                k++;
                l++;
            }
        }
        else{
            while(j<ctrp){
                arr[l]=positive[j];
                j++;
                l++;
            }
        }
        delete [] positive;
        delete [] negative;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
