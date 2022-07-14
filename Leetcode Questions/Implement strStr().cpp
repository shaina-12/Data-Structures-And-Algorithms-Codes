class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        if(haystack.compare(needle)==0){
            return 0;
        }
        int itr = needle.size();
        for(int i=0;i<haystack.length();i++){
            string s = haystack.substr(i,itr);
            //cout<<s<<" "<<i<<" "<<i+itr<<endl;
            if(needle.compare(s)==0){
                return i;
            }
        }
        return -1;
    }
};
