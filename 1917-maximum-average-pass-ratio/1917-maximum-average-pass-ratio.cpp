#include <queue>

struct entry {
    int total;
    int passed;
};

auto get_rate_diff(entry e) -> double {
    return (e.passed + 1.0) / (e.total + 1.0) - (e.passed + 0.0) / (e.total + 0.0);
}

class Solution {
public:
    auto maxAverageRatio(vector<vector<int>>& classes, int extraStudents) -> double {
        priority_queue<entry, std::vector<entry>, decltype([](entry a, entry b) { return get_rate_diff(a) < get_rate_diff(b); })> entries;
        for (const auto& c: classes) {
            entry e {
                c[1],
                c[0],
            };
            entries.push(e);
        }
        for (int i = extraStudents; i > 0; --i) {
            const auto top = entries.top();
            entries.pop();
            entries.push(entry { top.total + 1, top.passed + 1 }); 
        }
        double max_rate = 0;
        while (!entries.empty()) {
            const auto top = entries.top();
            entries.pop();
            max_rate += (top.passed + 0.0) / (top.total + 0.0);
        }
        return max_rate / classes.size();
    }
};