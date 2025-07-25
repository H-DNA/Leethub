class Solution:
    def maxSum(self, nums: List[int]) -> int:
        max = nums[0]
        for n in nums:
            if max < n: max = n
        if max <= 0:
            return max
        appeared = {}
        sum = 0
        for n in nums:
            if n < 0: continue
            if n in appeared: continue
            appeared[n] = True
            sum += n
        return sum