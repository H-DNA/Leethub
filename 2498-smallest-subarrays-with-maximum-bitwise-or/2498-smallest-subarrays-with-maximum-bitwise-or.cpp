class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        vector<int> last_seen(30, 0);

        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = 0; j < 30; ++j) {
                if (nums[i] & (1 << j)) {
                    last_seen[j] = i;
                }
                res[i] = max(res[i], last_seen[j] - i + 1);
            }
        }
        return res;
    }
};
