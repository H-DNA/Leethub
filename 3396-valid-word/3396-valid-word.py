class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        oneVowel = False
        oneConsonant = False
        for c in word:
            if c.lower() not in "0123456789abcdefghijklmnopqrstuvwxyz":
                return False
            if c.lower() in "ueoai":
                oneVowel = True
            elif c not in "0123456789":
                oneConsonant = True
        return oneVowel and oneConsonant
        