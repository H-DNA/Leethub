class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<vector<int>> res(m);
        for (auto& r: res)
            r = vector<int>(n, INT_MAX);
        
        vector<vector<bool>> checked(m);
        for (auto& r: checked)
            r = vector<bool>(n, false);
        
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (grid[r][c] == 2) {
                    q.push({r, c});
                    checked[r][c] = true;
                    res[r][c] = 0;
                }
                else if (grid[r][c] == 0) {
                    res[r][c] = -1;
                    checked[r][c] = true;
                }
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int new_d = res[p.first][p.second] + 1;
            if (p.first > 0) handlePoint(q, checked, res, new_d, p.first - 1, p.second);
            if (p.first < m - 1) handlePoint(q, checked, res, new_d, p.first + 1, p.second);
            if (p.second > 0) handlePoint(q, checked, res, new_d, p.first, p.second - 1);
            if (p.second < n - 1) handlePoint(q, checked, res, new_d, p.first, p.second + 1);
        }
        
        int max_t = -1;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                max_t = max(max_t, res[r][c]);
        if (max_t == INT_MAX) return -1;
        else if (max_t == -1) return 0;
        else return max_t;
        
    }
    
    inline void handlePoint(queue<pair<int, int>>& q, vector<vector<bool>>& checked, vector<vector<int>>& res, int dist, int pr, int pc) {
        if (!checked[pr][pc]) {
            q.push({pr, pc});
            checked[pr][pc] = true;
            res[pr][pc] = dist;
        }
    }
};