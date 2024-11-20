class Solution {
public:
    vector<int> partitionLabels(string s) {
      constexpr int alphabet_length = 26;
      std::array<int, alphabet_length> alphabet;
      for (int i = 0; i < s.size(); ++i) alphabet[s[i] - 'a'] = i;
      std::vector<int> res;
      int end_at = 0;
      int last_end = 0;
      for (int i = 0; i < s.size();) {
        while (i <= end_at) {
          if (end_at < alphabet[s[i] - 'a']) end_at = alphabet[s[i] - 'a'];
          ++i;
        }
        res.push_back(end_at - last_end + 1);
        last_end = end_at = i;
      }
      return res;
    }
};