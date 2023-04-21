#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int hash_val = 0;
	    for(int i=0;i<s.length();i++){
	        hash_val += int(s.at(i))-97;
	    }
	    cout<<hash_val<<" ";
	}
	return 0;
}
