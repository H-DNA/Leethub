from functools import reduce

class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morseBoard = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        tbl = dict()
        for word in words:
            tbl[reduce(lambda a, b: a + morseBoard[ord(b) - ord('a')], ' ' + word)] = True
        return len(tbl.keys())
        
        