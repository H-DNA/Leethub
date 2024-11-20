class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        map<long long, map<long long, long long>> dp[1001];
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                const long long diff = (long long)nums[i] - nums[j];
                for (const auto& t: dp[j][diff]) {
                    dp[i][diff][t.first + 1] += t.second;
                    res += t.second;
                }
                ++dp[i][diff][1];
            }
        }
        return res;
    }
};