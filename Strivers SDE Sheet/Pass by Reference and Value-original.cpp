class Solution {
  public:
    vector<int> passedBy(int a, int &b) {
        // code here
        vector <int> result;
        result.push_back(a+1);
        result.push_back(b+2);
        return result;
    }
};
