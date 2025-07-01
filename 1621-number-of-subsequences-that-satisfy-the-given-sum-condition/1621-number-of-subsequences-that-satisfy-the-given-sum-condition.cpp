#include <algorithm>
#include <cmath>

class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;
    
    int numSubseq(vector<int>& nums, int target) {
        vector<int> power(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
        long long count = 0;
        std::sort(nums.begin(), nums.end());
        int maxj = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (; maxj >= i; --maxj) {
                if (nums[i] + nums[maxj] <= target) {
                    break;
                }
            }
            if (maxj < i) {
                continue;
            }
            int disp = maxj - i;
            count = (count + power[disp]) % MOD;
        }
        return count;
    }
};