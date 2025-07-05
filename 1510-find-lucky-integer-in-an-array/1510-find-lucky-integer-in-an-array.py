class Solution:
    def findLucky(self, arr: List[int]) -> int:
        freq = {}
        for num in arr:
            if num not in freq:
                freq[num] = 1
            else:
                freq[num] += 1
        max_num = -1
        for num, f in freq.items():
            if num == f and max_num < num:
                max_num = num
        return max_num
        