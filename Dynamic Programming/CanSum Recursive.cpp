#include <iostream>
#include <vector>
using namespace std;
bool canSum(int targetSum, vector<int> numbers){
    if(targetSum==0){
        return true;
    }
    if(targetSum<0){
        return false;
    }
    for(int i=0;i<numbers.size();i++){
        int remainder = targetSum - numbers[i];
        if(canSum(remainder,numbers)==true){
            return true;
        }
    }
    return false;
}
int main(){
    cout<<canSum(7,{2,3})<<endl; //true
    cout<<canSum(7,{5,3,4,7})<<endl; //true
    cout<<canSum(7,{2,4})<<endl; //false
    cout<<canSum(8,{2,3,5})<<endl; //true
    cout<<canSum(300,{7,14})<<endl; //false
    return 0;
}
