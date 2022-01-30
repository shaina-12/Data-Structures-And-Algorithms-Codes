#User function Template for python3

class Solution:
    def count(self, S, m, n): 
        # code here
        ans = [[0 for j in range(m)] for i in range(n+1)]
        # Fill the entries for 0 value case (n = 0)
        for i in range(m):
            ans[0][i] = 1
        for i in range(1,n+1):
            for j in range(m):
                #counting the solution including S[j]
                x = ans[i-S[j]][j] if i-S[j]>=0 else 0
                #counting the solution excluding S[j]
                y = ans[i][j-1] if j>=1 else 0
                ans[i][j] = x+y
        return ans[n][m-1]
#{ 
#  Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n,m = list(map(int, input().strip().split()))
        S = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.count(S,m,n))
# } Driver Code Ends
