/ { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> A, int N){
        // code here
        vector<int> V;
        for(int i=0;i<N-2;i++){
            int a = A[i];
            int b = A[i+1];
            int c = A[i+2];
            if(((a+b)>c) && ((a+c)>b) && ((b+c)>a)){
                V.push_back(1);
            }
            else{
                V.push_back(0);
            }
        }
        return V;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends
