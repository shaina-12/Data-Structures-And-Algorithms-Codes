class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size()==0){
            return ans;
        }
        if(strs.size()==1){
            ans.push_back(strs);
            return ans;
        }
        unordered_map<string,int> m;
        int grp = 0;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(m.find(s)==m.end()){
                m[s] = grp;
                grp++;
                vector<string> v;
                v.push_back(strs[i]);
                ans.push_back(v);
            }
            else{
                int ind = m[s];
                ans[ind].push_back(strs[i]);
            }
        }
        return ans;
    }
};
