import numpy as np
def knapsack(maxWeight,weight,profit):
    totalProfit = 0
    fraction = [profit[i]/weight[i] for i in range(len(weight))]  
    fraction, weight, profit = zip(*sorted(zip(fraction,weight,profit),reverse = True))
    fraction = list(fraction)
    weight = list(weight)
    profit = list(profit)
    n = len(fraction)
    selObj = [0.0 for i in range(len(weight))]
    for i in range(n):
        if(weight[i] < maxWeight):
            totalProfit = totalProfit + profit[i]
            maxWeight = maxWeight - weight[i]
            selObj[i] = 1.0
        else:
            break
    if(i<n):
        fract = maxWeight/weight[i]
        totalProfit = totalProfit + (profit[i]*fract)
        maxWeight = 0
        selObj[i] = fract
    return totalProfit, selObj
#capacity of knapsack
maxWeight = int(input())
#weight of the given objects
weight = list(map(int,input().split()))
#profit associated with the given objects
profit = list(map(int,input().split()))
totalProfit, selObj = knapsack(maxWeight,weight,profit)
#Total profit
print(totalProfit)
#Portion of items selected
print(selObj)
