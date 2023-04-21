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
# cook your dish here
import itertools as it


def bounds(arr):
    val = True
    for i in range(len(arr)):
        if(arr[i]<=0 or arr[i]>=25):
            return False
    return True

t = int(input())
while(t>0):
    s = input()
    ls = len(s)
    hash_val = 0
    for i in s:
        hash_val+=ord(i)-97
    li = list(it.permutations(range(hash_val),ls))
    l1 = []
    for i in range(len(li)):
        if(sum(li[i])==hash_val and bounds(li[i])==True):
            st = ""
            for j in range(ls):
                st += chr(li[i][j]+97)
            if(st<=s):
                l1.append(st)
    l1.sort()
    print(str(hash_val)+" "+l1[0])
    t = t-1

