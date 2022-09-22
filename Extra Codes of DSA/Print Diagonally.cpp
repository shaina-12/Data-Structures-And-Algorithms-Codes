//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> ans;
		/*
		for(int k=0;k<(n*2);k++){
		    for(int i=0;i<n;i++){
		        for(int j=0;j<n;j++){
		            if((i+j)==k){
		                ans.push_back(A[i][j]);
		            }
		        }
		    }
		}*/
		for(int i=0;i<n;i++){
		    for(int j=0;j<=i;j++){
		        ans.push_back(A[j][i-j]);
		    }
		}
		for(int i=1;i<=n-1;i++){
		    for(int j=0;j<n-i;j++){
		        ans.push_back(A[i+j][n-1-j]);
		    }
		}
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
