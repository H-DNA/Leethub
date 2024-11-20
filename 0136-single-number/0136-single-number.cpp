class Solution {
public:
    int singleNumber(vector<int>& nums) {
        static std::mt19937 mt;
        
        int left = 0, right = nums.size() - 1;
        while (true) {
            if (right == left) return nums[left];
            int pivot = std::uniform_int_distribution<int>{left, right}(mt);
            int pivot_e = nums[pivot];
            swap(nums[pivot], nums[right]);
            int less_right = left;
            for (int i = left; i < right; ++i)
                if (nums[i] < pivot_e) swap(nums[i], nums[less_right++]);
                else if (nums[i] == pivot_e) {
                    if (i == right -1) break;
                    swap(nums[i], nums[right - 1]);
                    --i;
                }
            if (nums[right] != nums[right - 1]) return pivot_e;
            if ((less_right - left) % 2 == 1) right = less_right - 1;
            else {
                left = less_right;
                right -= 2;
            }
        }
        return -1;
    }
};