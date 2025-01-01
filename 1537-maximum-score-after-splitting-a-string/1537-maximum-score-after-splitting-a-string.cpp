class Solution {
public:
    int maxScore(string s) {
      int max = 0;
      int cur = 0;
      for (char c: s) {
        cur += (c == '1') ? 1 : 0;
      }
      int len = s.length() - 1;
      for (int i = 0; i < len; ++i) {
        cur += (s[i] == '0') ? 1 : -1;
        max = std::max(cur, max);
      }

      return max;
    }
};