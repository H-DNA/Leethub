class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alpha[26]{};
        for (auto c: magazine)
            ++alpha[c - 'a'];
        for (auto c: ransomNote) {
            --alpha[c - 'a'];
            if (alpha[c - 'a'] < 0) return false;
        }
        return true;
    }
};