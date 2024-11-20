#pragma GCC optimize("O3")

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int map[201] = {};
        vector<vector<int>> res;
        for (const auto i: nums) {
            ++map[i];
            if (map[i] > res.size()) {
                res.push_back({i});
            } else {
                res[map[i] - 1].push_back(i);
            }
        }

        return res;
    }
};