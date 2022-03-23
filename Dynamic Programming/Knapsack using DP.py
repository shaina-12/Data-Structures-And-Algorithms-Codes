# -*- coding: utf-8 -*-
"""
Created on Wed Mar 23 19:24:34 2022

@author: Shaina Mehta
"""

# implement 0/1 Knapsack using DP

# 0/1 Knapsack Using Dynamic Programming
import numpy as np
noi = int(input())
maxW = int(input())
item = [i+1 for i in range(noi)]
weight = list(map(int,input().split()))
profit = list(map(int,input().split()))
p, w, it = (list(t) for t in zip(*sorted(zip(profit,weight,item))))
m = np.zeros((noi+1,maxW+1),dtype=int)
# print(mat)
for i in range(0,noi+1):
    for wt in range(0,maxW+1):
        if(i==0 or wt==0):
            m[i][wt] = 0
        elif(w[i-1]<=wt):
            m[i][wt] = max(m[i-1,wt],m[i-1][wt-w[i-1]]+p[i-1])
        else:
            m[i][wt]=m[i-1][wt]
totalProfit = m[noi][maxW]
print(totalProfit)

# traceback
tmp = totalProfit
tmp1 = maxW
x = []
j = noi
k = maxW
fin = [0 for i in range(noi)]
while(tmp!=0):
    print(tmp)
    if(tmp!=m[j-1][k]):
        tmp -= p[j-1]
        x.append(j)
        tmp1 -= w[j-1]
        k = tmp1
    else:
        j=j-1
print(it)
print(w)
print(p)
for i in x:
    fin[i-1] = 1
print(fin)
    