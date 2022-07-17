class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> a = {1};
        v.push_back(a);
       if(numRows>=2){
            vector<int> b = {1,1};
            v.push_back(b);
       } 
        for(int i=2;i<numRows;i++){
            vector<int> v1;
            v1.push_back(1);
            for(int j=0;j<i-1;j++){
                v1.push_back(v[i-1][j]+v[i-1][j+1]);
            }
            v1.push_back(1);
            v.push_back(v1);
        }
        return v;
    }
};
