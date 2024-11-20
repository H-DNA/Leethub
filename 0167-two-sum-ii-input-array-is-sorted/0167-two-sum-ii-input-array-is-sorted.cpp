class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int left = 0;
      int right = numbers.size() - 1;
      while (left < right) {
        while (numbers[left] + numbers[right] > target)
          --right;
        if (numbers[left] + numbers[right] == target) return {left + 1, right + 1};
        ++left;
      }
      return {};
    }
};