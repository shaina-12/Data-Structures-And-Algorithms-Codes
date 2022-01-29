#User function Template for python3

class Solution:

    def candyStore(self, candies,N,K):
        # code here
        candies.sort()
        minCost = 0
        maxCost = 0
        tmp = 0
        for i in range(N):
            if(tmp>=N):
                break
            minCost = minCost + candies[i]
            maxCost = maxCost + candies[N-i-1]
            tmp = tmp + 1
            tmp = tmp + K
        return (minCost, maxCost)
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):

        N,K = [int(x) for x in input().split()]
        candies = [int(x) for x in input().split()]

        solObj = Solution()

        print(*solObj.candyStore(candies,N,K))
# } Driver Code Ends
