class Solution {
public:
    vector<int> generateNextRow(const vector<int>* const prevVec) {
        vector<int> v(0);
        v.push_back(1);
        for (int i = 0; i < prevVec->size() - 1; ++i) {
            v.push_back((*prevVec)[i] + (*prevVec)[i + 1]);
        }
        v.push_back(1);
        return v;
    }
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return {};
        }
        vector<vector<int>> res(numRows);
        res[0] = vector<int>{ 1 };
        for (int i = 1; i < numRows; ++i) {
            res[i] = generateNextRow(&res[i - 1]);
        }
        return res;
    }
};