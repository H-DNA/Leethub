class Solution {
public:
    static long long minimumDifference(vector<int>& nums) {
        const long long n = nums.size() / 3;
        std::vector<long long> diffs(n + 1, 0);
        std::priority_queue<int, std::vector<int>, std::less<int>> heap_left(nums.begin(), nums.begin() + n);
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap_right(nums.begin() + 2 * n, nums.end());

        long long sum = std::accumulate(nums.begin(), nums.begin() + n, 0LL);
        diffs[0] += sum;
        for (int i = n; i < 2 * n; ++i) {
            heap_left.push(nums[i]);
            sum -= heap_left.top();
            sum += nums[i];
            heap_left.pop();
            diffs[i - n + 1] += sum;
        }

        sum = std::accumulate(nums.begin() + 2 * n, nums.end(), 0LL);
        diffs[n] -= sum;
        for (int i = 2 * n - 1; i >= n; --i) {
            heap_right.push(nums[i]);
            sum -= heap_right.top();
            sum += nums[i];
            heap_right.pop();
            diffs[i - n] -= sum;
        }

        return *std::min_element(diffs.begin(), diffs.end());
    }
};