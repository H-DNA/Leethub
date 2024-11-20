#include <algorithm>

struct Input {
    int startTime;
    int endTime;
    int profit;
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Input> input;
        const int len = startTime.size();
        for (int i = 0; i < len; ++i) {
            input.push_back({ startTime[i], endTime[i], profit[i] });
        }
        sort(input.begin(), input.end(), [](const Input& a, const Input& b) { return a.startTime < b.startTime; });

        vector<int> res(len, 0);
        res[len - 1] = input[len - 1].profit; 
        for (int i = len - 2; i >= 0; --i) {
            const int end = input[i].endTime;
            
            int left_id = i + 1;
            int right_id = len - 1;
            while (left_id <= right_id) {
                const int mid_id = (left_id + right_id) / 2;
                if (input[mid_id].startTime < end) {
                    left_id = mid_id + 1;
                } else {
                    right_id = mid_id - 1;
                }
            }

            if (left_id >= len) {
                res[i] = input[i].profit;
            } else {
                res[i] = input[i].profit + res[left_id];
            }

            res[i] = max(res[i], res[i + 1]);
        }

        return res[0];
    }
};