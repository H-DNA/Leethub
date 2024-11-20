class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        
        vector<vector<int>> res(m);
        for (auto& r: res)
            r = vector<int>(n, INT_MAX);
        
        vector<vector<bool>> checked(m);
        for (auto& r: checked)
            r = vector<bool>(n, false);
        
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (mat[r][c] == 0) {
                    q.push({r, c});
                    checked[r][c] = true;
                    res[r][c] = 0;
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
        return res;
        
    }
    
    inline void handlePoint(queue<pair<int, int>>& q, vector<vector<bool>>& checked, vector<vector<int>>& res, int dist, int pr, int pc) {
        if (!checked[pr][pc]) {
            q.push({pr, pc});
            checked[pr][pc] = true;
            res[pr][pc] = dist;
        }
    }
};