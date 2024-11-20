class Solution:
    def minSteps(self, n):
        if n == 1: return 0
        if n == 2: return 2
        
        currNum = 2
        step = 2
        cpNum = 1
        
        while currNum != n:
            if n % currNum == 0:
                step += 2
                cpNum = currNum
            else:
                step +=1
            currNum += cpNum
        return step