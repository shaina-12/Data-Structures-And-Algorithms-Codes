#include <iostream>
#include <vector>
using namespace std;
bool howSum(int targetSum, vector<int> numbers, vector<int> &result){
    result.clear();
    if(targetSum==0){
        return true;
    }
    if(targetSum<0){
        return false;
    }
    for(int i=0;i<numbers.size();i++){
        int remainder = targetSum - numbers[i];
        bool recursion_result = howSum(remainder, numbers, result);
        if(recursion_result){
            result.push_back(numbers[i]);
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> result;
    howSum(7,{2,3},result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    result.clear();
    howSum(7,{5,3,4,7},result); //true
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    result.clear();
    howSum(7,{2,4},result); //false
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    result.clear();
    howSum(8,{2,3,5},result); //true
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    result.clear();
    howSum(300,{7,14},result); //false
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    result.clear();
    return 0;
}
