class Solution {
public:
    int rob(vector<int>& nums) {
        const int l = nums.size();
        if (l == 1) return nums[0];
        std::vector<int> val(l);
        val[0] = nums[0];
        val[1] = max(nums[0], nums[1]);
        for (int i = 2; i < l; ++i) {
            val[i] = max(val[i - 1], nums[i] + val[i - 2]);
        }
        return val[l - 1];
    }
};