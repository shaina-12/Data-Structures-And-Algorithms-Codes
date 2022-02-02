# include <iostream>
# include <stack>
# include <string>
using namespace std;
bool checkParenthesis(string pths){
    stack <char> s;
    for(int i=0;i<pths.size();i++){
        if(pths[i]=='(' || pths[i]=='[' || pths[i]=='{'){
            s.push(pths[i]);
        }
        else{
            char a = s.top();
            if(a=='(' && (pths[i]==']' || pths[i]=='}')){
                return false;
            }
            if(a=='[' && (pths[i]==')' || pths[i]=='}')){
                return false;
            }
            if(a=='{' && (pths[i]==')' || pths[i]==']')){
                return false;
            }
            s.pop();
        }
    }
    if(s.size()!=0){
        return false;
    }
    return true;
}
int main(){
    string pths;
    cin>>pths;
    bool check = checkParenthesis(pths);
    if(check){
        cout<<"Correct!!!";
    }
    else{
        cout<<"Wrong!!!";
    }
}
