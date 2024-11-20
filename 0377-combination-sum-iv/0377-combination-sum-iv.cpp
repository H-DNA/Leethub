class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        unsigned int buff[1001] = {1, 0};
        for (int i = 1; i <= target; ++i) {
            for (int j: nums) {
                if (i - j < 0) {
                    break;
                }
                buff[i] += buff[i - j];
            }
        }
        return buff[target];
    }
};
