class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
      int sum = 0;  
      std::vector<int> switchCosts;
      for (auto& c: costs) {
        sum += c[0];
        switchCosts.push_back(c[1] - c[0]);
      }
      sort(switchCosts.begin(), switchCosts.end());
      for (int i = 0; i < costs.size() / 2; ++i)
          sum += switchCosts[i];
      return sum;
    }
};