class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unsigned int occur1[26] = {};
        unsigned int occur2[26] = {};

        for (const auto c: word1) {
            ++occur1[c - 'a'];
        }

        for (const auto c: word2) {
            ++occur2[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (occur1[i] == 0 && occur2[i] != 0) {
                return false;
            }
            if (occur2[i] == 0 && occur1[i] != 0) {
                return false;
            }
        }

        vector<unsigned int> oc1, oc2;
        for (int i = 0; i < 26; ++i) {
            if (occur1[i] != 0) oc1.push_back(occur1[i]);
            if (occur2[i] != 0) oc2.push_back(occur2[i]);
        }

        sort(oc1.begin(), oc1.end());
        sort(oc2.begin(), oc2.end());

        for (int i = 0; i < oc1.size(); ++i) {
            if (oc1[i] != oc2[i]) {
                return false;
            }
        }

        return true;
    }
};