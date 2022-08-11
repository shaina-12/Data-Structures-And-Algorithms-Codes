def bestSum(targetSum, numbers):
    if(targetSum==0):
        return []
    if(targetSum<0):
        return None
    shortestCombination = None
    for num in numbers:
        remainder = targetSum - num
        remainderCombination = bestSum(remainder,numbers)
        if(remainderCombination!=None):
            combination = remainderCombination[:]
            combination.append(num)
            if(shortestCombination==None or len(combination)<len(shortestCombination)):
                shortestCombination = combination[:]
    return shortestCombination

if __name__ == "__main__":
    print(bestSum(7,[5,3,4,7])) # [7]
    print(bestSum(8,[2,3,5]))   # [3,5]
    print(bestSum(8,[1,4,5]))   # [4,4]
    print(bestSum(100,[1,2,5,25])) # [25,25,25,25]

