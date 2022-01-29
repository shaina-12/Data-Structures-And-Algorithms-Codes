# function to return maximum XOR subset in set[]
int_bits = 32
class Solution:
    def maxSubarrayXOR(self, arr, N):
        # add code here
        index = 0
        for i in range(int_bits-1,-1,-1):
            maxInd = index
            maxEle = -2147483648
            for j in range(index,N):
                if((arr[j] & (1<<i))!=0 and arr[j] > maxEle):
                    maxEle = arr[j]
                    maxInd = j
            if(maxEle == -2147483648):
                continue
            
            temp = arr[index]
            arr[index] = arr[maxInd]
            arr[maxInd] = temp
            maxInd = index
            #index = index + 1
            for j in range(N):
                if(j!=maxInd and (arr[j] & (1<<i))!=0):
                    arr[j] = arr[j] ^ arr[maxInd]
            index = index + 1
            
        res = 0
        for i in range(N):
            res = res ^ arr[i]
        return res
#{ 
#  Driver Code Starts
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        n=int(input())
        set=list(map(int,input().split()))
        obj = Solution()
        print(obj.maxSubarrayXOR(set,n))
# } Driver Code Ends
