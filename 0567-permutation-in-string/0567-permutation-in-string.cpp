class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::vector<unsigned long long> alpha(26);
        for (auto c: s1)
            ++alpha[c - 'a'];
        int start = 0;
        for (int i = 0; i < s2.length(); ++i) {
            char c = s2[i];
            if (alpha[c - 'a'] > 0) {
                if (i - start + 1 == s1.length()) return true;
                --alpha[c - 'a'];
            } else {
                for (; alpha[c - 'a'] == 0; ++start) {
                    if (start == i) {
                        ++start;
                        break;
                    }
                    ++alpha[s2[start] - 'a'];
                }
                
                if (start <= i) --alpha[c - 'a'];

            }
        }
        return false;
    }
};