class Solution
{
public:
    // taken reference from https://discuss.geeksforgeeks.org/comment/a727c7ce244edbcac9739ff8745a99e7/practice
    long long sumOfDivisors(int N)
    {
        long long sum=0;
        // Write Your Code here
        for(int i=1;i<=N;i++){
            sum += (i*(N/i));
        }
        return sum;
    }
};
