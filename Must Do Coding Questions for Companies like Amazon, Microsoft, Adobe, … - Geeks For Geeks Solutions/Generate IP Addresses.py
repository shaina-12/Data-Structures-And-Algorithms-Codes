#Your Function should return a list containing all possible IP address
#No need to worry about order
class Solution:
    def checkIP(self,s):
        s = s.split('.')
        for i in s:
            if(len(i)>3 or int(i)<0 or int(i)>255):
                return False
            if(len(i)>1 and int(i)==0):
                return False
            if(len(i)>1 and int(i)!=0 and i[0]=='0'):
                return False
        return True
    def genIp(self, s):
        #Code here
        sz = len(s)
        if(sz>12 and sz<4):
            return []
        snew = s
        l = []
        for i in range(1,sz-2):
            for j in range(i+1,sz-1):
                for k in range(j+1,sz):
                    snew = snew[:k]+'.'+snew[k:]
                    snew = snew[:j]+'.'+snew[j:]
                    snew = snew[:i]+'.'+snew[i:]
                    if(self.checkIP(snew)):
                        l.append(snew)
                    snew = s
        return l
        
#{ 
#  Driver Code Starts
#Main
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s = input().strip()
        res = Solution().genIp(s)
        res.sort()
        for u in res:
            print(u)
        
# } Driver Code Ends
