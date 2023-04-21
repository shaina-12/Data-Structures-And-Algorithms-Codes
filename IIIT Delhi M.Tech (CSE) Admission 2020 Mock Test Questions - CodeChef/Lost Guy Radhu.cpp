/* The Problem Statement is Given in this Link: https://www.codechef.com/IIITDS20/problems/MAY19F1?tab=statement */
/* Solution */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n, Q;
	    cin>>n>>Q;
	    vector <int> a; 
	    vector <int> q;
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        a.push_back(x);
	    }
	    for(int i=0;i<Q;i++){
	        int x;
	        cin>>x;
	        q.push_back(x);
	    }
	    for(int i=0;i<Q;i++){
	        cout<<*max_element(a.begin(), a.begin()+q[i])<<endl;
	    }
	}
	return 0;
}
