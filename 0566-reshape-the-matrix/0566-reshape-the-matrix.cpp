class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, const int r, const int c) {
      const int m = mat.size(), n = mat[0].size();
      if (m * n != r * c) return mat;
      std::vector<std::vector<int>> newmat(r);
      int col = 0, row = 0;
      for (auto& i: mat)
        for (auto j: i) {
          newmat[row].push_back(j);
          ++col;
          if (col >= c) {
            col = 0;
            ++row;
          }
        }
      return newmat;
    }
};