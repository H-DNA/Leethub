class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> buf;
        recur(res, buf, 1, n, k);
        return res;
    }
    
    void recur(vector<vector<int>>& res, vector<int>& buf, int l, int r, int k) {
        if (k == 0) {
            res.push_back(buf);
            return;
        }
        for (int i = l; i <= r - k + 1; ++i) {
            buf.push_back(i);
            recur(res, buf, i + 1, r, k - 1);
            buf.pop_back();
        }
    }
};