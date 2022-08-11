#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool canConstruct(string target, vector<string> wordBank){
    if(target==""){
        return true;
    }
    for(int i=0;i<wordBank.size();i++){
        if(target.find(wordBank[i],0)==0){
            string suffix = target.substr(wordBank[i].length());
            if(canConstruct(suffix,wordBank)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    cout<<canConstruct("abcdef",{"ab","abc","cd","def","abcd"})<<endl; //true
    cout<<canConstruct("skateboard",{"bo","rd","ate","t","ska","sk","boar"})<<endl; //false
    cout<<canConstruct("enterapotentpot",{"a","p","ent","enter","ot","o","t"})<<endl; //true
    cout<<canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",{"e","ee","eee",
    "eeee","eeeee","eeeeee"})<<endl; //false
    return 0;
}