class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int left = 0, right = nums.size() - 1;
      std::vector<int> oarr(nums.size());
      int ptr = right;
      while (left <= right) {
        if (nums[left] * nums[left] > nums[right] * nums[right]) {
          oarr[ptr--] = (nums[left] * nums[left]);
          ++left;
        }
        else {
          oarr[ptr--] = (nums[right] * nums[right]);
          --right;
        }
      }
      return oarr;
    }
};