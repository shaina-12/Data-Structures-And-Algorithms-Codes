string findCommonPrefixUtil(string s1, string s2){
        string result;
        int n1 = s1.length();
        int n2 = s2.length();
        for(int i=0,j=0;i<=n1-1&&j<=n2-1;i++,j++){
            if(s1[i]!=s2[j]){
                break;
            }
        result.push_back(s1[i]);
        }
    return result;
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];
        for(int i=1;i<strs.size();i++){
             prefix = findCommonPrefixUtil(prefix,strs[i]);
        }
        return prefix;
    }
};

/*
class Solution {
public:
    
    string prefix(string s1, string s2){
        string str = "";
        int n;
        if(s1.length()<s2.length()){
            n=s1.length();
        }
        else{
            n=s2.length();
        }
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                break;
            }
            str+=s1[i];
        }
        return str;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string refstr = strs[0];
        for(int i=1;i<strs.size();i++){
            string newstr = prefix(refstr,strs[i]);
            if(newstr.length()<refstr.length()){
                refstr=newstr;
            }
        }
        return refstr;
    }
};
*/
