class Solution {
public:
    int firstUniqChar(string s) {
    std::vector<int> c_id(26, INT_MAX);
    std::vector<bool> no(s.size());
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i] - 'a';
        if (c_id[c] == INT_MAX)
            c_id[c] = i;
        else {
            no[i] = true;
            no[c_id[c]] = true;
        }
    }
    
        for (int i = 0; i < no.size(); ++i)
            if (!no[i]) return i;
        return -1;
    }
};