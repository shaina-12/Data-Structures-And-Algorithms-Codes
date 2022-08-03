#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;
bool canSum(int targetSum, vector<int> numbers, map<int,bool> &memo){
    if(memo.find(targetSum) != memo.end()){
        return memo[targetSum];
    }
    if(targetSum==0){
        return true;
    }
    if(targetSum<0){
        return false;
    }
    for(int i=0;i<numbers.size();i++){
        int remainder = targetSum - numbers[i];
        if(canSum(remainder,numbers,memo)==1){
            memo[targetSum] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
}
int main(){
    map<int,bool> memo;
    cout<<canSum(7,{2,3},memo)<<endl; //true
    memo.clear();
    cout<<canSum(7,{5,3,4,7},memo)<<endl; //true
    memo.clear();
    cout<<canSum(7,{2,4},memo)<<endl; //false
    memo.clear();
    cout<<canSum(8,{2,3,5},memo)<<endl; //true
    memo.clear();
    cout<<canSum(300,{7,14},memo)<<endl; //false
    memo.clear();
    return 0;
}
