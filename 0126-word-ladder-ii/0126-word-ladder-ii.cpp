class Solution {
public:
    bool check(string& s1, string& s2) {
        bool b = false;
        for (int i = 0; i < s1.size(); ++i)
            if (s1[i] != s2[i]) {
                if (b) return false;
                b = true;
            }
        return true;
            
    }
    
    struct Node {
        int d;
        std::vector<int> pred;
    };
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        std::vector<Node> d(wordList.size(), {INT_MAX});
        std::queue<int> q;
        int end_id = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            if (end_id == -1 && endWord == wordList[i])
                end_id = i;
            if (check(beginWord, wordList[i])) {
                d[i].d = 1;
                d[i].pred.push_back(-1);
                q.push(i);
            }
        }
        if (end_id == -1) return {};
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j = 0; j < wordList.size(); ++j) {
                if (d[j].d >= d[i].d + 1 && check(wordList[i], wordList[j])) {
                    if (d[j].d > d[i].d + 1) q.push(j);
                    d[j].d = d[i].d + 1;
                    d[j].pred.push_back(i);
                }
            }
            if (i == end_id) break;
        }
        return buildSol(beginWord, wordList, d, end_id);

    }
    
    std::vector<std::vector<string>> buildSol(string& beginWord, std::vector<std::string>& wordList, std::vector<Node>& d, int i) {
        if (i == -1) return {std::vector<string>{beginWord}};
        std::vector<std::vector<string>> sol;
        for (auto pred: d[i].pred) {
            auto tmp = buildSol(beginWord, wordList, d, pred);
            sol.insert(sol.end(), tmp.begin(), tmp.end());
        }
        for (auto& subsol: sol)
            subsol.push_back(wordList[i]);
        return sol;
    }
};