class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        sums = []
        sum = 0 
        for n in nums:
            sum += n
            sums.append(sum)
        return sums