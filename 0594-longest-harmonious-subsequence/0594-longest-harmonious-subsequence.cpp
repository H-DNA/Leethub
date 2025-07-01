class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int max_count = 0;
        int prev;
        int cur = nums[0];
        int prev_count = 0;
        int cur_count = 1;
        for (int i = 1; i < nums.size() + 1; ++i) {
            if (prev_count > 0 && cur_count > 0 && cur - prev == 1) {
                max_count = std::max(max_count, prev_count + cur_count);
            }
            if (i == nums.size()) {
                break;
            }
            if (nums[i] != nums[i-1]) {
                prev_count = cur_count;
                cur_count = 1;
                prev = cur;
                cur = nums[i];
            } else {
                ++cur_count;
            }
        }
        return max_count;
    }
};