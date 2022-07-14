class Solution {
public:
    void reverseString(vector<char>& s) {
        int si = 0;
        int ei = s.size()-1;
        while(si<ei){
            char c = s[si];
            s[si] = s[ei];
            s[ei] = c;
            si++;
            ei--;
        }
    }
};
