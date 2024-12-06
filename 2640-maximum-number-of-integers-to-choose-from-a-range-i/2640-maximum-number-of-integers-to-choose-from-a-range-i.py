class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        numbers = list(set(range(1, n + 1)).difference(set(banned)))
        numbers.sort()
        count = 0
        sum = 0
        for n in numbers:
            sum += n
            if sum > maxSum:
                return count
            count += 1
        return count