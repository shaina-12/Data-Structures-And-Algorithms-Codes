import numpy as np
def knapsack(maxWeight,weight,profit):
    totalProfit = 0
    fraction = [profit[i]/weight[i] for i in range(len(weight))]  
    '''print(fraction)
    print(weight)
    print(profit)'''
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
    '''print(fraction)
    print(weight)
    print(profit)'''
    '''fwp = np.array([fraction,weight,profit])
    fwp.transpose()
    fwp = [list(fwp[0]),list(fwp[1]),list(fwp[2])]
    nl = sorted(fwp,key = lambda x: x[0], reverse = True)
    nl = np.array(nl)
    nl = nl.transpose()
    nl = [list(nl[0]),list(nl[1]),list(nl[2])]
    itr = 0
    w = []
    p = []
    while(maxWeight > 0):
        if(nl[1][itr] <= maxWeight):
            totalProfit = totalProfit + nl[2][itr]
            maxWeight = maxWeight - nl[1][itr]
            p.append(nl[2][itr])
            w.append(nl[1][itr])
            itr = itr + 1
        else:
            break
    newProfit = 0.0
    if(itr<len(weight)):
        newProfit =  ((nl[2][itr] * maxWeight)/nl[1][itr])
        totalProfit = totalProfit + newProfit
        p.append(newProfit)
        w.append(maxWeight)
        maxWeight = 0
    return totalProfit, w, p'''
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
#print(choosenWeight)
