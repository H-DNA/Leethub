class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        constexpr int MAXVAL = 1e5;
        constexpr int HALFMAX = MAXVAL >> 1;
        std::vector<int> res;
        int debt[MAXVAL + 1]{};
        sort(changed.begin(), changed.end());
        for (int e: changed) {
            if (debt[e] >= 0 && e > HALFMAX) return {};
            if (debt[e] >= 0) {
                res.push_back(e);
                --debt[e << 1];
            } else
                ++debt[e];
        }
        for (int d: debt)
            if (d < 0) return {};
        return res;
    }
};