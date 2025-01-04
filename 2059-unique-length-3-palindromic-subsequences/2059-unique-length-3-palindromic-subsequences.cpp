#define ALPHA_COUNT 26

class Solution {
public:
  int countPalindromicSubsequence(string s) {
    bool alphas[ALPHA_COUNT][ALPHA_COUNT]{};
    long unsigned int starts[ALPHA_COUNT];
    long unsigned int ends[ALPHA_COUNT];
    for (char c = 0; c < ALPHA_COUNT; ++c) {
      starts[c] = -1;
      ends[c] = -1;
    }

    const long unsigned int len = s.length();
    for (long long int i = 0; i < len; ++i) {
      const long unsigned int id = s[i] - 'a';
      if (starts[id] == -1)
        starts[id] = i;
    }
    for (long long int i = len - 1; i >= 0; --i) {
      const long unsigned int id = s[i] - 'a';
      if (ends[id] == -1)
        ends[id] = i;
    }
    for (long unsigned int i = 0; i < len; ++i) {
      const long unsigned int id = s[i] - 'a';
      for (char c = 0; c < ALPHA_COUNT; ++c) {
        if (starts[c] != -1 && starts[c] < i && i < ends[c]) {
          alphas[c][id] = true;
        }
      }
    }

    long unsigned int res = 0;
    for (char i = 0; i < ALPHA_COUNT; ++i) {
      for (char j = 0; j < ALPHA_COUNT; ++j) {
      res += alphas[i][j];
      }
    }
    return res;
  }
};