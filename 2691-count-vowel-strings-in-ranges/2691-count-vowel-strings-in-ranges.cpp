class Solution {
public:
    inline static bool isVowel(char c) {
      switch (c) {
        case 'a':
        case 'e':
        case 'o':
        case 'i':
        case 'u':
          return true;
        default: return false;
      }
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
      std::vector<int> prefixes{};
      prefixes.reserve(words.size() + 1);
      prefixes.push_back(0);
      
      int count = 0;
      for (const string& word: words) {
        count += (Solution::isVowel(*word.begin()) && Solution::isVowel(*(word.end() - 1)));
        prefixes.push_back(count);
      }
      
      std::vector<int> answers{};
      answers.reserve(words.size());
      for (const vector<int>& q: queries) {
        const int start = q[0];
        const int end = q[1];
        answers.push_back(prefixes[end + 1] - prefixes[start]);
      }

      return answers;
    }
};