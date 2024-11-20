class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        recur(res, s, 0);
        return res;
    }
    
    void recur(vector<string>& res, string& s, int l) {
        if (l >= s.size()) {
            res.push_back(s);
            return;
        }
        recur(res, s, l + 1);
        if ('a' <= s[l] && s[l] <= 'z') {
            s[l] = toupper(s[l]);
            recur(res, s, l + 1);
        } else if ('A' <= s[l] && s[l] <= 'Z') {
            s[l] = tolower(s[l]);
            recur(res, s, l + 1);
        }
    }
};