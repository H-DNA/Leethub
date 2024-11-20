class Solution {
public:
    int dominantIndex(vector<int>& nums) {
      if (nums.size() == 0) return -1;
      else if (nums.size() == 1) return 0;
      
      int id_max, max, sec_max;
      
      if (nums[0] < nums[1]) {
        id_max = 1;
        max = nums[1];
        sec_max = nums[0];
      } else {
        id_max = 0;
        max = nums[0];
        sec_max = nums[1];
      }
      
      for (int i = 2; i < nums.size(); ++i) {
        if (max <= nums[i]) {
          id_max = i;
          sec_max = max;
          max = nums[i];
        }
        else if (sec_max < nums[i]) {
           sec_max = nums[i];
        }
      }
      if (max >= 2 * sec_max) return id_max;
      else return -1;
    }
};