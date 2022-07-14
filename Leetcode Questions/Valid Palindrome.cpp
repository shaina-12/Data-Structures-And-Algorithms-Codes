class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(isalpha(c) || isdigit(c)){
                t+=tolower(c);
            }
        }
        int si = 0;
        int ei = t.length()-1;
        while(si<ei){
            if(t[si]!=t[ei]){
                return false;
            }
            si++;
            ei--;
        }
        return true;
    }
};
