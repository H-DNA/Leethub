class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       std::vector<int> res(triangle.size());
       res[0] = triangle[0][0];
       for (int step = 1; step < triangle.size(); ++step) {
           const int len = step + 1;
           res[len - 1] = triangle[step][len - 1] + res[len - 2];
           for (int i = len - 2; i >= 1; --i) {
               res[i] = min(res[i], res[i - 1]) + triangle[step][i];
           }
           res[0] += triangle[step][0];
       }
        int min_v = INT_MAX;
        for (auto v: res)
            min_v = min(min_v, v);
        return min_v;
    }
};