class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
      long int rightSum = 0;
      for (const auto num: nums) {
        rightSum += num;
      }
      long int leftSum = 0;
      const long int len = nums.size() - 1;
      long unsigned int res = 0;
      for (int i = 0; i < len; ++i) {
        const long unsigned int n = nums[i];
        leftSum += n;
        rightSum -= n;
        if (leftSum >= rightSum) {
          res += 1;
        }
      }
      return res;
    }
};