class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        max_can = max(candidates)
        count = {}
        i = 0
        n = 1
        while n <= max_can:
            n = 1 << i
            for c in candidates:
                count[i] = count.get(i, 0) + int((n & c) > 0)
            i += 1
        return max(count.values())