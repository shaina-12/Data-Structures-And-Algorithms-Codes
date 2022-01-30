#User function Template for python3

class Solution:
    
    #Function to find the length of longest common subsequence in two strings.
    def lcs(self,x,y,s1,s2):
        # code here
        ans = [[0 for i in range(y+1)] for i in range(x+1)]
        for i in range(x+1):
            for j in range(y+1):
                if(i==0 or j==0):
                    ans[i][j] = 0
                elif(s1[i-1] == s2[j-1]):
                    ans[i][j] = ans[i-1][j-1]+1
                else:
                    ans[i][j] = max(ans[i-1][j],ans[i][j-1])
        return ans[x][y]

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        x,y = map(int,input().strip().split())
        s1 = str(input())
        s2 = str(input())
        ob=Solution()
        print(ob.lcs(x,y,s1,s2))
# } Driver Code Ends
