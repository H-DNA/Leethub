class Solution:
    def squareSum(self, n: int) -> int:
        res = 0
        while n > 0:
            res += (n % 10) ** 2
            n //= 10
        return res

    def isHappy(self, n: int) -> bool:
        s = set()
        s.add(n)
        while True:
            n = self.squareSum(n)
            if n == 1:
                return True
            if n in s:
                return False
            s.add(n)