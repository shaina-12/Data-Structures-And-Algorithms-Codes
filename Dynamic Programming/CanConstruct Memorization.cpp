#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
bool canConstruct(string target, vector<string> wordBank, map<string,bool> &memo){
    if(memo.find(target) != memo.end()){
        return memo[target];
    }
    if(target==""){
        return true;
    }
    for(int i=0;i<wordBank.size();i++){
        if(target.find(wordBank[i],0)==0){
            string suffix = target.substr(wordBank[i].length());
            if(canConstruct(suffix,wordBank,memo)){
                memo[target] = true;
                return true;
            }
        }
    }
    memo[target] = false;
    return false;
}
int main(){
    map<string,bool> memo;
    cout<<canConstruct("abcdef",{"ab","abc","cd","def","abcd"},memo)<<endl; //true
    memo.clear();
    cout<<canConstruct("skateboard",{"bo","rd","ate","t","ska","sk","boar"},memo)<<endl; //false
    memo.clear();
    cout<<canConstruct("enterapotentpot",{"a","p","ent","enter","ot","o","t"},memo)<<endl; //true
    memo.clear();
    cout<<canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",{"e","ee","eee",
    "eeee","eeeee","eeeeee"},memo)<<endl; //false
    memo.clear();
    return 0;
}