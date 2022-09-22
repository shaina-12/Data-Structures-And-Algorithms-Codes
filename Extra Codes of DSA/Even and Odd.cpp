//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void reArrange(int arr[], int N) {
        // code here
        int ctre=0, ctro=0;
        for(int i=0;i<N;i++){
            if(arr[i]%2==0){
                ctre++;
            }
            else{
                ctro++;
            }
        }
        int *even = new int[ctre];
        int *odd = new int[ctro];
        int j=0,k=0;
        for(int i=0;i<N;i++){
            if(arr[i]%2==0){
                even[j]=arr[i];
                j++;
            }
            else{
                odd[k]=arr[i];
                k++;
            }
        }
        j=0;
        k=0;
        for(int i=0;i<N;i++){
            if(i%2==0){
                arr[i]=even[j];
                j++;
            }
            else{
                arr[i]=odd[k];
                k++;
            }
        }
        delete [] even;
        delete [] odd;
    }
};

//{ Driver Code Starts.

int check(int arr[], int n)
{
    int flag = 1;
    int c=0, d=0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            if(arr[i]%2)
            {
                flag = 0;
                break;
            }
            else
                c++;
        }
        else
        {
            if(arr[i]%2==0)
            {
                flag = 0;
                break;
            }
            else
                d++;
        }
    }
    if(c!=d)
        flag = 0;
        
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        ob.reArrange(arr,N);
        
        cout<<check(arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
