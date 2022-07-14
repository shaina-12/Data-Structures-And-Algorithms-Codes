class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        bool b;
        if(s.length()!=t.length()){
            b=false;
        }
        else if(s.compare(t)!=0){
            b=false;
        }
        else{
            b=true;
        }
        return b;
    }
};
