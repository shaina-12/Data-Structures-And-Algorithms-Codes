import random as rn
def rec(l,n,ind):
    #print(ind)
    if(n == ind):
        return
    s = l[ind]
    #print(s)
    i = ind - 1
    while(i>=0 and s<l[i]):
        l[i+1] = l[i]
        #print(l[i+1])
        #print(l[i])
        i = i - 1
    l[i+1] = s
    #print(l)
    rec(l,n,ind + 1)

def ins(l,n):
    ind = 1
    #print(l[ind])
    rec(l,n,ind)
n = int(input())
l = [rn.randint(1,100) for i in range(n)]
print(l)
ins(l,n)
print(l)