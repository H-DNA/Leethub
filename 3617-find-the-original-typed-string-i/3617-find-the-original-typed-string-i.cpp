class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        int cur_count = 1;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i] != word[i - 1]) {
                res += cur_count - 1;
                cur_count = 1;
            } else {
                cur_count += 1;
            }
        }
        res += cur_count - 1;
        return res;
    }
};