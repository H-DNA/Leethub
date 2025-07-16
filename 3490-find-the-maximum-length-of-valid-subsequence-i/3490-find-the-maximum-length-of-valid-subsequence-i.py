class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        num_0 = 0
        num_1 = 0
        num_same = 0
        if nums[0] % 2 == 0:
            num_0 += 1
        else:
            num_1 += 1
        for i in range(1, len(nums)):
            prev = nums[i - 1] % 2
            cur = nums[i] % 2
            if cur % 2 == 0:
                num_0 += 1
            else:
                num_1 += 1
            if prev == cur:
                num_same += 1
        return len(nums) - min(num_0, num_1, num_same)