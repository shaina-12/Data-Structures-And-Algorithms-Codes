#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool howSum(int targetSum, vector<int> numbers, vector<int> &result, map<int,bool> &memo){
    result.clear();
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
        if(howSum(remainder,numbers,result,memo)==1){
            result.push_back(numbers[i]);
            memo[targetSum] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
}
int main(){
    vector<int> result;
    map<int,bool> memo;
    howSum(7,{2,3},result,memo);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    result.clear();
    memo.clear();
    howSum(7,{5,3,4,7},result,memo); //true
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    result.clear();
    memo.clear();
    howSum(7,{2,4},result,memo); //false
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    result.clear();
    memo.clear();
    howSum(8,{2,3,5},result,memo); //true
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    result.clear();
    memo.clear();
    howSum(300,{7,14},result,memo); //false
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    result.clear();
    memo.clear();
    return 0;
}
