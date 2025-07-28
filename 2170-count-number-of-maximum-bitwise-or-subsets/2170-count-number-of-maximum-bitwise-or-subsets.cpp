#include <set>

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (auto num: nums) {
            max_or |= num;
        }
        return backtrack(0, 0, nums, max_or);
    }

    int backtrack(int current_or, int index, vector<int>& nums, int max_or) {
        if (index >= nums.size()) {
            return current_or == max_or ? 1 : 0;
        }
        if (current_or == max_or) {
            return (1 << (nums.size() - index));
        }
        return backtrack(current_or | nums[index], index + 1, nums, max_or)
             + backtrack(current_or, index + 1, nums, max_or);
    }
};