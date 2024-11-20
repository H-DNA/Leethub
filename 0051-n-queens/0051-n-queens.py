class Solution:
    def recur(self, row: int, cols: Set[int], ldiags: Set[int], rdiags: Set[int], n: int, chosenCols: List[int]) -> List[List[str]]:
        if row == n:
            return [list(map(lambda col: "." * col + "Q" + "." * (n - col - 1), chosenCols))]
        res = []
        for col in range(n):
            if col not in cols or col - row not in ldiags or row + col not in rdiags:
                continue
            cols.remove(col)
            ldiags.remove(col - row)
            rdiags.remove(row + col)
            res_tmp = self.recur(row + 1, cols, ldiags, rdiags, n, chosenCols + [col])
            if len(res_tmp):
                res += res_tmp
            cols.add(col)
            ldiags.add(col - row)
            rdiags.add(row + col)
        return res
        
    def solveNQueens(self, n: int) -> List[List[str]]:
        cols = set(range(n))
        ldiags = set(range(-n + 1, n))
        rdiags = set(range(2 * n))
        return self.recur(0, cols, ldiags, rdiags, n, [])