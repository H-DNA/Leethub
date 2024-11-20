class Solution:
    @cache
    def Alice(self, i: int, j: int) -> Tuple[int, int]:
        if i > j:
            return (0, 0)
        a1, b1 = self.Bob(i + 1, j)
        a1 += self.piles[i]
        a2, b2 = self.Bob(i, j - 1)
        a2 += self.piles[j]
        return (a1, b1) if a1 - b1 > a2 - b2 else (a2, b2)
        

    @cache
    def Bob(self, i: int, j: int) -> Tuple[int, int]:
        if i == j:
            return (0, self.piles[i])
        a1, b1 = self.Alice(i + 1, j)
        b1 += self.piles[i]
        a2, b2 = self.Alice(i, j - 1)
        b2 += self.piles[j]
        return (a1, b1) if a1 - b1 < a2 - b2 else (a2, b2)

    def stoneGame(self, piles: List[int]) -> bool:
        self.piles = piles
        a, b = self.Alice(0, len(piles) - 1)
        return a > b