class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 1:
            return 0
        sum = 0
        left_monotonic_height = [[-1, 0]]
        for (id, h) in enumerate(height):
            while len(left_monotonic_height) and left_monotonic_height[-1][-1] <= h:
                removed = left_monotonic_height.pop()
                if len(left_monotonic_height):
                    last = left_monotonic_height[-1]
                    sum += (id - last[0] - 1) * (min(h, last[1]) - removed[1])
            left_monotonic_height.append((id, h))
        return sum
