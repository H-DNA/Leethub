class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        res = []
        for f in folder:
            if len(res) == 0:
                res.append(f)
            elif not f.startswith(res[-1] + "/"):
                res.append(f)
        return res