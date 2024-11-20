class Point {
public:
  int id;
  int num;
  bool operator<(const Point& other) {
  return (num < other.num || (num == other.num && id < other.id));
  }

  bool operator==(const Point& other) {
    return (id == other.id && num == other.num);
  }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      std::vector<Point> line;  
      for (int r = 0; r < mat.size(); ++r) {
        int soldier_count = 0;
        for (int c = 0; c < mat[0].size(); ++c) {
            if (mat[r][c]) ++soldier_count;
            else break;
        }
        line.push_back({r, soldier_count});
      } 
      sort(line.begin(), line.end());
      std::vector<int> out;
      for (int i = 0; i < k; ++i)
        out.push_back(line[i].id);
      return out;
    }
};