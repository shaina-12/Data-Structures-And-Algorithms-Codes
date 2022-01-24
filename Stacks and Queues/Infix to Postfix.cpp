# include <iostream>
# include <stack>
# include <string>
using namespace std;
void infixToPostfix(string inExp,string &postExp){
    stack <char> s;
    for(int i=0;i<inExp.size();i++){
        if(inExp[i]=='('){
            s.push(inExp[i]);
        }
        else if(inExp[i]==')'){
            while(!s.empty() && s.top()!='('){
                postExp += s.top();
                s.pop();
            }
            s.pop();
        }
        else if(inExp[i]=='^'){
            if(s.empty()){
                s.push(inExp[i]);
            }
            else 
            {
                char a = s.top();
                if(a=='^'){
                    postExp += a;
                    s.pop();
                    while(!s.empty()){
                        char b = s.top();
                        if(b=='^'||b=='*'||b=='/'){
                            postExp += b;
                            s.pop();
                        }
                        else{
                            break;
                        }
                    }
                s.push(inExp[i]);
                }
                else{
                    s.push(inExp[i]);
                }
            }   
        }
        else if(inExp[i]=='*'){
            if(s.empty()){                    
                s.push(inExp[i]);
            }
            else{
                char a = s.top();
                if(a == '^'||a == '*'||a=='/'){
                while(!s.empty()){
                    char b = s.top();                    
                    if (b=='^'||b=='*'||b=='/'){
                        postExp += b;
                        s.pop();
                    }
                    else{
                        break;
                    }
                }
                s.push(inExp[i]);
                }     
                else{
                    s.push(inExp[i]);
                }
            }
        }
        else if(inExp[i] == '/'){
            if(s.empty()){
                s.push(inExp[i]);
            }
            else{
                char a = s.top();
                if(a=='^'||a=='*'||a=='/'){
                while(!s.empty()){
                    char b = s.top();
                    if(b=='^'||b=='*'||b=='/'){
                        char b = s.top();
                        postExp += b;
                        s.pop();
                    }
                    else{
                        break;
                    }
                }
                 s.push(inExp[i]);
                }
                else{
                     s.push(inExp[i]);
                }
            }
        }
        else if(inExp[i] == '+'){
            if(s.empty()){
                s.push(inExp[i]);
            }
            else{
                char a = s.top();
                if(a=='^'||a=='*'||a=='/'||a=='+'||a=='-'){
                while(!s.empty()){
                    char b = s.top();
                    if(b=='^'||b=='*'||b=='/'||b=='+'||b=='-'){
                        char b = s.top();
                        postExp += b;
                        s.pop();
                    }
                    else{
                        break;
                    }
                }
                 s.push(inExp[i]);
                }
                else{
                    s.push(inExp[i]);
                }
            }
        }
        else if(inExp[i] == '-'){
            if(s.empty()){
                s.push(inExp[i]);
            }
            else{
                char a = s.top();
                if(a=='^'||a=='*'||a=='/'||a=='+'||a=='-'){
                while(!s.empty()){
                    char b = s.top();
                    if(b=='^'||b=='*'||b=='/'||b=='+'||b=='-'){
                        char b = s.top();
                        postExp += b;
                        s.pop();
                    }
                    else{
                        break;
                    }
                }
                 s.push(inExp[i]);
                }
                else{
                    s.push(inExp[i]);
                }
            }
        }
        else{
            postExp += inExp[i];
        }
    }
    while(!s.empty()){
        postExp += s.top();
        s.pop();
    }
}
int main(){
    string inExp;
    cout<<"Enter the infix expression: ";
    cin>>inExp;
    string postExp=" ";
    infixToPostfix(inExp,postExp);
    cout<<"The postfix expression is: "<<postExp<<endl;
}
