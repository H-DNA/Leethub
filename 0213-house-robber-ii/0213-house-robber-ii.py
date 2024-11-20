class Solution:
    @cache
    def max_rob(self, i: int, j: int) -> int:
        if i > j:
            return 0
        res = 0
        for k in range(i, min(j + 1, i + 3)):
            res = max(self.nums[k] + self.max_rob(k + 2, j), res)
        return res
    
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 3:
            return max(nums)
        self.nums = nums
        n = len(nums)
        res = 0
        for i in range(-1, 2):
            res = max(nums[i] + self.max_rob((i + 2) % n, (i - 2 + n) % n), res)
        return res