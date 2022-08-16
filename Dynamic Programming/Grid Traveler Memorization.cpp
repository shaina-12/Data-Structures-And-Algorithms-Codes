#include <iostream>
#include <string>
#include <map>
using namespace std;
long long int gridTraveler(int m, int n, map<string,long long int> &memo){
    string key = to_string(m)+","+to_string(n);
    if(memo.find(key)!=memo.end()){
        cout<<"done"<<endl;
        return memo[key];
    }
    if(m==1 && n==1){
        return 1;
    }
    if(m==0 || n==0){
        return 0;
    }
    memo[key] = gridTraveler(m-1,n,memo) + gridTraveler(m,n-1,memo);
    return memo[key];
}
int main(){
    map<string,long long int> memo;
    cout<<gridTraveler(1,1,memo)<<endl;
    memo.clear();
    cout<<gridTraveler(2,3,memo)<<endl;
    memo.clear();
    cout<<gridTraveler(3,2,memo)<<endl;
    memo.clear();
    cout<<gridTraveler(3,3,memo)<<endl;
    memo.clear();
    cout<<gridTraveler(18,18,memo)<<endl;
    memo.clear();
    return 0;
}