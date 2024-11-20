class Solution {
public:
    void reverse(string&s, int left, int right) {
      const int lr = left + right;
      const int mid = (lr + 1) >> 1;
      for (int i = left; i < mid; ++i) {
        int tmp = s[i];
        s[i] = s[lr - i];
        s[lr - i] = tmp;
      }
    }
    string reverseWords(string s) {
      int left = 0;
      const int len = s.length();
      for (int i = 0; i <= len; ++i) {
        if (i == len or s[i] == ' ') {
          reverse(s, left, i - 1);
          left = i + 1;
        }
      }
      return s;
    }
};