class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<bool> alpha(256, false);
        int max_len = 0;
        int start = 0;
        int sum = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (!alpha[c]) {
                ++sum;
                alpha[c] = true;
            }
            else {
                max_len = max(max_len, sum);
                for (; alpha[c]; ++start) {
                    alpha[s[start]] = false;
                    --sum;
                }
                alpha[c] = true;
                ++sum;
            }
        }
        return max(max_len, sum);
    }
};