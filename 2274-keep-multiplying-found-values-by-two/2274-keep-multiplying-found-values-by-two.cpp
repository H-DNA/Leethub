class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        constexpr int max_num = 1001;
        bool jump_tbl[max_num];
        for (int i = 0; i < max_num; ++i) jump_tbl[i] = false;
        for (int& i: nums) jump_tbl[i] = true;
        while (true) {
          if (original > 1000) return original;
          if (jump_tbl[original]) original *= 2;
          else return original;
        }
    }
};