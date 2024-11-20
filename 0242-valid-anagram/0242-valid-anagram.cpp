class Solution {
public:
    bool isAnagram(string s, string t) {
        int alpha[26]{};
        if (s.size() != t.size()) return false;
        for (auto c: s)
            ++alpha[c - 'a'];
        for (auto c: t)
            --alpha[c - 'a'];
        for (auto i: alpha)
            if (i != 0) return false;
        return true;
    }
};