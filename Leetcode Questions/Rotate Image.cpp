class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()-1;i++){
            for(int j=i+1;j<matrix[i].size();j++){
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
        int start=0;
        int end = matrix.size()-1;
        while(start<end){
            for(int j=0;j<matrix[0].size();j++){
                int temp = matrix[j][start];
                matrix[j][start] = matrix[j][end];
                matrix[j][end] = temp;
            }
            start++;
            end--;
        }
        
    }
};
