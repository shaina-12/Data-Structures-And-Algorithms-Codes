class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else if(s[i]==')' && st.size()!=0){
                if(st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']' && st.size()!=0){
                if(st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}' && st.size()!=0){
                if(st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        if(st.size()>0){
            return false;
        }
        return true;
    }
};
