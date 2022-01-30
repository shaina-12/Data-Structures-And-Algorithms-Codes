#User function template for Python

class Solution:
    # your task is to complete this function
    # function should return an integer
    def atoi(self,string):
        # Code here
        for s in string:
            if((s>='a' and s<='z') or (s>='A' and s<='Z')):
                return -1
        num = 0
        for s in string:
            if(s>='0' and s<='9'):
                a = int(s)
                num = num*10+a
        if(string[0] == '-'):
            num = num * -1
        return num
#{ 
#  Driver Code Starts
#Initial template for Python

if __name__=='__main__':
    t=int(input())
    for i in range(t):
        string = input().strip();
        ob=Solution()
        print(ob.atoi(string))
# } Driver Code Ends
