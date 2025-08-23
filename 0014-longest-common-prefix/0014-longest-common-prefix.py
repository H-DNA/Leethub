class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]
        res = 0
        fstr = strs[0]
        strs = strs[1:]
        while True:
            if len(fstr) <= res:
                return fstr
            for str in strs:
                if len(str) <= res:
                    return fstr[:res]
                if str[res] != fstr[res]:
                    return fstr[:res]
            res += 1
        return fstr[:res]
