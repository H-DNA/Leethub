class Solution {
public:
    int uniquePaths(int m, int n) {
        int smaller = min(m - 1, n - 1);
        int greater = max(m - 1, n - 1);
        
        long long nPaths = 1;
        for (int i = 1; i <= smaller; ++i)
            nPaths = nPaths * (greater + i) / i;
        return nPaths;
    }
};