class Solution {
public:
    int hammingDistance(int x, int y) {
        string x1 = bitset<32>(x).to_string();
        string y1 = bitset<32>(y).to_string();
        int ctr=0;
        for(int i=0;i<32;i++){
            if(x1[i]!=y1[i]){
                ctr++;
            }
        }
        return ctr;
    }
};
