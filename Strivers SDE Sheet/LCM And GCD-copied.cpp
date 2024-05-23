class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector <long long> result;
        long long X;
        long long Y;
        if(A>B){
            X=A;
            Y=B;
        }
        else{
            X=B;
            Y=A;
        }
        while(Y>0){
            long long c = X%Y;
            X = Y;
            Y = c;
        }
        long long Z = (A*B)/X;
        result.push_back(Z);
        result.push_back(X);
        return result;
    }
};
