map<char,string> comb = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},                             {'9',"wxyz"}};
void combinations(string digits, vector<string> &ans, int itr,string s){
    if(itr==digits.length()){
        ans.push_back(s);
        return;
    }
    char a = digits[itr];
    for(int i=0;i<comb[a].length();i++){
        s += comb[a][i];
        combinations(digits,ans,itr+1,s);
        s.pop_back();
    }
    return;
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string s = "";
        combinations(digits,ans,0,s);
        return ans;
    }
};
