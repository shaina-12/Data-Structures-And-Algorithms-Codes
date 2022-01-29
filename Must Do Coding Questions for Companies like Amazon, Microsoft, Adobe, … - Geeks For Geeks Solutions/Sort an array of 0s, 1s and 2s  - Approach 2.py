#User function Template for python3

class Solution:
    def sort012(self,arr,n):
        # code here
        low = 0
        high = n-1
        mid = 0
        while(mid<=high):
            if(arr[mid] == 0):
                arr[low],arr[mid] = arr[mid],arr[low]
                low += 1
                mid += 1
            elif(arr[mid] == 1):
                mid += 1
            elif(arr[mid] == 2):
                arr[mid],arr[high] = arr[high],arr[mid]
                high -= 1
                
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        n=int(input())
        arr=[int(x) for x in input().strip().split()]
        ob=Solution()
        ob.sort012(arr,n)
        for i in arr:
            print(i, end=' ')
        print()

# } Driver Code Ends
