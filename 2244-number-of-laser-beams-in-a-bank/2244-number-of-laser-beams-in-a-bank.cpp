#include <algorithm>

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        int prev = 0;

        for (const auto& s: bank) {
            int cur = std::ranges::count(s, '1');
            if (cur > 0) {
                res += cur * prev;
                prev = cur;
            }
        }

        return res;
    }
};