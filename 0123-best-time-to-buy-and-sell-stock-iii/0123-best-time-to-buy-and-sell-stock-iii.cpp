class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int firstProfit = 0, totalProfit = -100000, firstBuy = prices[0], secondBuy = -100000;
      
      for (int& i: prices) {
        firstBuy = min(firstBuy, i);
        firstProfit = max(firstProfit, i - firstBuy);
        secondBuy = max(secondBuy, firstProfit - i);
        totalProfit = max(totalProfit, secondBuy + i);
      }
      return totalProfit;
    }
};