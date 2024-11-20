class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int buy = -1;
      int max_prof = 0;
      for (auto i: prices) {
        if (buy == -1 or buy > i) buy = i;
        max_prof = max(max_prof, i - buy);
      }
      return max_prof;
    }
};