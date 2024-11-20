#include <queue>
#include <algorithm>

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        std::priority_queue<int> profitQueue{};
        vector<std::pair<int, int>> pairs{};
        for (int i = 0; i < profits.size(); ++i) {
            pairs.push_back({ profits[i], capital[i] });
        }
        std::sort(pairs.begin(), pairs.end(), [](auto p1, auto p2) { return p1.second > p2.second; });
        int curcap = w;
        while (k > 0 && pairs.size() > 0) {
            for (std::pair<int, int> pair = pairs.back(); pairs.size() > 0 && pair.second <= curcap; ) {
                profitQueue.push(pair.first);
                pairs.pop_back();
                if (pairs.size() > 0) {
                    pair = pairs.back();
                }
            }
            --k;
            if (profitQueue.empty()) {
                return curcap;
            }
            curcap += profitQueue.top();
            profitQueue.pop();
        }
        while (k > 0 && !profitQueue.empty()) {
            --k;
            curcap += profitQueue.top();
            profitQueue.pop();
        }
        return curcap;
    }
};