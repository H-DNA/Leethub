class Solution {
public:
    inline bool isSubString(const string& a, const string& b) {
      return a.find(b) != string::npos;
    }
    vector<string> stringMatching(vector<string>& words) {
      vector<string> res;
      const unsigned int len = words.size();
      for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
          if (i == j) continue;
          if (isSubString(words[j], words[i])) {
            res.push_back(words[i]);
            break;
          }
        }
      }
      return res;
    }
};