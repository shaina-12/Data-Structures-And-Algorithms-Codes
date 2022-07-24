void cleanRow(int i, vector<vector<int>>& matrix){
    for(int j=0;j<matrix[0].size();j++){
        matrix[i][j]=0;
    }
}
void cleanCol(int j, vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        matrix[i][j]=0;
    }
}
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> index;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    index.push_back(v);
                }
            }
        }
        for(int i=0;i<index.size();i++){
            cleanRow(index[i][0],matrix);
            cleanCol(index[i][1],matrix);
        }
    }
};
