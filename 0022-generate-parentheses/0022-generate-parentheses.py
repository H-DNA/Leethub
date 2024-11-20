class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 1:
            return ["()"]
        return set([string[:pos] + "()" + string[pos:] for string in self.generateParenthesis(n - 1) for pos in range(len(string))])