# cook your dish here
import itertools as it

def bounds(arr):
    for i in range(len(arr)):
        if(arr[i]<0 or arr[i]>25):
            return False
    return True

t = int(input())
while(t>0):
    s = input()
    ls = len(s)
    hash_val = 0
    for i in s:
        hash_val+=abs(ord(i)-97)
    li = list(it.product(range(74),repeat=3))
    #print(len(li))
    l1 = []
    for i in range(len(li)):
        if(sum(li[i])==hash_val and bounds(li[i])==True):
            st = ""
            for j in range(ls):
                st += chr(li[i][j]+97)
            if(st>s):
                #print(st)
                l1.append(st)
    #print(len(l1))
    l1.sort()
    print(str(hash_val)+" "+l1[0])
    t = t-1

