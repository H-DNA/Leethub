class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        acc_sum, i, count = 1, 0, 0
        while acc_sum <= n:
            if i < len(nums) and nums[i] <= acc_sum:
                acc_sum += nums[i]
                i += 1
            else:
                acc_sum *= 2
                count += 1
        return count