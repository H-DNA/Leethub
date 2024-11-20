class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      std::vector<std::pair<int,int>> stack;
      int max = 0;
      const int m = grid.size(), n = grid[0].size();
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          if (grid[i][j]) {
            int count = 0;
            stack.push_back({i, j});
            grid[i][j] = 0;
            while (!stack.empty()) {
              auto pix = stack[stack.size() - 1];
              stack.pop_back();
              int r = pix.first, c = pix.second;
              
              ++count;
              
              if (r > 0 && grid[r - 1][c]) {stack.push_back({r-1, c});grid[r-1][c] = 0;}
              if (r < m - 1 && grid[r + 1][c]) {stack.push_back({r+1, c});grid[r+1][c] = 0;}
              if (c > 0 && grid[r][c - 1]) {stack.push_back({r, c - 1});grid[r][c-1] = 0;}
              if (c < n - 1 && grid[r][c + 1]) {stack.push_back({r, c + 1});grid[r][c+1] = 0;}
            }
            if (max < count) max = count;
          }
        }
      return max;
    }
};