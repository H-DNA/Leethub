#include <vector>

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        std::vector<int> monotonic_stack = vector<int>();
        for (int i = prices.size() - 1; i >= 0; --i) {
            const int price = prices[i];
            while (monotonic_stack.size() && monotonic_stack[monotonic_stack.size() - 1] > price) {
                monotonic_stack.pop_back();
            }
            if (monotonic_stack.size()) {
                prices[i] -= monotonic_stack[monotonic_stack.size() - 1];
            }
            monotonic_stack.push_back(price);
        }
        return prices;
    }
};